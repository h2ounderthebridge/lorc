#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Neuron{
 public:
  Neuron(std::vector<double> wghts, double momentum);
  double activate(std::vector<double> inputs);
  
 private:
  std::vector<double> m_weights;
  double m_momenutm;
};

#endif
