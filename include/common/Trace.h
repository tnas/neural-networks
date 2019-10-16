#ifndef TRACE_H
#define TRACE_H

#include <iostream>
#include <vector>

using namespace std;

class Trace
{
    const vector<float> inputs;
    const vector<float> weights;
    const float bias;
    const float result;
    const float output;
    const float desired;

    public:
        Trace(vector<float> inputs, vector<float> weights, float bias, float result, float output, float desired):
            inputs(inputs),
            weights(weights),
            bias(bias),
            result(result),
            output(output),
            desired(desired) {};
        virtual ~Trace();
        void toString();

};

#endif // TRACE_H
