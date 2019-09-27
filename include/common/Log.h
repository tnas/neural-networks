#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <vector>
#include "Trace.h"

using namespace std;

class Log
{
    unsigned int iteration;
    float error;
    vector<Trace> tracer;
    vector<Trace> status;

    public:
        Log();
        virtual ~Log();
        void setError(float error);
        void setIteration(unsigned int iter);
        void addIterationStatus(Trace trace);
        void addTrace(Trace trace);
        void print();
};

#endif // LOG_H
