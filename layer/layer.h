//
// Created by themegatb on 11/29/16.
//

#ifndef NEURALNETWORK_LAYER_H
#define NEURALNETWORK_LAYER_H

using namespace std;

#include <vector>
#include "../neuron/neuron.h"

template<typename T>
class Layer {
    vector<Neuron<T>> neurons;
public:
    Layer(size_t layer_size, size_t input_size, ActivationFunction<T> af);
    void modify();
//    vector<T> getOutputs();
    size_t output_size();
    vector<T> calculate(vector<T> inputs);
};

#endif //NEURALNETWORK_LAYER_H
