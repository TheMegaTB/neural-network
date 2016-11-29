cmake_minimum_required(VERSION 3.6)
project(NeuralNetwork)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp neuron/neuron.cpp neuron/neuron.h helpers.h layer/layer.cpp layer/layer.h network/network.cpp network/network.h)
add_executable(NeuralNetwork ${SOURCE_FILES})