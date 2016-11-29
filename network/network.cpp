//
// Created by themegatb on 11/29/16.
//

#include <iostream>
#include "network.h"

template<typename T>
Network<T>::Network(size_t input_size) {
    this->input_size = input_size;
}

template<typename T>
void Network<T>::add_layer(size_t layer_size, ActivationFunction<T> af) {
    size_t input_size = this->layers.size() == 0 ? this->input_size : this->layers.back().output_size();

    this->layers.reserve(this->layers.size() + 1);

    this->layers.push_back(Layer<T>(layer_size, input_size, af));
}

template<typename T>
void Network<T>::modify() {
    for (int i = 0; i < this->layers.size(); ++i) {
        this->layers[i].modify();
    }
}

template<typename T>
vector<T> Network<T>::calculate(vector <T> inputs) {
    vector<T> last_results = inputs;
    for (int i = 0; i < this->layers.size(); ++i) {
        for (int j = 0; j < last_results.size(); ++j) {
            cout << last_results[j] << " | ";
        }
        cout << endl;
        last_results = this->layers[i].calculate(last_results);
    }

    return last_results;
}

template class Network<double>;