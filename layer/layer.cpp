//
// Created by themegatb on 11/29/16.
//

#include "layer.h"

template<typename T>
Layer<T>::Layer(size_t layer_size, size_t input_size, ActivationFunction<T> af) {
    this->neurons.reserve(layer_size);

    for (int i = 0; i < layer_size; ++i) {
        this->neurons.push_back(
                Neuron<T>(af, input_size)
        );
    }
}

template<typename T>
void Layer<T>::modify() {
    for (int i = 0; i < this->neurons.size(); ++i) {
        this->neurons[i].modify();
    }
}

template<typename T>
size_t Layer<T>::output_size() {
    return this->neurons.size();
}

//template<typename T>
//vector<T> Layer<T>::getOutputs() {
//    vector<T> outputs;
//    outputs.reserve(this->neurons.size());
//
//    for (int i = 0; i < this->neurons.size(); ++i) {
//        outputs.push_back(this->neurons[i].value);
//    }
//
//    return outputs;
//}

template<typename T>
vector<T> Layer<T>::calculate(vector<T> inputs) {
    vector<T> results;
    results.reserve(this->neurons.size());

    for (int i = 0; i < this->neurons.size(); ++i) {
        results.push_back(this->neurons[i].calculate(inputs));
    }

    return results;
}

template class Layer<double>;