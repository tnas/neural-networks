#include "../../include/common/KohonenTrace.h"


KohonenTrace::~KohonenTrace()
{

}

void KohonenTrace::toString()
{
    cout << "Presenting input: ";
    for (unsigned int coord = 0; coord < this->dimension; ++coord)
    {
        cout << this->input[coord] << " ";
    }
    cout << endl;

    unsigned int neuron = 0;
    for (float distNeuron : this->distance)
    {
        cout << "d" << neuron << " = " << distNeuron;
        if (neuron == this->winnerNeuron) cout << " (Winner)";
        cout << endl;
        ++neuron;
    }

    cout << "Weights after updating:" << endl;
    for (vector<float> weightsNeuron : this->weights)
    {
        for (float weight : weightsNeuron)
        {
            cout << weight << " ";
        }
        cout << endl;
    }
}
