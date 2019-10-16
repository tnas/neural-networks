#ifndef HARDKOHONEN_H
#define HARDKOHONEN_H

#include "NeuralNetwork.h"
#include <limits>

using namespace std;

class HardKohonen : public NeuralNetwork
{
    const float learningDecrease;
    float radius;
    const float radiusDecreaseRate;

    public:
        HardKohonen(float learningRate, float error, float bias, float* weights, float learningDecrease,
                    float radius, float radiusDecRate, unsigned int dimension, unsigned int iterations,
                    ActivationFuncion actFunction) :
            NeuralNetwork(bias, weights, dimension, learningRate, error, iterations, actFunction),
            learningDecrease(learningDecrease),
            radius(radius),
            radiusDecreaseRate(radiusDecRate) {};
        void run(const DataSet* dataSet);

};

#endif // HARDKOHONEN_H
