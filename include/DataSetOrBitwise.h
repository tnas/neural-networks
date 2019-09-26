#ifndef DATASETORBITWISE_H
#define DATASETORBITWISE_H

#include "DataSet.h"


class DataSetOrBitwise : public DataSet
{
    public:
        DataSetOrBitwise(int numberOfSamples, int inputDimension):
            DataSet(numberOfSamples, inputDimension) {};
        void buildDataMatrix();
        void defineDesiredOutput();
};

#endif // DATASETORBITWISE_H
