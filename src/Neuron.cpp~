#include <vector>
#include <cmath>
#include "Neuron.h"

using namespace std;

Neuron::Neuron(vector<double> &wghts, double momentum){
  m_weights = wghts;
  m_momentum = momentum;
  m_outputerror = 0;
}

double Neuron::sigderiv(double y){ return 1-y*y; };

void Neuron::increaseerror(double error){ m_outputerror += error; };
void Neuron::calculatedelta(){ m_delta = sigderiv(m_output)*m_outputerror; };

double Neuron::activate(vector<double> &inputs){
  m_inputs = inputs;
  double summedwghts = 0;
  double sigmoidresult;
  for (unsigned n = 0; n < inputs.size(); ++n){
    double wghted = m_weights[n]*inputs[n];
    summedwghts += wghted;
  }
  sigmoidresult = 1/(1+pow((exp(1)),-(summedwghts-m_momentum)));
  m_output = sigmoidresult;
  return sigmoidresult;
}

void Neuron::updateweights(){
  vector<double> updated_weights;
  for(unsigned i = 0; i < m_weights.size(); i++){
    updated_weights.push_back(m_weights[i] + m_momentum*(m_delta*m_inputs[i]));
  }
  m_weights = updated_weights;
}

