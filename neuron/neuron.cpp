//
// Created by themegatb on 11/28/16.
//

#include <math.h>
#include <iostream>
#include <typeinfo>

#include "../helpers.h"
#include "neuron.h"

value sigmoid(value& in) {
    return (value) (1.0 / (1 + exp(-10.0 * in)));
}

value sine(value& in) {
    return (value) sin(in);
}

template<typename T>
//ActivationFunction<T>::ActivationFunction(AFType aft, T (*_custom_function)(T&)) {
ActivationFunction<T>::ActivationFunction(AFType aft, union Parameters * param) {
    if (!param) {
        this->parameters = {};
    } else {
        this->parameters = *param;
    }
    this->type = aft;
    switch (aft) {
        case AFType::Custom:
            this->parameters.custom_function = this->parameters.custom_function;
            break;
        default:
            break;
    }
}

template<typename T>
T ActivationFunction<T>::run(T in) {
    T input_value;
    switch (this->type) {
        case AFType::Sigmoid:
            input_value = in - this->parameters.sigmoid.theta;
            return sigmoid(input_value);
        case AFType::Sine:
            input_value = this->parameters.sine.omega * in - this->parameters.sine.theta;
            return sine(input_value);
        case AFType::Custom:
            return this->parameters.custom_function(in);
    }
    return 0.0;
}

template<typename T>
Neuron<T>::Neuron(ActivationFunction<T> activation_function, size_t input_length) {
    this->af = activation_function;
    this->weights.reserve(input_length);

    for (int i = 0; i < input_length; ++i) {
        this->weights.push_back(rand_double() * 4.0 - 2.0);
    }
}

template<typename T>
void Neuron<T>::calculate(std::vector<T> inputs) {
    T sum = 0.0;

    for (int i = 0; i < this->weights.size(); ++i) {
        std::cout << weights[i] << std::endl;
        sum += inputs[i] * weights[i];
    }

    std::cout << sum << std::endl;

    this->value = this->af.run(sum);
}


template class ActivationFunction<double>;
template class Neuron<double>;