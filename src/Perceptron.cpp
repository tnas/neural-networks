#include "../include/Perceptron.h"
#include "../include/Trace.h"
#include <iostream>
#include <vector>

using namespace std;

static vector<Trace> tracer;

Perceptron::~Perceptron()
{
    if (this->weights != nullptr)
        delete(this->weights);
}

float dotProduct(float* sample, float* weights, int dim)
{
    float sum = 0;
    for (int i = 0; i < dim; ++i)
    {
        sum += sample[i] * weights[i];
    }

    return sum;
}


void Perceptron::initializeWeights()
{
    if (this->weights != nullptr)
        delete(this->weights);

    this->weights = new float[this->inputDimension];
    for (int i = 0; i < this->inputDimension; this->weights[i++] = 0);
}


void Perceptron::run(const DataSet* dataSet)
{
    this->inputDimension = dataSet->getInputDimension();
    this->initializeWeights();

    float currBias = this->bias;
    float result, error;
    int output, countError;
    this->iterations = 1;
    vector<float> currWeights;
    error = 1;

    while (error > this->thresholdError)
    {
        countError = 0;

        for (int sample = 0; sample < dataSet->getNumberOfSamples(); sample++)
        {
            result = currBias + dotProduct(dataSet->getDataMatrix()[sample],
                                             this->weights, this->inputDimension);

            if (result > this->indefinitionRate)
            {
                output = 1;
            }
            else if (result < -this->indefinitionRate)
            {
                output = -1;
            }
            else {
                output = 0;
            }

            // Updating weights and bias
            if (output != dataSet->getDesiredOutput()[sample])
            {
                for (int i = 0; i < this->inputDimension; ++i)
                {
                    this->weights[i] += this->learningRate * dataSet->getDesiredOutput()[sample] *
                        dataSet->getDataMatrix()[sample][i];
                }
                currBias += this->learningRate * dataSet->getDesiredOutput()[sample];
                ++countError;
            }

            for (int i = 0; i < this->inputDimension; currWeights.push_back(this->weights[i++]));

            tracer.push_back(Trace(this->iterations, this->inputDimension,
                currWeights, currBias, result));

            currWeights.clear();
        }

        error = (float) countError/dataSet->getNumberOfSamples();

        ++this->iterations;
    }
}


void Perceptron::printTrace()
{
    for (Trace trace : tracer)
        trace.toString();
}

