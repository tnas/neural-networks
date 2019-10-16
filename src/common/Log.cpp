#include "../../include/common/Log.h"

Log::Log()
{
    //ctor
}

Log::~Log()
{
    this->tracer.clear();
    this->status.clear();
    this->khTracer.clear();
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

void Log::addKohonenTrace(KohonenTrace trace)
{
    this->khTracer.push_back(trace);
}

void Log::addIterationStatus(Trace trace)
{
    this->status.push_back(trace);
}

void Log::setLearningRate(float learning)
{
    this->learningRate = learning;
}

void Log::setRadius(float radius)
{
    this->radius = radius;
}

void Log::print()
{
    if (!this->tracer.empty())
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
    else if (!this->khTracer.empty())
    {
        cout << "-- Iteration: " << this->iteration
             << " (alpha = " << this->learningRate
             << ", Radius = " << this->radius << ")" << endl;

        for (KohonenTrace trace : this->khTracer)
            trace.toString();
    }

}


