#include "../../include/datasets/DataSetABPattern.h"

void DataSetABPattern::buildDataMatrix()
{
    this->dataMatrix[0][0] = 0.75;
    this->dataMatrix[0][1] = 0.75;
    this->dataMatrix[1][0] = 0.75;
    this->dataMatrix[1][1] = 0.25;
    this->dataMatrix[2][0] = 0.25;
    this->dataMatrix[2][1] = 0.75;
    this->dataMatrix[3][0] = 0.25;
    this->dataMatrix[3][1] = 0.25;
}

/**
 * A = 1; B = -1
 */
void DataSetABPattern::defineDesiredOutput()
{
    this->desiredOutput[0] = 1;
    this->desiredOutput[1] = -1;
    this->desiredOutput[2] = -1;
    this->desiredOutput[3] = 1;
}

