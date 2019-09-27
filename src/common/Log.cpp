#include "../../include/common/Log.h"

Log::Log()
{
    //ctor
}

Log::~Log()
{
    this->tracer.clear();
    this->status.clear();
}

void Log::setError(float error)
{
    this->error = error;
}

void Log::setIteration(unsigned int iter)
{
    this->iteration = iter;
}

void Log::addTrace(Trace trace)
{
    this->tracer.push_back(trace);
}

void Log::addIterationStatus(Trace trace)
{
    this->status.push_back(trace);
}

void Log::print()
{
    for (Trace trace : this->tracer)
        trace.toString();

    cout << "-- Iteration: " << this->iteration
         << " -- Error: " << this->error
         << " -- Current Status: " << endl;

     for (Trace trace : this->status)
        trace.toString();

    cout << "--------------" << endl;
}


