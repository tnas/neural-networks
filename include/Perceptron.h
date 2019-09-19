#ifndef PERCEPTRON_H
#define PERCEPTRON_H


class Perceptron
{
    float learningRate; // alpha
    float bias; // theta
    float indefinitionRate; // delta

    public:
        /** Default constructor */
        Perceptron();
        /** Default destructor */
        virtual ~Perceptron();
};

#endif // PERCEPTRON_H
