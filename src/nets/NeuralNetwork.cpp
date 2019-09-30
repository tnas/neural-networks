#include "../../include/nets/NeuralNetwork.h"

using namespace std;

NeuralNetwork::~NeuralNetwork()
{
    if (this->weights != nullptr)
        delete(this->weights);
}

float NeuralNetwork::getBinaryFunction(float result)
{
    return result >= 0 ? 1 : -1;
}

float NeuralNetwork::getLimiarFunction(float result)
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

float NeuralNetwork::getHTangentFunction(float result)
{
    return tanh(result);
}

float NeuralNetwork::applyActivationFunction(float result)
{
    switch(this->actFunction)
    {
    case LIMIAR :
        return this->getLimiarFunction(result);
    case TANH :
        return this->getHTangentFunction(result);
    case BINARY :
        return this->getBinaryFunction(result);
    default :
        return this->getBinaryFunction(result);
    }
}

float NeuralNetwork::getCurrentQuadraticError()
{
    float result, error;
    error = 0;

    for (int sample = 0; sample < this->dataSet->getNumberOfSamples(); sample++)
    {
        result = this->bias + this->dotProduct(dataSet->getDataMatrix()[sample],
            this->weights, this->inputDimension);

        error += pow((dataSet->getDesiredOutput()[sample] - result), 2.0);
    }

    return error / 2;
}

unsigned int NeuralNetwork::evaluateIterationHits()
{
    float result, output;
    int hitsCounter;

    hitsCounter = 0;

    for (int sample = 0; sample < this->dataSet->getNumberOfSamples(); sample++)
    {
        result = this->bias + this->dotProduct(dataSet->getDataMatrix()[sample],
            this->weights, this->inputDimension);

        output = this->applyActivationFunction(result);

        this->logger.back().addIterationStatus(Trace(
                this->getVector(this->inputDimension, dataSet->getDataMatrix()[sample]),
                this->getVector(this->inputDimension, this->weights),
                this->bias, result, output, dataSet->getDesiredOutput()[sample]));

        if (output == dataSet->getDesiredOutput()[sample]) ++hitsCounter;
    }

    return hitsCounter;
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
    float output, result;
    int error;

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
    for (unsigned int i = 0; i < this->inputDimension; ++i)
    {
        cout << "w" << i << " = " << this->weights[i] << " ";
    }
    cout << endl;
}


vector<float> NeuralNetwork::getVector(const unsigned int dim, const float* values)
{
    vector<float> currVector;
    for (unsigned int i = 0; i < dim; currVector.push_back(values[i++]));
    return currVector;
}


void NeuralNetwork::setIndefinitionRate(float indefinitionRate)
{
    this->indefinitionRate = indefinitionRate;
}


void NeuralNetwork::addLog(Log log)
{
    this->logger.push_back(log);
}

void NeuralNetwork::printTrace()
{
    for (Log log : this->logger)
        log.print();
}

