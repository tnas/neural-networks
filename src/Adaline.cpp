#include "../include/Adaline.h"


int Adaline::applyActivationFunction(float result)
{
    return result >= 0 ? 1 : -1;
}

float Adaline::calculateCurrentError()
{
    float result;
    int output, countError;

    countError = 0;

    for (int sample = 0; sample < this->dataSet->getNumberOfSamples(); sample++)
    {
        result = this->bias + this->dotProduct(dataSet->getDataMatrix()[sample],
            this->weights, this->inputDimension);

        output = this->applyActivationFunction(result);

        if (output != dataSet->getDesiredOutput()[sample]) ++countError;
    }

    return (float) countError/dataSet->getNumberOfSamples();
}

void Adaline::run(const DataSet* dataSet)
{
    float result, error;
    vector<float> currWeights;

    this->dataSet = dataSet;
    unsigned int iterations = 0;
    error = 1;

    while (error > this->thresholdError && iterations < this->maxIterations)
    {
        for (int sample = 0; sample < dataSet->getNumberOfSamples(); sample++)
        {
            result = this->bias + this->dotProduct(dataSet->getDataMatrix()[sample],
                this->weights, this->inputDimension);

            float deltaBias = this->learningRate *
                    (dataSet->getDesiredOutput()[sample] - result);

            // Updating weights and bias
            for (unsigned int i = 0; i < this->inputDimension; ++i)
            {
                this->weights[i] +=  deltaBias * dataSet->getDataMatrix()[sample][i];
            }

            this->bias += deltaBias;

            // Execution tracing
            for (unsigned int i = 0; i < this->inputDimension; currWeights.push_back(this->weights[i++]));
            this->tracer.push_back(Trace(iterations, this->inputDimension, currWeights, this->bias, result));
            currWeights.clear();
        }

        error = this->calculateCurrentError();
        this->learningRate *= Adaline::LEARNING_DECREASE;
        ++iterations;
    }
}
