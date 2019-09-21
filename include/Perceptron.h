#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "DataSet.h"

class Perceptron
{
    const float learningRate; // alpha
    const float indefinitionRate; // delta
    const float thresholdError;
    const int maxIterations;
    int inputDimension;

    float bias; // theta
    float* weights;

    void initializeWeights();
    int applyActivationFunction(float result);

    public:
        Perceptron(float learningRate, float bias, float indefinitionRate, float thresholdError, int maxIterations):
            learningRate(learningRate),
            bias(bias),
            indefinitionRate(indefinitionRate),
            thresholdError(thresholdError),
            maxIterations(maxIterations),
            weights(nullptr){};
        virtual ~Perceptron();

        void printTrace();
        void run(const DataSet* dataSet);
        void test(const DataSet* dataSet);
};

#endif // PERCEPTRON_H
