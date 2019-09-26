#include "../include/Perceptron.h"
#include <iostream>

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
    float result, error;
    int output, countError;
    unsigned int iterations = 0;
    vector<float> currWeights;
    error = 1;

    this->weights = new float[this->inputDimension];
    for (unsigned int i = 0; i < this->inputDimension; this->weights[i++] = 0);

    while (error > this->thresholdError && iterations < this->maxIterations)
    {
        countError = 0;

        for (int sample = 0; sample < dataSet->getNumberOfSamples(); sample++)
        {
            result = this->bias + this->dotProduct(dataSet->getDataMatrix()[sample],
                this->weights, this->inputDimension);

            output = this->applyActivationFunction(result);

            // Updating weights and bias
            if (output != dataSet->getDesiredOutput()[sample])
            {
                for (unsigned int i = 0; i < this->inputDimension; ++i)
                {
                    this->weights[i] += this->learningRate * dataSet->getDesiredOutput()[sample] *
                        dataSet->getDataMatrix()[sample][i];
                }
                this->bias += this->learningRate * dataSet->getDesiredOutput()[sample];
                ++countError;
            }

            for (unsigned int i = 0; i < this->inputDimension; currWeights.push_back(this->weights[i++]));
            this->tracer.push_back(Trace(iterations, this->inputDimension, currWeights, this->bias, result));
            currWeights.clear();
        }

        error = (float) countError/dataSet->getNumberOfSamples();

        ++iterations;
    }
}


