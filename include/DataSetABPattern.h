#ifndef DATASETABPATTERN_H
#define DATASETABPATTERN_H

#include "DataSet.h"

/**
 * XOR modeled as A and B
 */
class DataSetABPattern : public DataSet
{
    public:
        DataSetABPattern(int numberOfSamples, int inputDimension):
            DataSet(numberOfSamples, inputDimension) {};
        void buildDataMatrix();
        void defineDesiredOutput();
};

#endif // DATASETABPATTERN_H
