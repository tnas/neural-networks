#ifndef TRACE_H
#define TRACE_H

#include <vector>

using namespace std;

class Trace
{
    const int iteration;
    const int inputDimension;
    const vector<float> weights;
    const float bias;
    const float result;

    public:
        Trace(int iter, int inputDim, vector<float> weights, float bias, float result):
            iteration(iter),
            inputDimension(inputDim),
            weights(weights),
            bias(bias),
            result(result) {};
        virtual ~Trace();
        void toString();

};

#endif // TRACE_H
