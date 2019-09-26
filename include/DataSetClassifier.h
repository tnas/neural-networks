#ifndef DATASETCLASSIFIER_H
#define DATASETCLASSIFIER_H

#include "DataSet.h"


class DataSetClassifier : public DataSet
{
    public:
        DataSetClassifier(int numberOfSamples, int inputDimension):
            DataSet(numberOfSamples, inputDimension) {};
        void buildDataMatrix();
        void defineDesiredOutput();
};

#endif // DATASETCLASSIFIER_H
