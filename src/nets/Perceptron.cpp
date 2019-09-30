#include "../../include/nets/Perceptron.h"
#include <iostream>

void Perceptron::run(const DataSet* dataSet)
{
    float output, result, error;
    unsigned int countError, iteration;
    this->dataSet = dataSet;
    iteration = error = 1;

    this->weights = new float[this->inputDimension];
    for (unsigned int i = 0; i < this->inputDimension; this->weights[i++] = 0);

    do
    {
        Log log;
        log.setIteration(iteration);
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

            // Tracing
            log.addTrace(Trace(
                this->getVector(this->inputDimension, dataSet->getDataMatrix()[sample]),
                this->getVector(this->inputDimension, this->weights),
                this->bias, result, output, dataSet->getDesiredOutput()[sample]));
        }

        error = (float) countError/dataSet->getNumberOfSamples();
        log.setError(error);
        this->addLog(log);

        ++iteration;
    } while (this->evaluateIterationError() > this->thresholdError && iteration <= this->maxIterations);
}


