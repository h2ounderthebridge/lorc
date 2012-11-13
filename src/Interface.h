#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <cppcms/application.h>
#include <cppcms/service.h>
#include "Network.h"
#include "Layer.h"
#include "Neuron.h"

class interface : public cppcms::application {

 public:
  interface(cppcms::service &srv);
  void create();
  void train();
  void jtrain();
  void classify();
 private:
  std::vector<Network> m_appnet;
  unsigned m_numInputs;
  unsigned m_numHidden;
  unsigned m_numOutputs;
};

#endif
