#ifndef DATASET_H
#define DATASET_H


class DataSet
{
    protected:
        int numberOfSamples;
        int inputDimension;
        unsigned int numberOfNeurons;
        float** dataMatrix;
        float** weightMatrix;
        float* desiredOutput;

        void prepareWeightMatrix(unsigned int neurons);

    public:
        DataSet(int numberOfSamples, int inputDimension);
        virtual ~DataSet();

        virtual void buildDataMatrix() = 0;
        virtual void defineDesiredOutput() = 0;
        virtual void defineWeightMatrix() {};

        void printDesiredOutput();
        void printDataMatrix();
        int getInputDimension() const;
        int getNumberOfSamples() const;
        unsigned int getNumberOfNeurons() const;
        float** getDataMatrix() const;
        float** getWeightMatrix() const;
        float* getDesiredOutput() const;
};

#endif // DATASET_H
