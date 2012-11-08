#include "Network.h"
#include "Layer.h"
#include "Neuron.h"
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

Network::Network(vector<unsigned> arch, double momentum){
  m_momentum = momentum;
  m_numLayers = arch.size()-1;
  m_numInputs = arch[0];
  vector<Layer> layers;
  for(unsigned n = 1; n < arch.size(); n++){
    vector<Neuron> neurons;
    unsigned neuroncount = arch[n];
    unsigned inputcount = arch[n-1];
    for(unsigned q = 0; q < neuroncount; q++){
      vector<double> wghts;
      for(unsigned r = 0; r < inputcount; r++){
	wghts.push_back(randweight());
      }
      neurons.push_back(Neuron(wghts,m_momentum));
    }
    layers.push_back(Layer(neurons));
  }
  m_network = layers;
}

double Network::randweight(){
  return (double)rand() / (double)RAND_MAX;
}

double Network::sigderiv(double y){
  return 1-y*y;
};

vector<double> Network::feedforward(vector<double> inputs){
  for(unsigned n = 0; n < m_network.size(); n++){
    inputs = m_network[n].getlayeroutputs(inputs);
  }
  return inputs;
}

void Network::backprop(vector<double> actual){
  for(unsigned i = m_numLayers-1; i != -1; i--){
    if(i == m_numLayers-1){
      for(unsigned r = 0; r < m_network[i].m_neurons.size(); r++){
	double err = actual[r]-m_network[i].m_neurons[r].m_output;
	m_network[i].m_neurons[r].increaseerror(err);
	m_network[i].m_neurons[r].calculatedelta();
	for(unsigned g = 0; g < m_network[i-1].m_neurons.size(); g++){
	  double incerr = m_network[i].m_neurons[r].m_delta*m_network[i].m_neurons[r].m_weights[g];
	  m_network[i-1].m_neurons[g].increaseerror(incerr);
	}
	m_network[i].m_neurons[r].updateweights();
      }
    }
    else {
      for(unsigned r = 0; r < m_network[i].m_neurons.size(); r++){
	m_network[i].m_neurons[r].calculatedelta();
	m_network[i].m_neurons[r].updateweights();
      }
    }
  }
}

void Network::trainnetwork(vector<double> inputs, vector<double> actual){
  vector<double> test = feedforward(inputs);
  backprop(actual);
}
      
  
