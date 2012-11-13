#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include "Layer.h"
#include "Neuron.h"

class Network
{
 public:
  Network(std::vector<unsigned> arch, double momentum);
  std::vector<double> feedforward(std::vector<double> inputs);
  void backprop(std::vector<double> actual);
  void trainnetwork(std::vector<double> inputs,std::vector<double> actual);
  void increasenetworkerror(double err);
  double getnetworkerror();
  std::vector<double> getlastoutput();
 private:
  std::vector<Layer> m_network;
  double randweight();
  double m_momentum;
  unsigned m_numLayers;
  unsigned m_numInputs;
  double sigderiv(double y);
  double m_networkerror;
  std::vector<double> m_lastoutput;
};

#endif
