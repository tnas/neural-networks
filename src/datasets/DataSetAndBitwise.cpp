#include "../../include/datasets/DataSetAndBitwise.h"

void DataSetAndBitwise::buildDataMatrix()
{
    this->dataMatrix[0][0] = 1;
    this->dataMatrix[0][1] = 1;
    this->dataMatrix[1][0] = 1;
    this->dataMatrix[1][1] = -1;
    this->dataMatrix[2][0] = -1;
    this->dataMatrix[2][1] = 1;
    this->dataMatrix[3][0] = -1;
    this->dataMatrix[3][1] = -1;
}

void DataSetAndBitwise::defineDesiredOutput()
{
    this->desiredOutput[0] = 1;
    this->desiredOutput[1] = -1;
    this->desiredOutput[2] = -1;
    this->desiredOutput[3] = -1;
}

