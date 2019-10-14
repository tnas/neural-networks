#ifndef DATASETAFKRS12_H
#define DATASETAFKRS12_H

#include "DataSet.h"

class DataSetAFKRS12 : public DataSet
{
    public:
        const unsigned int NUMBER_OF_NEURONS = 6;

        DataSetAFKRS12(int numberOfSamples, int inputDimension):
            DataSet(numberOfSamples, inputDimension) {};
        void buildDataMatrix();
        void defineDesiredOutput();
        void defineWeightMatrix();
};

#endif // DATASETAFKRS12_H
