#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <vector>
#include "Trace.h"
#include "KohonenTrace.h"

using namespace std;

class Log
{
    unsigned int iteration;
    float error;
    float learningRate;
    float radius;
    vector<Trace> tracer;
    vector<Trace> status;
    vector<KohonenTrace> khTracer;

    public:
        Log();
        virtual ~Log();
        void setError(float error);
        void setLearningRate(float learning);
        void setRadius(float radius);
        void setIteration(unsigned int iter);
        void addIterationStatus(Trace trace);
        void addTrace(Trace trace);
        void addKohonenTrace(KohonenTrace trace);
        void print();
};

#endif // LOG_H
