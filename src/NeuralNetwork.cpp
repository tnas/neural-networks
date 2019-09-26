#include "NeuralNetwork.h"

using namespace std;

NeuralNetwork::~NeuralNetwork()
{
    if (this->weights != nullptr)
        delete(this->weights);
}


float NeuralNetwork::dotProduct(float* sample, float* weights, int dim)
{
    float sum = 0;
    for (int i = 0; i < dim; ++i)
    {
        sum += sample[i] * weights[i];
    }

    return sum;
}


void NeuralNetwork::test(const DataSet* dataSet)
{
    float result;
    int output, error;

    error = 0;

    for (int sample = 0; sample < dataSet->getNumberOfSamples(); sample++)
    {
        result = this->bias + this->dotProduct(dataSet->getDataMatrix()[sample],
            this->weights, this->inputDimension);

        output = this->applyActivationFunction(result);

        if (output != dataSet->getDesiredOutput()[sample]) ++error;

        for (unsigned int i = 0; i < this->inputDimension; ++i)
        {
            cout << "x" << i << " = " << dataSet->getDataMatrix()[sample][i] << " ";
        }

        cout << "d = " << dataSet->getDesiredOutput()[sample] << " "
             << "y = " << output << endl;
    }

    cout << "Error: " << error << "/" << dataSet->getNumberOfSamples() << endl;
}


void NeuralNetwork::printTrace()
{
    for (Trace trace : tracer)
        trace.toString();
}

