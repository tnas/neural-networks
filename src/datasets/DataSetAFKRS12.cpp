#include "DataSetAFKRS12.h"


void DataSetAFKRS12::buildDataMatrix()
{
    unsigned int row = 0;

    // Cluster: A
    this->dataMatrix[row][0] = 1;
    this->dataMatrix[row][1] = 0;
    this->dataMatrix[row][2] = 0;
    this->dataMatrix[row][3] = 0;
    this->dataMatrix[row][4] = 0;
    ++row;

    // Cluster: F
    this->dataMatrix[row][0] = 3;
    this->dataMatrix[row][1] = 1;
    this->dataMatrix[row][2] = 0;
    this->dataMatrix[row][3] = 0;
    this->dataMatrix[row][4] = 0;
    ++row;

    // Cluster: K, R
    this->dataMatrix[row][0] = 3;
    this->dataMatrix[row][1] = 3;
    this->dataMatrix[row][2] = 1;
    this->dataMatrix[row][3] = 0;
    this->dataMatrix[row][4] = 0;
    ++row;
    this->dataMatrix[row][0] = 3;
    this->dataMatrix[row][1] = 3;
    this->dataMatrix[row][2] = 8;
    this->dataMatrix[row][3] = 0;
    this->dataMatrix[row][4] = 0;
    ++row;

    // Cluster: S
    this->dataMatrix[row][0] = 3;
    this->dataMatrix[row][1] = 3;
    this->dataMatrix[row][2] = 3;
    this->dataMatrix[row][3] = 1;
    this->dataMatrix[row][4] = 0;
    ++row;

    // Cluster: 1, 2
    this->dataMatrix[row][0] = 3;
    this->dataMatrix[row][1] = 3;
    this->dataMatrix[row][2] = 6;
    this->dataMatrix[row][3] = 2;
    this->dataMatrix[row][4] = 1;
    ++row;
    this->dataMatrix[row][0] = 3;
    this->dataMatrix[row][1] = 3;
    this->dataMatrix[row][2] = 6;
    this->dataMatrix[row][3] = 2;
    this->dataMatrix[row][4] = 2;
}

void DataSetAFKRS12::defineDesiredOutput()
{

}

void DataSetAFKRS12::defineWeightMatrix()
{
    this->prepareWeightMatrix(NUMBER_OF_NEURONS);
    unsigned int row = 0;

    this->weightMatrix[row][0] = 0.1;
    this->weightMatrix[row][1] = 0.2;
    this->weightMatrix[row][2] = 0.3;
    this->weightMatrix[row][3] = 0.4;
    this->weightMatrix[row][4] = 0.5;
    ++row;

    this->weightMatrix[row][0] = 0.5;
    this->weightMatrix[row][1] = 0.6;
    this->weightMatrix[row][2] = 0.3;
    this->weightMatrix[row][3] = 0.2;
    this->weightMatrix[row][4] = 0.1;
    ++row;

    this->weightMatrix[row][0] = 0.3;
    this->weightMatrix[row][1] = 0.1;
    this->weightMatrix[row][2] = 0.5;
    this->weightMatrix[row][3] = 0.2;
    this->weightMatrix[row][4] = 0.4;
    ++row;

    this->weightMatrix[row][0] = 0.2;
    this->weightMatrix[row][1] = 0.5;
    this->weightMatrix[row][2] = 0.3;
    this->weightMatrix[row][3] = 0.4;
    this->weightMatrix[row][4] = 0.1;
    ++row;

    this->weightMatrix[row][0] = 0.1;
    this->weightMatrix[row][1] = 0.4;
    this->weightMatrix[row][2] = 0.3;
    this->weightMatrix[row][3] = 0.5;
    this->weightMatrix[row][4] = 0.2;
    ++row;

    this->weightMatrix[row][0] = 0.5;
    this->weightMatrix[row][1] = 0.3;
    this->weightMatrix[row][2] = 0.2;
    this->weightMatrix[row][3] = 0.1;
    this->weightMatrix[row][4] = 0.4;
}


