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

float NeuralNetwork::getMediumQuadraticError(float* input, float* base, unsigned int dimension)
{
    float error = 0;

    for (unsigned int pos = 0; pos < dimension; pos++)
    {
        error += pow((input[pos] - base[pos]), 2.0);
    }

    return error / dimension;
}

float NeuralNetwork::evaluateIteration()
{
    float result, output;
    unsigned int errorCounter;

    errorCounter = 0;

    for (int sample = 0; sample < this->dataSet->getNumberOfSamples(); sample++)
    {
        result = this->bias + this->dotProduct(dataSet->getDataMatrix()[sample],
            this->weights, this->inputDimension);

        output = this->applyActivationFunction(result);

        this->logger.back().addIterationStatus(Trace(
                this->getVector(this->inputDimension, dataSet->getDataMatrix()[sample]),
                this->getVector(this->inputDimension, this->weights),
                this->bias, result, output, dataSet->getDesiredOutput()[sample]));

        if (output != dataSet->getDesiredOutput()[sample]) ++errorCounter;
    }

    this->logger.back().setError(errorCounter);

    return errorCounter;
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


float NeuralNetwork::euclideanDistance(float* sample, float* weights, int dim)
{
    float sum = 0;
    for (int i = 0; i < dim; ++i)
    {
        sum += pow((sample[i] - weights[i]), 2.0);
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

