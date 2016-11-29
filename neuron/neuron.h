//
// Created by themegatb on 11/28/16.
//

#ifndef NEURALNETWORK_NEURON_H
#define NEURALNETWORK_NEURON_H

#include <vector>

typedef double value;
template<typename T>
union Parameters {
    T (*custom_function)(T&);
    struct {
        double omega;
        double theta;
    } sine;
    struct {
        double theta;
    } sigmoid;
};

value sigmoid(value&);

enum AFType {
    Sigmoid,
    Sine,
    Custom
};

template<typename T>
class ActivationFunction {
    AFType type;
    Parameters<T> parameters;
public:
    ActivationFunction(AFType = AFType::Sigmoid, union Parameters<T> * = nullptr);
    T run(T);
};

template<typename T>
class Neuron {
    ActivationFunction<T> af;
    std::vector<T> weights;
public:
    Neuron(ActivationFunction<T>, std::size_t input_length);

    double value;

    T calculate(std::vector<T> inputs);
    void modify();
};

#endif //NEURALNETWORK_NEURON_H
