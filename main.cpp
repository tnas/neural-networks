#include <iostream>
#include "include/Perceptron.h"
#include "include/DataSet.h"
#include "include/DataSetAndBitwise.h"

using namespace std;

int main()
{
    DataSet* dataSet = new DataSetAndBitwise(4, 2);
    dataSet->defineDesiredOutput();
    dataSet->buildDataMatrix();

    Perceptron perceptron = Perceptron(1.0, 0.0, 0.2, 0.0);
    perceptron.run(dataSet);
    perceptron.printTrace();

    free(dataSet);

    return 0;
}
