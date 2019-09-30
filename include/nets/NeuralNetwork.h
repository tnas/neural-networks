#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include "../common/Log.h"
#include "../common/Trace.h"
#include "../datasets/DataSet.h"
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class NeuralNetwork
{
    public:
        enum ActivationFuncion { BINARY = 1, LIMIAR, TANH };

        NeuralNetwork(float bias, float* weights, unsigned int dimension,
                      float learningRate, float error, unsigned int iterations,
                      ActivationFuncion actFunction) :
            bias(bias),
            weights(weights),
            inputDimension(dimension),
            learningRate(learningRate),
            thresholdError(error),
            maxIterations(iterations),
            indefinitionRate(DEFAULT_UNDEF_RATE),
            actFunction(actFunction) {};
        virtual ~NeuralNetwork();

        float dotProduct(float* sample, float* weights, int dim);
        void test(const DataSet* dataSet);
        void addLog(Log log);
        void printTrace();
        vector<float> getVector(const unsigned int dim, const float* values);
        void setIndefinitionRate(float indefinitionRate);
        float applyActivationFunction(float result);
        float getCurrentQuadraticError();
        int evaluateIteration();

        virtual void run(const DataSet* dataSet) = 0;

    protected :
        const DataSet* dataSet;
        vector<Log> logger;
        float bias; // theta
        float* weights;
        const unsigned int inputDimension;
        float learningRate; // alpha
        const float thresholdError;
        const unsigned int maxIterations;

    private :
        static const int DEFAULT_UNDEF_RATE = 0.2;

        float indefinitionRate; // delta
        NeuralNetwork::ActivationFuncion actFunction;

        float getBinaryFunction(float result);
        float getLimiarFunction(float result);
        float getHTangentFunction(float result);
};

#endif // NEURALNETWORK_H
