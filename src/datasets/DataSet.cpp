#include "../../include/datasets/DataSet.h"
#include <iostream>

using namespace std;

DataSet::DataSet(int numberOfSamples, int inputDimension)
{
    this->numberOfSamples = numberOfSamples;
    this->inputDimension = inputDimension;

    this->desiredOutput = new float[this->numberOfSamples];

    this->dataMatrix = new float*[this->numberOfSamples];
    for (int i = 0; i < this->numberOfSamples; i++)
    {
        this->dataMatrix[i] = new float[this->inputDimension];
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



