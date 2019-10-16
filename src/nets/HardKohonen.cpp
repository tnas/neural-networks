#include "../../include/nets/HardKohonen.h"


void HardKohonen::run(const DataSet* dataSet)
{
    unsigned int iteration = 1;
    float* distance = new float[dataSet->getNumberOfNeurons()];

    do
    {
        Log log;
        log.setIteration(iteration);
        log.setLearningRate(this->learningRate);
        log.setRadius(this->radius);

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

            // Generating snapshot of weights and distance
            vector<vector<float>> currWeights;
            vector<float> currDistance;
            for (unsigned int n = 0; n < dataSet->getNumberOfNeurons(); ++n)
            {
                vector<float> neuron;
                for (int coord = 0; coord < dataSet->getInputDimension(); ++coord)
                {
                    neuron.push_back(dataSet->getWeightMatrix()[n][coord]);
                }
                currWeights.push_back(neuron);
                currDistance.push_back(distance[n]);
            }

            // Tracing the iteration
            log.addKohonenTrace(KohonenTrace(currDistance, winnerNeuron, dataSet->getNumberOfNeurons(),
                     currWeights, dataSet->getInputDimension(), dataSet->getDataMatrix()[sample]));
        }

        this->addLog(log);

        ++iteration;
        this->learningRate *= this->learningDecrease;
        this->radius *= this->radiusDecreaseRate;

    } while(iteration <= this->maxIterations && this->learningRate > 0 && this->radius > 0);

    free(distance);
}
