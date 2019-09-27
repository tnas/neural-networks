#include "include/nets/NeuralNetwork.h"
#include "include/nets/Perceptron.h"
#include "include/nets/Adaline.h"
#include "include/datasets/DataSetFactory.h"
#include "NetworkRunner.h"

const int EXEC = 3;

int main()
{

    NetworkRunner netRunner;
    netRunner.loadConfigurations();

    /*
    DataSetFactory dsFactory;

    if (EXEC == 1)
    {
        Perceptron perceptron = Perceptron(1.0, 0.0, 0.2, 0.0, 10, 2, NeuralNetwork::LIMIAR);
        perceptron.run(dsFactory.getDataSet(DataSetFactory::AB_PATTERN));
        perceptron.printTrace();
    }
    else if (EXEC == 2)
    {
        Perceptron perceptron = Perceptron(1.0, 0.0, 0.2, 0.0, 4, 2, NeuralNetwork::LIMIAR);
        perceptron.run(dsFactory.getDataSet(DataSetFactory::CLASSIFIER));
        perceptron.test(dsFactory.getDataSet(DataSetFactory::CLASSIFIER_TEST));
    }
    else if (EXEC == 3) {
        float weights[] = { 0.3, 0.7 };
        Adaline adaline = Adaline(0.4, 0.0, 0.0, weights, 2, 20, NeuralNetwork::TANH);
        adaline.run(dsFactory.getDataSet(DataSetFactory::VECTOR_CLASSIFIER));
        adaline.printTrace();
    }
    else if (EXEC == 4) {
        float weights[] = { 0.9, -0.7 };
        Adaline adaline = Adaline(0.4, 0.0, 0.0, weights, 2, 4, NeuralNetwork::BINARY);
        adaline.run(dsFactory.getDataSet(DataSetFactory::CLASSIFIER));
        adaline.test(dsFactory.getDataSet(DataSetFactory::CLASSIFIER_TEST));
    }
    */

    return 0;
}
