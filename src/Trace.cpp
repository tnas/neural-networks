#include "../include/Trace.h"
#include <iostream>

Trace::~Trace()
{

}

void Trace::toString()
{
    cout << "Iter = " << this->iteration << " "
         << "Y* = " << this->result << " ";
    for (int i = 0; i < this->inputDimension; ++i)
    {
        cout << "w" << i << " = " << this->weights[i] << " ";
    }

    cout << "bias = " << this->bias << endl;
}
