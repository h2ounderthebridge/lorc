#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Neuron{
 public:
  Neuron(double numInputs);
  
 private:
  std::vector<double> m_weights;
};
