#include "../../include/nets/HardKohonen.h"

HardKohonen::~HardKohonen()
{
    if (this->distance != nullptr)
        delete(this->distance);
}


unsigned int HardKohonen::getWinnerNeuron(float* input, const DataSet* dataSet)
{
    unsigned int winnerNeuron = 0;
    float minDistance = numeric_limits<float>::max();

    for (unsigned int neuron = 0; neuron < dataSet->getNumberOfNeurons(); ++neuron)
    {
        this->distance[neuron] = this->euclideanDistance(input, dataSet->getWeightMatrix()[neuron],
            dataSet->getInputDimension());

        if (this->distance[neuron] < minDistance)
        {
            minDistance = this->distance[neuron];
            winnerNeuron = neuron;
        }
    }

    return winnerNeuron;
}


void HardKohonen::run(const DataSet* dataSet)
{
    unsigned int iteration = 1;
    this->distance = new float[dataSet->getNumberOfNeurons()];

    do
    {
        Log log;
        log.setIteration(iteration);
        log.setLearningRate(this->learningRate);
        log.setRadius(this->radius);

        for (int sample = 0; sample < dataSet->getNumberOfSamples(); ++sample)
        {
            unsigned int winnerNeuron = this->getWinnerNeuron(dataSet->getDataMatrix()[sample], dataSet);

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
                currDistance.push_back(this->distance[n]);
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
}


void HardKohonen::test(const DataSet* dataSet)
{
    float error = 0;
    unsigned int winNeuron;

    cout << endl << "Testing:" << endl;

    for (int test = 0; test < dataSet->getNumberOfTests(); ++test)
    {
        winNeuron = this->getWinnerNeuron(dataSet->getTestMatrix()[test], dataSet);
        error = this->getMediumQuadraticError(dataSet->getTestMatrix()[test],
                            dataSet->getWeightMatrix()[winNeuron], dataSet->getInputDimension());

        if (error <= this->thresholdError)
        {
            cout << "Test " << test << ": Success (Error = " << error << ", Win: " << winNeuron << ")" << endl;
        }
        else
        {
            cout << "Test " << test << ": Fail (Error = " << error << ", Win: " << winNeuron << ")" << endl;
        }
    }
}
