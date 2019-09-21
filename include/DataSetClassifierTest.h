#ifndef DATASETCLASSIFIERTEST_H
#define DATASETCLASSIFIERTEST_H

#include <DataSet.h>


class DataSetClassifierTest : public DataSet
{
    public:
        DataSetClassifierTest(int numberOfSamples, int inputDimension):
            DataSet(numberOfSamples, inputDimension) {};
        void buildDataMatrix();
        void defineDesiredOutput();
};

#endif // DATASETCLASSIFIERTEST_H
