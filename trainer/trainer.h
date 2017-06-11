//
// Created by themegatb on 12/2/16.
//

#ifndef NEURALNETWORK_TRAINER_H
#define NEURALNETWORK_TRAINER_H

#include "../network/network.h"

template<typename T>
class Trainer {
    vector<Network<T>> networks;
    T (*rate_function)(Network<T>*);
    void step();
public:
    Trainer(Network<T>, size_t population_size, T (*rate_functon)(Network<T>*));
    void train(int n);

    vector<Network<T>> get_best_networks(size_t n);

    Network<T> get_best_network();
};

#endif //NEURALNETWORK_TRAINER_H
