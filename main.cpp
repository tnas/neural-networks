#include <iostream>
#include "include/Perceptron.h"
#include "include/DataSet.h"
#include "include/DataSetAndBitwise.h"
#include "include/DataSetABPattern.h"
#include "include/DataSetClassifier.h"
#include "include/DataSetClassifierTest.h"

using namespace std;

int main()
{
    DataSet* dataSet = new DataSetClassifier(22, 2);
    dataSet->defineDesiredOutput();
    dataSet->buildDataMatrix();

    Perceptron perceptron = Perceptron(1.0, 0.0, 0.2, 0.0, 1000);
    perceptron.run(dataSet);
    perceptron.printTrace();

    DataSet* dataSetTest = new DataSetClassifierTest(8, 2);
    dataSetTest->defineDesiredOutput();
    dataSetTest->buildDataMatrix();

    perceptron.test(dataSetTest);

    free(dataSet);
    free(dataSetTest);

    return 0;
}
