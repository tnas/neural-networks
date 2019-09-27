#include "DataSetFactory.h"
#include "DataSetAndBitwise.h"
#include "DataSetOrBitwise.h"
#include "DataSetABPattern.h"
#include "DataSetClassifier.h"
#include "DataSetClassifierTest.h"
#include "DataSetVectorClassifier.h"

DataSetFactory::DataSetFactory()
{
    this->dataSets[0] = new DataSetABPattern(4, 2);
    this->dataSets[1] = new DataSetAndBitwise(4, 2);
    this->dataSets[2] = new DataSetClassifier(22, 2);
    this->dataSets[3] = new DataSetClassifierTest(8, 2);
    this->dataSets[4] = new DataSetOrBitwise(4, 2);
    this->dataSets[5] = new DataSetVectorClassifier(5, 4);

    for (unsigned int ds = 0; ds < DATASET_SAMPLES; ++ds)
    {
        this->dataSets[ds]->buildDataMatrix();
        this->dataSets[ds]->defineDesiredOutput();
    }
}

DataSetFactory::~DataSetFactory()
{
    for (unsigned int ds = 0; ds < DATASET_SAMPLES; ++ds)
    {
        free(this->dataSets[ds]);
    }
}

DataSet* DataSetFactory::getDataSet(DataSetType type)
{
    return this->dataSets[type];
}

