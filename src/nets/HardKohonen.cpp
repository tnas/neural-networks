#include "HardKohonen.h"


void HardKohonen::run(const DataSet* dataSet)
{
    unsigned int iteration = 1;
    float* distance = new float[dataSet->getNumberOfNeurons()];

    do
    {
        Log log;
        log.setIteration(iteration);

        for (int sample = 0; sample < dataSet->getNumberOfSamples(); ++sample)
        {
            unsigned int winnerNeuron = 0;
            float minDistance = numeric_limits<float>::max();

            for (unsigned int neuron = 0; neuron < dataSet->getNumberOfNeurons(); ++neuron)
            {
                distance[neuron] = this->euclideanDistance(dataSet->getDataMatrix()[sample],
                    dataSet->getWeightMatrix()[neuron], dataSet->getInputDimension());

                if (distance[neuron] < minDistance)
                {
                    minDistance = distance[neuron];
                    winnerNeuron = neuron;
                }
            }

            // Updating winner neuron
            for (int coord = 0; coord < dataSet->getInputDimension(); ++coord)
            {
                dataSet->getWeightMatrix()[winnerNeuron][coord] += this->learningRate *
                    (dataSet->getDataMatrix()[sample][coord] - dataSet->getWeightMatrix()[winnerNeuron][coord]);
            }
        }

        this->addLog(log);

        ++iteration;

    } while(iteration <= this->maxIterations);

    free(distance);
}
