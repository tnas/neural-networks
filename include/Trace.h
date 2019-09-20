#ifndef TRACE_H
#define TRACE_H


class Trace
{
    const int iteration;
    const int inputDimension;
    const float* weighs;
    const float bias;
    const float result;

    public:
        Trace(int iter, int inputDim, float* weighs, float bias, float result):
            iteration(iter),
            inputDimension(inputDim),
            weighs(weighs),
            bias(bias),
            result(result) {};
        virtual ~Trace();
        void toString();

};

#endif // TRACE_H
