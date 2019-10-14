#ifndef DATASETFACTORY_H
#define DATASETFACTORY_H

#include <iostream>
#include "DataSet.h"
#include "DataSetFactory.h"
#include "DataSetAndBitwise.h"
#include "DataSetOrBitwise.h"
#include "DataSetABPattern.h"
#include "DataSetClassifier.h"
#include "DataSetClassifierTest.h"
#include "DataSetVectorClassifier.h"
#include "DataSetAFKRS12.h"

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
            CLASSIFIER_TEST,
            AFKRS12,
        };

        DataSetFactory();
        virtual ~DataSetFactory();
        DataSet* getDataSet(DataSetType type);

    protected:

    private:
        static const int DATASET_SAMPLES = 7;
        DataSet* dataSets[DATASET_SAMPLES];
};

#endif // DATASETFACTORY_H
