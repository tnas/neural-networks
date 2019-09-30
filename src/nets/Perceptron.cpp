#include "../../include/nets/Perceptron.h"
#include <iostream>

void Perceptron::run(const DataSet* dataSet)
{
    float output, result, error;
    unsigned int iteration, errorCounter, iterationHits;
    this->dataSet = dataSet;
    iteration = error = 1;

    this->weights = new float[this->inputDimension];
    this->pocketWeights = new float[this->inputDimension];
    for (unsigned int i = 0; i < this->inputDimension; ++i)
        this->weights[i] = this->pocketWeights[i] = 0;
    this->pocketHits = 0;

    do
    {
        Log log;
        log.setIteration(iteration);
        errorCounter = 0;

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
                ++errorCounter;
            }

            // Tracing
            log.addTrace(Trace(
                this->getVector(this->inputDimension, dataSet->getDataMatrix()[sample]),
                this->getVector(this->inputDimension, this->weights),
                this->bias, result, output, dataSet->getDesiredOutput()[sample]));
        }

        error = (float) errorCounter;
        log.setError(error);
        this->addLog(log);

        iterationHits = this->evaluateIterationHits();

        if (iterationHits > this->pocketHits)
        {
            for (unsigned int i = 0; i < this->inputDimension; ++i)
                this->pocketWeights[i] = this->weights[i];
        }

        ++iteration;

    } while (error > this->thresholdError && iteration <= this->maxIterations);

    for (unsigned int i = 0; i < this->inputDimension; ++i)
        this->weights[i] = this->pocketWeights[i];

    free(this->pocketWeights);
}


