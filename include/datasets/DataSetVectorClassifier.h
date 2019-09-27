#ifndef DATASETVECTORCLASSIFIER_H
#define DATASETVECTORCLASSIFIER_H

#include "DataSet.h"


class DataSetVectorClassifier : public DataSet
{
    public:
        DataSetVectorClassifier(int numberOfSamples, int inputDimension):
            DataSet(numberOfSamples, inputDimension) {};
        void buildDataMatrix();
        void defineDesiredOutput();
};

#endif // DATASETVECTORCLASSIFIER_H
