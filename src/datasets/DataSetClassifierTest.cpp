#include "../../include/datasets/DataSetClassifierTest.h"


void DataSetClassifierTest::buildDataMatrix()
{
    this->dataMatrix[0][0] = 0;
    this->dataMatrix[0][1] = 0;
    this->dataMatrix[1][0] = 1;
    this->dataMatrix[1][1] = 0;
    this->dataMatrix[2][0] = 4.5;
    this->dataMatrix[2][1] = 0.5;
    this->dataMatrix[3][0] = 3.5;
    this->dataMatrix[3][1] = 1.5;
    this->dataMatrix[4][0] = 4;
    this->dataMatrix[4][1] = 2.5;
    this->dataMatrix[5][0] = 1.5;
    this->dataMatrix[5][1] = 1.5;
    this->dataMatrix[6][0] = 2;
    this->dataMatrix[6][1] = 0.5;
    this->dataMatrix[7][0] = 2.5;
    this->dataMatrix[7][1] = 2.5;
}

void DataSetClassifierTest::defineDesiredOutput()
{
    this->desiredOutput[0] = 1;
    this->desiredOutput[1] = -1;
    this->desiredOutput[2] = -1;
    this->desiredOutput[3] = -1;
    this->desiredOutput[4] = 1;
    this->desiredOutput[5] = 1;
    this->desiredOutput[6] = -1;
    this->desiredOutput[7] = 1;
}
