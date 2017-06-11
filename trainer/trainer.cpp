//
// Created by themegatb on 12/2/16.
//

#include "trainer.h"

template<typename T>
Trainer<T>::Trainer(Network<T> network, size_t population_size_factor, T (*new_rate_function)(Network<T>*)) {

    size_t population_size = population_size_factor * 2;

    this->networks.reserve(population_size);

    this->networks.push_back(network);
    for (int i = 0; i < population_size - 1; ++i) {
        Network<T> tmp_network = network;
        tmp_network.modify();
        this->networks.push_back(tmp_network);
    }

    this->rate_function = new_rate_function;
}

template<typename T>
Network<T> Trainer<T>::get_best_network() {

}