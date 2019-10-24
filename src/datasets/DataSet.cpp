#include "../../include/datasets/DataSet.h"
#include <iostream>

using namespace std;

DataSet::DataSet(int numberOfSamples, int numberOfTests, int inputDimension, unsigned int neurons)
{
    this->weightMatrix = nullptr;
    this->testMatrix = nullptr;
    this->numberOfSamples = numberOfSamples;
    this->numberOfTests = numberOfTests;
    this->inputDimension = inputDimension;
    this->numberOfNeurons = neurons;

    this->desiredOutput = new float[this->numberOfSamples];

    this->dataMatrix = new float*[this->numberOfSamples];
    for (int i = 0; i < this->numberOfSamples; i++)
    {
        this->dataMatrix[i] = new float[this->inputDimension];
    }

    if (this->numberOfNeurons > 0)
    {
        this->weightMatrix = new float*[this->numberOfNeurons];
        for (unsigned int i = 0; i < this->numberOfNeurons; i++)
        {
            this->weightMatrix[i] = new float[this->inputDimension];
        }
    }

    if (this->numberOfTests > 0)
    {
        this->testMatrix = new float*[this->numberOfTests];
        for (int i = 0; i < this->numberOfTests; i++)
        {
            this->testMatrix[i] = new float[this->inputDimension];
        }
    }
}

DataSet::~DataSet()
{
    delete(this->desiredOutput);

    for (int i = 0; i < this->numberOfSamples; i++)
    {
        delete(this->dataMatrix[i]);
    }

    delete(this->dataMatrix);

    if (this->weightMatrix != nullptr)
    {
        for (unsigned int i = 0; i < this->numberOfNeurons; i++)
        {
            delete(this->weightMatrix[i]);
        }

        delete(this->weightMatrix);
    }

    if (this->testMatrix != nullptr)
    {
        for (int i = 0; i < this->numberOfTests; i++)
        {
            delete(this->testMatrix[i]);
        }

        delete(this->testMatrix);
    }
}

void DataSet::printDesiredOutput()
{
    for (int pos = 0; pos < this->numberOfSamples; ++pos)
    {
        cout << this->desiredOutput[pos] << endl;
    }
}

void DataSet::printDataMatrix()
{
    for (int i = 0; i < this->numberOfSamples; i++)
    {
        for (int j = 0; j < this->inputDimension; j++)
        {
            cout << this->dataMatrix[i][j] << " ";
        }

        cout << endl;
    }
}

int DataSet::getInputDimension() const
{
    return this->inputDimension;
}

int DataSet::getNumberOfSamples() const
{
    return this->numberOfSamples;
}

float** DataSet::getDataMatrix() const
{
    return this->dataMatrix;
}

float* DataSet::getDesiredOutput() const
{
    return this->desiredOutput;
}

float** DataSet::getWeightMatrix() const
{
    return this->weightMatrix;
}

unsigned int DataSet::getNumberOfNeurons() const
{
    return this->numberOfNeurons;
}

float** DataSet::getTestMatrix() const
{
    return this->testMatrix;
}

int DataSet::getNumberOfTests() const
{
    return this->numberOfTests;
}

