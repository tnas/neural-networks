#ifndef DATASETAFKRS12_H
#define DATASETAFKRS12_H

#include "DataSet.h"

class DataSetAFKRS12 : public DataSet
{
    public:
        static const unsigned int NUMBER_OF_NEURONS = 6;

        DataSetAFKRS12(int numberOfSamples, int numberOfTests, int inputDimension):
            DataSet(numberOfSamples, numberOfTests, inputDimension, NUMBER_OF_NEURONS) {};
        void buildDataMatrix();
        void defineWeightMatrix();
        void defineTestMatrix();
};

#endif // DATASETAFKRS12_H
