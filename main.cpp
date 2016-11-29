#include <iostream>

#include "neuron/neuron.h"
#include "layer/layer.h"
#include "network/network.h"

double testAF(double &in) {
    return 1.5;
}

int main() {
    std::srand(time(NULL));

//    union Parameters<double> params;
//    params.sine = { omega: 1, theta: 2.5 };
//    ActivationFunction<double> af(AFType::Sine, &params);
//    std::cout << af.run(0.25) << std::endl;

    ActivationFunction<double> af(AFType::Sigmoid);

    Network<double> net(2);
    net.add_layer(2, af);
    net.add_layer(3, af);
    vector<double> results = net.calculate({0.5, 0.5});
    cout << "RES: ";
    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << " | ";
    }
    cout << endl;

//    Layer<double> l1(10, 2, af);
//    vector<double> out = l1.calculate({0.1, 0.5});
//    for (int i = 0; i < out.size(); ++i) {
//        cout << out[i] << endl;
//    }
//
//    cout << "------------" << endl;
//
//    l1.modify();
//    vector<double> out2 = l1.calculate({0.1, 0.5});
//    for (int i = 0; i < out2.size(); ++i) {
//        cout << out2[i] << endl;
//    }

//    Neuron<double> n(af, 10);
//
//    n.calculate({0.23, 0.1436, 0.5893, -0.2478, -0.923, 0.3543, -0.22, 0.4563, 0.99, -0.89});
//    std::cout << n.value << std::endl;
//
//    n.modify();
//    n.calculate({0.23, 0.1436, 0.5893, -0.2478, -0.923, 0.3543, -0.22, 0.4563, 0.99, -0.89});
//    std::cout << n.value << std::endl;

    std::cout << "Hello, World! " << std::endl;
    return 0;
}