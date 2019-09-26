#include "include/Perceptron.h"
#include "include/Adaline.h"
#include "include/DataSet.h"
#include "include/DataSetAndBitwise.h"
#include "include/DataSetOrBitwise.h"
#include "include/DataSetABPattern.h"
#include "include/DataSetClassifier.h"
#include "include/DataSetClassifierTest.h"

const int DATASET_SAMPLES = 5;
const int EXEC = 2;

int main()
{
    DataSet* dataSets[DATASET_SAMPLES];
    dataSets[0] = new DataSetABPattern(4, 2);
    dataSets[1] = new DataSetAndBitwise(4, 2);
    dataSets[2] = new DataSetClassifier(22, 2);
    dataSets[3] = new DataSetClassifierTest(8, 2);
    dataSets[4] = new DataSetOrBitwise(4, 2);

    for (unsigned int ds = 0; ds < DATASET_SAMPLES; ++ds)
    {
        dataSets[ds]->buildDataMatrix();
        dataSets[ds]->defineDesiredOutput();
    }

    if (EXEC == 1)
    {
        Perceptron perceptron = Perceptron(1.0, 0.0, 0.2, 0.0, 100, 2);
        perceptron.run(dataSets[2]);
        perceptron.test(dataSets[3]);
    }
    else if (EXEC == 2) {
        float weights[] = { 0.9, -0.7 };
        Adaline adaline = Adaline(0.4, 0.0, 0.0, weights, 2, 10);
        adaline.run(dataSets[1]);
        adaline.printTrace();
    }

    for (unsigned int ds = 0; ds < DATASET_SAMPLES; ++ds)
    {
        free(dataSets[ds]);
    }

    return 0;
}
