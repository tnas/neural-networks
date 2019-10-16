#ifndef KOHONENTRACE_H
#define KOHONENTRACE_H

#include <vector>
#include <iostream>

using namespace std;

class KohonenTrace
{
    public:
        KohonenTrace(vector<float> distance, unsigned int winner, unsigned int numberNeurons,
                     vector<vector<float>> weights, unsigned int dimension, float* input):
            distance(distance),
            winnerNeuron(winner),
            numberOfNeurons(numberNeurons),
            weights(weights),
            dimension(dimension),
            input(input) {};
        virtual ~KohonenTrace();
        void toString();

    protected:

    private:
        vector<float> distance;
        unsigned int winnerNeuron;
        unsigned int numberOfNeurons;
        vector<vector<float>> weights;
        unsigned int dimension;
        float* input;
};

#endif // KOHONENTRACE_H
