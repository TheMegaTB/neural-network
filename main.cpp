#include <iostream>

#include "neuron/neuron.h"

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
    Neuron<double> n(af, 10);

    n.calculate({0.23, 0.1436, 0.5893, -0.2478, -0.923, 0.3543, -0.22, 0.4563, 0.99, -0.89});
    std::cout << n.value << std::endl;

    std::cout << "Hello, World! " << std::endl;
    return 0;
}