#include "../../include/datasets/DataSetFactory.h"

DataSetFactory::DataSetFactory()
{
    for (unsigned int ds = 0; ds < DATASET_SAMPLES; ++ds)
    {
        this->dataSets[ds] = nullptr;
    }
}

DataSetFactory::~DataSetFactory()
{
    for (unsigned int ds = 0; ds < DATASET_SAMPLES; ++ds)
    {
        if (this->dataSets[ds] != nullptr) free(this->dataSets[ds]);
    }
}

DataSet* DataSetFactory::getDataSet(DataSetType type)
{
    int ds = type - 1;

    if (this->dataSets[ds] == nullptr)
    {
        switch (type)
        {
        case DataSetType::AB_PATTERN :
            this->dataSets[ds] = new DataSetABPattern(4, 2);
            break;
        case DataSetType::AND_BITWISE :
            this->dataSets[ds] = new DataSetAndBitwise(4, 2);
            break;
        case DataSetType::CLASSIFIER :
            this->dataSets[ds] = new DataSetClassifier(22, 2);
            break;
        case DataSetType::OR_BITWISE :
            this->dataSets[ds] = new DataSetOrBitwise(4, 2);
            break;
        case DataSetType::VECTOR_CLASSIFIER :
            this->dataSets[ds] = new DataSetVectorClassifier(5, 4);
            break;
        case DataSetType::CLASSIFIER_TEST :
            this->dataSets[ds] = new DataSetClassifierTest(8, 2);
            break;
        case DataSetType::AFKRS12 :
            this->dataSets[ds] = new DataSetAFKRS12(7, 4, 5);
            break;
        }

        this->dataSets[ds]->buildDataMatrix();
        this->dataSets[ds]->defineDesiredOutput();
        this->dataSets[ds]->defineWeightMatrix();
        this->dataSets[ds]->defineTestMatrix();
    }

    return this->dataSets[ds];
}

