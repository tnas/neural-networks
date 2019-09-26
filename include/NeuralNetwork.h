#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "Trace.h"
#include "DataSet.h"
#include <iostream>
#include <vector>

using namespace std;

class NeuralNetwork
{
    protected :
        const DataSet* dataSet;
        vector<Trace> tracer;
        float bias; // theta
        float* weights;
        const unsigned int inputDimension;
        float learningRate; // alpha
        const float thresholdError;
        const unsigned int maxIterations;

    public:
        NeuralNetwork(float bias, float* weights, unsigned int dimension,
                      float learningRate, float error, unsigned int iterations) :
            bias(bias),
            weights(weights),
            inputDimension(dimension),
            learningRate(learningRate),
            thresholdError(error),
            maxIterations(iterations) {};
        virtual ~NeuralNetwork();

        float dotProduct(float* sample, float* weights, int dim);
        void printTrace();
        void test(const DataSet* dataSet);

        virtual void run(const DataSet* dataSet) = 0;
        virtual int applyActivationFunction(float result) = 0;
};

#endif // NEURALNETWORK_H
