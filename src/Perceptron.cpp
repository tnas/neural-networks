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


int Perceptron::applyActivationFunction(float result)
{
    if (result > this->indefinitionRate)
    {
        return 1;
    }
    else if (result < -this->indefinitionRate)
    {
        return -1;
    }
    else {
        return 0;
    }
}



void Perceptron::run(const DataSet* dataSet)
{
    this->inputDimension = dataSet->getInputDimension();
    this->initializeWeights();

    float result, error;
    int output, countError;
    int iterations = 0;
    vector<float> currWeights;
    error = 1;

    while (error > this->thresholdError && iterations < this->maxIterations)
    {
        countError = 0;

        for (int sample = 0; sample < dataSet->getNumberOfSamples(); sample++)
        {
            result = this->bias + dotProduct(dataSet->getDataMatrix()[sample],
                                             this->weights, this->inputDimension);

            output = this->applyActivationFunction(result);

            // Updating weights and bias
            if (output != dataSet->getDesiredOutput()[sample])
            {
                for (int i = 0; i < this->inputDimension; ++i)
                {
                    this->weights[i] += this->learningRate * dataSet->getDesiredOutput()[sample] *
                        dataSet->getDataMatrix()[sample][i];
                }
                this->bias += this->learningRate * dataSet->getDesiredOutput()[sample];
                ++countError;
            }

            for (int i = 0; i < this->inputDimension; currWeights.push_back(this->weights[i++]));

            tracer.push_back(Trace(iterations, this->inputDimension, currWeights, this->bias, result));

            currWeights.clear();
        }

        error = (float) countError/dataSet->getNumberOfSamples();

        ++iterations;
    }
}


void Perceptron::test(const DataSet* dataSet)
{
    float result;
    int output, error;

    error = 0;

    for (int sample = 0; sample < dataSet->getNumberOfSamples(); sample++)
    {
        result = this->bias + dotProduct(dataSet->getDataMatrix()[sample],
            this->weights, this->inputDimension);

        output = this->applyActivationFunction(result);

        if (output != dataSet->getDesiredOutput()[sample]) ++error;

        for (int i = 0; i < this->inputDimension; ++i)
        {
            cout << "x" << i << " = " << dataSet->getDataMatrix()[sample][i] << " ";
        }

        cout << "d = " << dataSet->getDesiredOutput()[sample] << " "
             << "y = " << output << endl;
    }

    cout << "Error: " << error << "/" << dataSet->getNumberOfSamples() << endl;
}


void Perceptron::printTrace()
{
    for (Trace trace : tracer)
        trace.toString();
}

