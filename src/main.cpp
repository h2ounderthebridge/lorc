#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include "Neuron.h"
#include "Layer.h"
#include "Network.h"

using namespace std;

int main(){
  vector<unsigned> test;
  test.push_back(1);
  test.push_back(1);
  test.push_back(1);
  Network mynet(test,0.5);
  vector<double> input;
  input.push_back(1.0);
  vector<double> output = mynet.feedforward(input);
  for(unsigned n = 0; n < output.size(); n++){
    cout << output[n] << endl;
  }

  system("PAUSE");
  return 0;
}
