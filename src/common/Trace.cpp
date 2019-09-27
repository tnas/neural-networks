#include "../../include/common/Trace.h"
#include <iostream>

Trace::~Trace()
{

}

void Trace::toString()
{
    cout << "(";
    for (float input : this->inputs)
    {
        cout << input << ",";
    }
    cout << ") --> " << "Y* = " << this->result << " "
         << "Y = " << this->output << " "
         << "d = " << this->desired << " ";

    int i = 1;
    for (float weight : this->weights)
    {
        cout << "w" << i++ << " = " << weight << " ";
    }

    cout << "bias = " << this->bias << endl;
}
