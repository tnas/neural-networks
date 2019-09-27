#include "../../include/nets/Adaline.h"


void Adaline::run(const DataSet* dataSet)
{
    float result, error;
    this->dataSet = dataSet;
    unsigned int iteration = 1;
    error = 1;

    do
    {
        Log log;
        log.setIteration(iteration);

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

            // Tracing
            log.addTrace(Trace(
                this->getVector(this->inputDimension, dataSet->getDataMatrix()[sample]),
                this->getVector(this->inputDimension, this->weights),
                this->bias, result, this->applyActivationFunction(result),
                dataSet->getDesiredOutput()[sample]));
        }

        error = this->getCurrentQuadraticError();
        log.setError(error);

        this->learningRate *= Adaline::LEARNING_DECREASE;
        ++iteration;

        this->addLog(log);
    } while (error > this->thresholdError && iteration < this->maxIterations && this->evaluateIteration() != 0);
}
