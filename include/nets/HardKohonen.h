#ifndef HARDKOHONEN_H
#define HARDKOHONEN_H

#include "NeuralNetwork.h"
#include <limits>
#include <iostream>

using namespace std;

class HardKohonen : public NeuralNetwork
{
    const float learningDecrease;
    float radius;
    const float radiusDecreaseRate;
    float* distance;

    public:
        HardKohonen(float learningRate, float error, float bias, float* weights, float learningDecrease,
                    float radius, float radiusDecRate, unsigned int dimension, unsigned int iterations,
                    ActivationFuncion actFunction) :
            NeuralNetwork(bias, weights, dimension, learningRate, error, iterations, actFunction),
            learningDecrease(learningDecrease),
            radius(radius),
            radiusDecreaseRate(radiusDecRate),
            distance(nullptr) {};
        ~HardKohonen();
        unsigned int getWinnerNeuron(float* input, const DataSet* dataSet);
        void run(const DataSet* dataSet);
        void test(const DataSet* dataSet);

};

#endif // HARDKOHONEN_H
