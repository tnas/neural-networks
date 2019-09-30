#include "NetworkRunner.h"

NetworkRunner::NetworkRunner()
{
    //ctor
}

NetworkRunner::~NetworkRunner()
{
    free(this->weights);
}

void NetworkRunner::loadConfigurations()
{
    ifstream netFile(NetworkRunner::NET_CONF_PATH);
    string line, keyConf;
    unsigned int net, actFunction, ds;

    if (netFile.is_open())
    {
        while (getline(netFile, line))
        {
            if (line.find(NetworkRunner::COMMENT_CHARACTER) == string::npos && !line.empty())
            {
                istringstream sline(line);
                sline >> keyConf;

                if (keyConf.compare(NetworkRunner::CONF_PARAM_NET) == 0)
                {
                    sline >> net;
                    switch (net)
                    {
                    case NetType::PERCEPTRON :
                        this->netType = NetType::PERCEPTRON;
                        break;
                    case NetType::ADALINE :
                        this->netType = NetType::ADALINE;
                        break;
                    default :
                        cerr << "Invalid net configuration!" << endl;
                        exit(1);
                    }
                }
                else if (keyConf.compare(NetworkRunner::CONF_PARAM_LEARN_RATE) == 0)
                {
                    sline >> this->learningRate;
                }
                else if (keyConf.compare(NetworkRunner::CONF_PARAM_BIAS) == 0)
                {
                    sline >> this->bias;
                }
                else if (keyConf.compare(NetworkRunner::CONF_PARAM_ERROR) == 0)
                {
                    sline >> this->thresholdError;
                }
                else if (keyConf.compare(NetworkRunner::CONF_PARAM_ITERATIONS) == 0)
                {
                    sline >> this->maxIterations;
                }
                else if (keyConf.compare(NetworkRunner::CONF_PARAM_DIMENSION) == 0)
                {
                    sline >> this->inputDimension;
                }
                else if (keyConf.compare(NetworkRunner::CONF_PARAM_WEIGHTS) == 0)
                {
                    this->weights = new float[this->inputDimension];
                    for (unsigned int w = 0; w < this->inputDimension; ++w)
                        sline >> this->weights[w];
                }
                else if (keyConf.compare(NetworkRunner::CONF_PARAM_INDEFINITION_RATE) == 0)
                {
                    sline >> this->indefinitionRate;
                }
                else if (keyConf.compare(NetworkRunner::CONF_PARAM_LEARN_DECREASE_RATE) == 0)
                {
                    sline >> this->learningDecrease;
                }
                else if (keyConf.compare(NetworkRunner::CONF_PARAM_ACTIVATION_FUNCTION) == 0)
                {
                    sline >> actFunction;
                    switch (actFunction)
                    {
                    case NeuralNetwork::BINARY :
                        this->activationFunction = NeuralNetwork::BINARY;
                        break;
                    case NeuralNetwork::LIMIAR :
                        this->activationFunction = NeuralNetwork::LIMIAR;
                        break;
                    case NeuralNetwork::TANH :
                        this->activationFunction = NeuralNetwork::TANH;
                        break;
                    default :
                        cerr << "Invalid activation function!" << endl;
                        exit(1);
                    }
                }
                 else if (keyConf.compare(NetworkRunner::CONF_PARAM_DATA_SET) == 0)
                {
                    sline >> ds;
                    switch (ds)
                    {
                    case DataSetFactory::AB_PATTERN :
                        this->dsType = DataSetFactory::AB_PATTERN;
                        break;
                    case DataSetFactory::AND_BITWISE :
                        this->dsType = DataSetFactory::AND_BITWISE;
                        break;
                    case DataSetFactory::CLASSIFIER :
                        this->dsType = DataSetFactory::CLASSIFIER;
                        break;
                    case DataSetFactory::OR_BITWISE :
                        this->dsType = DataSetFactory::OR_BITWISE;
                        break;
                    case DataSetFactory::VECTOR_CLASSIFIER :
                        this->dsType = DataSetFactory::VECTOR_CLASSIFIER;
                        break;
                    default :
                        cerr << "Invalid data set configuration!" << endl;
                        exit(1);
                    }
                }
                else
                {
                    cerr << "Invalid net configuration!" << endl;
                    exit(1);
                }
            }
        }
    }

    netFile.close();
}

void NetworkRunner::execute()
{
    const DataSet* dataSet = this->dsFactory.getDataSet(this->dsType);
    NeuralNetwork* neuralNet;

    switch (this->netType)
    {
    case NetType::PERCEPTRON :
        neuralNet = new Perceptron(this->learningRate, this->bias, this->indefinitionRate,
                                   this->thresholdError, this->maxIterations, this->inputDimension,
                                   this->activationFunction);
        break;
    case NetType::ADALINE :
        neuralNet = new Adaline(this->learningRate, this->thresholdError, this->bias, this->weights,
                                this->learningDecrease, this->inputDimension, this->maxIterations,
                                this->activationFunction);
        break;
    }

    neuralNet->run(dataSet);

    if (this->dsType == DataSetFactory::CLASSIFIER)
    {
        neuralNet->test(this->dsFactory.getDataSet(DataSetFactory::CLASSIFIER_TEST));
    }
    else
    {
        neuralNet->printTrace();
    }

    free(neuralNet);
}

void NetworkRunner::printConfigurations()
{
    cout << "Net: " << this->netType << endl
         << "Learning Rate: " << this->learningRate << endl
         << "Learn Rate Decrease: " << this->learningDecrease << endl
         << "Bias: " << this->bias << endl
         << "Error: " << this->thresholdError << endl
         << "Iterations: " << this->maxIterations << endl
         << "Input Dimension: " << this->inputDimension << endl
         << "Indefinition Rate: " << this->indefinitionRate << endl
         << "Activation Function: " << this->activationFunction << endl
         << "Data Set: " << this->dsType << endl;
}

