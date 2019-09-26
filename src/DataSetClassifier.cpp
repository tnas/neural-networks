#include "../include/DataSetClassifier.h"

void DataSetClassifier::buildDataMatrix()
{
    this->dataMatrix[0][0] = 0;
    this->dataMatrix[0][1] = 1;
    this->dataMatrix[1][0] = 0;
    this->dataMatrix[1][1] = 2;
    this->dataMatrix[2][0] = 1;
    this->dataMatrix[2][1] = 1;
    this->dataMatrix[3][0] = 1;
    this->dataMatrix[3][1] = 2;
    this->dataMatrix[4][0] = 1;
    this->dataMatrix[4][1] = 3;
    this->dataMatrix[5][0] = 2;
    this->dataMatrix[5][1] = 2;
    this->dataMatrix[6][0] = 2;
    this->dataMatrix[6][1] = 3;
    this->dataMatrix[7][0] = 3;
    this->dataMatrix[7][1] = 2;
    this->dataMatrix[8][0] = 4;
    this->dataMatrix[8][1] = 1;
    this->dataMatrix[9][0] = 4;
    this->dataMatrix[9][1] = 3;
    this->dataMatrix[10][0] = 0;
    this->dataMatrix[10][1] = 3;

    this->dataMatrix[11][0] = 2;
    this->dataMatrix[11][1] = 0;
    this->dataMatrix[12][0] = 2;
    this->dataMatrix[12][1] = 1;
    this->dataMatrix[13][0] = 3;
    this->dataMatrix[13][1] = 0;
    this->dataMatrix[14][0] = 3;
    this->dataMatrix[14][1] = 1;
    this->dataMatrix[15][0] = 3;
    this->dataMatrix[15][1] = 3;
    this->dataMatrix[16][0] = 4;
    this->dataMatrix[16][1] = 0;
    this->dataMatrix[17][0] = 4;
    this->dataMatrix[17][1] = 2;
    this->dataMatrix[18][0] = 5;
    this->dataMatrix[18][1] = 0;
    this->dataMatrix[19][0] = 5;
    this->dataMatrix[19][1] = 1;
    this->dataMatrix[20][0] = 5;
    this->dataMatrix[20][1] = 2;
    this->dataMatrix[21][0] = 5;
    this->dataMatrix[21][1] = 3;
}

void DataSetClassifier::defineDesiredOutput()
{
    this->desiredOutput[0] = 1;
    this->desiredOutput[1] = 1;
    this->desiredOutput[2] = 1;
    this->desiredOutput[3] = 1;
    this->desiredOutput[4] = 1;
    this->desiredOutput[5] = 1;
    this->desiredOutput[6] = 1;
    this->desiredOutput[7] = 1;
    this->desiredOutput[8] = 1;
    this->desiredOutput[9] = 1;
    this->desiredOutput[10] = 1;
    this->desiredOutput[11] = 1;

    this->desiredOutput[12] = -1;
    this->desiredOutput[13] = -1;
    this->desiredOutput[14] = -1;
    this->desiredOutput[15] = -1;
    this->desiredOutput[16] = -1;
    this->desiredOutput[17] = -1;
    this->desiredOutput[18] = -1;
    this->desiredOutput[19] = -1;
    this->desiredOutput[20] = -1;
    this->desiredOutput[21] = -1;
    this->desiredOutput[22] = -1;
}


