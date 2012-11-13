#ifndef NEURON_H
#define NEURON_H

#include <vector>

class Neuron
{
 public:
  Neuron(std::vector<double> &wghts, double momentum);
  double activate(std::vector<double> &inputs);
  void increaseerror(double error);
  void calculatedelta();
  void updateweights();
  std::vector<double> m_weights;
  double m_momentum;
  std::vector<double> m_inputerrors;
  double m_outputerror;
  double m_delta;
  double m_output;
  std::vector<double> m_inputs;
  double sigderiv(double y);
};

#endif
