//
// Created by themegatb on 11/29/16.
//

#ifndef NEURALNETWORK_NETWORK_H
#define NEURALNETWORK_NETWORK_H

#include "../layer/layer.h"

template<typename T>
class Network {
    vector<Layer<T>> layers;
    size_t input_size;
public:
    Network(size_t input_size);

    void add_layer(size_t layer_size, ActivationFunction<T>);
    void modify();

    vector<T> calculate(vector<T> inputs);
};

#endif //NEURALNETWORK_NETWORK_H
