#include "../../include/nets/Perceptron.h"

void Perceptron::run(const DataSet* dataSet)
{
    float output, result, error;
    unsigned int iteration;

    this->dataSet = dataSet;
    iteration = 1;
    this->weights = new float[this->inputDimension];
    this->pocketWeights = new float[this->inputDimension];
    for (unsigned int i = 0; i < this->inputDimension; ++i)
        this->weights[i] = this->pocketWeights[i] = 0;
    this->pocketError = dataSet->getNumberOfSamples();

    do
    {
        Log log;
        log.setIteration(iteration);

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
            }

            // Tracing
            log.addTrace(Trace(
                this->getVector(this->inputDimension, dataSet->getDataMatrix()[sample]),
                this->getVector(this->inputDimension, this->weights),
                this->bias, result, output, dataSet->getDesiredOutput()[sample]));
        }

        this->addLog(log);
        error = this->evaluateIteration();

        if (error < this->pocketError)
        {
            for (unsigned int i = 0; i < this->inputDimension; ++i)
                this->pocketWeights[i] = this->weights[i];
            this->pocketError = error;
        }

        ++iteration;

    } while (error > this->thresholdError && iteration <= this->maxIterations);

    for (unsigned int i = 0; i < this->inputDimension; ++i)
        this->weights[i] = this->pocketWeights[i];

    free(this->pocketWeights);
}


