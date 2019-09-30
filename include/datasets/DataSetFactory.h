#ifndef DATASETFACTORY_H
#define DATASETFACTORY_H

#include <iostream>
#include "DataSet.h"

using namespace std;

class DataSetFactory
{
    public:
        enum DataSetType
        {
            AB_PATTERN = 1,
            AND_BITWISE,
            CLASSIFIER,
            OR_BITWISE,
            VECTOR_CLASSIFIER,

            CLASSIFIER_TEST
        };

        DataSetFactory();
        virtual ~DataSetFactory();
        DataSet* getDataSet(DataSetType type);

    protected:

    private:
        static const int DATASET_SAMPLES = 6;
        DataSet* dataSets[DATASET_SAMPLES];
};

#endif // DATASETFACTORY_H
