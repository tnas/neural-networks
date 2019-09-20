#ifndef DATASETABPATTERN_H
#define DATASETABPATTERN_H

#include <DataSet.h>


class DataSetABPattern : public DataSet
{
    public:
        /** Default constructor */
        DataSetABPattern(int numberOfSamples, int inputDimension):
            DataSet(numberOfSamples, inputDimension) {};
        /** Default destructor */
        virtual ~DataSetABPattern();
        void buildDataMatrix();
        void defineDesiredOutput();
};

#endif // DATASETABPATTERN_H
