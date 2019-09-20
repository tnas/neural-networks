#ifndef DATASET_H
#define DATASET_H


class DataSet
{
    protected:
        int numberOfSamples;
        int inputDimension;
        float** dataMatrix;
        int* desiredOutput;

    public:
        DataSet(int numberOfSamples, int inputDimension);
        virtual ~DataSet();

        virtual void buildDataMatrix() = 0;
        virtual void defineDesiredOutput() = 0;

        void printDesiredOutput();
        void printDataMatrix();
        int getInputDimension() const;
        int getNumberOfSamples() const;
        float** getDataMatrix() const;
        int* getDesiredOutput() const;
};

#endif // DATASET_H
