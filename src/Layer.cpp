#include "Layer.h"
#include "Neuron.h"
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

Layer::Layer(vector<Neuron> neurons){
  m_neurons = neurons;
}

vector<double> Layer::getlayeroutputs(vector<double> inputs){
  vector<double> results;
  for(unsigned n = 0; n < m_neurons.size(); n++){
    double result = m_neurons[n].activate(inputs);
    results.push_back(result);
  }
  return results;
}


