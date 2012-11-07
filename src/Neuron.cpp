#include <vector>
#include "Neuron.h"

using namespace std;

Neuron::Neuron(vector<double> wghts, double momentum){
  m_weights = wghts;
  m_momentum = momentum;
}

double Neuron::activate(vector<double> inputs){
  double summedwghts = 0;
  double sigmoidresult;
  for (unsigned n = 0; n < inputs.size(); ++n){
    double wghted = m_weights[n]*inputs[n];
    summedwghts += wghted;
  }
  sigmoidresult = 1/(1+((exp(1))^-(summedwghts-m_momentum)));
  return sigmoidresult;
}

