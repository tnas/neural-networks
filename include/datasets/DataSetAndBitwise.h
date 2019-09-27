#ifndef DATASETANDBITWISE_H
#define DATASETANDBITWISE_H

#include "DataSet.h"


class DataSetAndBitwise : public DataSet
{
    public:
        DataSetAndBitwise(int numberOfSamples, int inputDimension):
            DataSet(numberOfSamples, inputDimension) {};
        void buildDataMatrix();
        void defineDesiredOutput();
};

#endif // DATASETANDBITWISE_H
