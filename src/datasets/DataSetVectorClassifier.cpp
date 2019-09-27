#include "../../include/datasets/DataSetVectorClassifier.h"

void DataSetVectorClassifier::buildDataMatrix()
{
    this->dataMatrix[0][0] = 1;
    this->dataMatrix[0][1] = 1;
    this->dataMatrix[0][2] = 1;
    this->dataMatrix[0][3] = 1;

    this->dataMatrix[1][0] = -1;
    this->dataMatrix[1][1] = -1;
    this->dataMatrix[1][2] = -1;
    this->dataMatrix[1][3] = -1;

    this->dataMatrix[2][0] = 1;
    this->dataMatrix[2][1] = 1;
    this->dataMatrix[2][2] = -1;
    this->dataMatrix[2][3] = -1;

    this->dataMatrix[3][0] = 1;
    this->dataMatrix[3][1] = -1;
    this->dataMatrix[3][2] = -1;
    this->dataMatrix[3][3] = 1;

    this->dataMatrix[4][0] = -1;
    this->dataMatrix[4][1] = -1;
    this->dataMatrix[4][2] = 1;
    this->dataMatrix[4][3] = 1;
}

void DataSetVectorClassifier::defineDesiredOutput()
{
    this->desiredOutput[0] = 0.9;
    this->desiredOutput[1] = 0.8;
    this->desiredOutput[2] = -0.7;
    this->desiredOutput[3] = -0.8;
    this->desiredOutput[3] = -0.7;
}
