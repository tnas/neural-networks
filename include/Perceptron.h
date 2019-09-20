#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include "DataSet.h"

class Perceptron
{
    const float learningRate; // alpha
    const float bias; // theta
    const float indefinitionRate; // delta
    const float thresholdError;

    float* weights;
    int inputDimension;
    int iterations;

    void initializeWeights();

    public:
        Perceptron(float learningRate, float bias, float indefinitionRate, float thresholdError):
            learningRate(learningRate),
            bias(bias),
            indefinitionRate(indefinitionRate),
            thresholdError(thresholdError),
            weights(nullptr){};
        virtual ~Perceptron();

        void run(const DataSet* dataSet);
        void printTrace();
};

#endif // PERCEPTRON_H
