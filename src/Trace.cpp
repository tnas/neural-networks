#include "Trace.h"
#include <iostream>

using namespace std;

Trace::~Trace()
{
    //dtor
}

void Trace::toString()
{
    cout << "Iter = " << this->iteration << " "
         << "Y* = " << this->result << " ";
    for (int i = 0; i < this->inputDimension; ++i)
    {
        cout << "w" << i << " = " << this->weighs[i] << " ";
    }

    cout << "bias = " << this->bias << endl;
}
