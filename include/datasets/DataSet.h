#ifndef DATASET_H
#define DATASET_H


class DataSet
{
    protected:
        int numberOfSamples;
        int numberOfTests;
        int inputDimension;
        unsigned int numberOfNeurons;
        float** dataMatrix;
        float** weightMatrix;
        float** testMatrix;
        float* desiredOutput;

    public:
        DataSet(int numberOfSamples, int numberOfTests, int inputDimension, unsigned int neurons);
        DataSet(int numberOfSamples, int numberOfTests, int inputDimension) :
            DataSet(numberOfSamples, numberOfTests, inputDimension, 0) {};
        DataSet(int numberOfSamples, int inputDimension) :
            DataSet(numberOfSamples, 0, inputDimension) {};
        virtual ~DataSet();

        virtual void buildDataMatrix() = 0;
        virtual void defineDesiredOutput() {};
        virtual void defineWeightMatrix() {};
        virtual void defineTestMatrix() {};

        void printDesiredOutput();
        void printDataMatrix();
        int getInputDimension() const;
        int getNumberOfSamples() const;
        int getNumberOfTests() const;
        unsigned int getNumberOfNeurons() const;
        float** getDataMatrix() const;
        float** getWeightMatrix() const;
        float** getTestMatrix() const;
        float* getDesiredOutput() const;
};

#endif // DATASET_H
