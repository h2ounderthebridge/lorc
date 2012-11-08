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
  test.push_back(4);
  test.push_back(4);
  test.push_back(1);
  Network mynet(test,0.8);
  vector<double> input1;
  vector<double> input2;
  vector<double> input3;
  vector<double> input4;
  vector<double> input5;
  vector<double> input6;
  vector<double> input7;
  vector<double> actual1;
  vector<double> actual2;
  vector<double> actual3;
  vector<double> actual4;
  vector<double> actual5;
  vector<double> actual6;
  vector<double> actual7;
  input1.push_back(1.0);
  input1.push_back(0.0);
  input1.push_back(1.0);
  input1.push_back(0.0);
  actual1.push_back(1.0);
  input2.push_back(0.0);
  input2.push_back(1.0);
  input2.push_back(1.0);
  input2.push_back(1.0);
  actual2.push_back(1.0);
  input3.push_back(0.0);
  input3.push_back(0.0);
  input3.push_back(1.0);
  input3.push_back(0.0);
  actual3.push_back(0.0);
  input4.push_back(0.0);
  input4.push_back(1.0);
  input4.push_back(0.0);
  input4.push_back(0.0);
  actual4.push_back(0.0);
  input5.push_back(0.0);
  input5.push_back(1.0);
  input5.push_back(0.0);
  input5.push_back(1.0);
  actual5.push_back(0.0);
  input6.push_back(1.0);
  input6.push_back(1.0);
  input6.push_back(1.0);
  input6.push_back(0.0);
  actual6.push_back(1.0);
  input7.push_back(1.0);
  input7.push_back(1.0);
  input7.push_back(0.5);
  input7.push_back(0.0);
  actual7.push_back(1.0);
  mynet.trainnetwork(input1,actual1);
  mynet.trainnetwork(input2,actual2);
  mynet.trainnetwork(input3,actual3);
  mynet.trainnetwork(input4,actual4);
  mynet.trainnetwork(input6,actual6);
  mynet.trainnetwork(input5,actual5);
  
  vector<double> test1;
  vector<double> test2;
  vector<double> test3;
  test1.push_back(1.0);
  test1.push_back(1.0);
  test1.push_back(1.0);
  test1.push_back(1.0);
  test2.push_back(0.0);
  test2.push_back(0.0);
  test2.push_back(0.0);
  test2.push_back(0.0);
  test3.push_back(1.0);
  test3.push_back(0.0);
  test3.push_back(1.0);
  test3.push_back(0.0);
  vector<double> results1;
  vector<double> results2;
  vector<double> results3;
  results1 = mynet.feedforward(test1);
  results2 = mynet.feedforward(test2);
  results3 = mynet.feedforward(test3);
  if(results1[0] > 0.5){
    cout << "Output Value: " << results1[0] << endl;
    cout << "In the first test the team had home field advantage, better offence, better defense, and had won the previous week." << endl;
    cout << "The neural network predicts that they would - WIN" << endl;
    cout << "\n\n\n" << endl;
  }
  else{
    cout << "Output Value: " << results1[0] << endl;
    cout << "In the first test the team had home field advantage, better offence, better defense, and had won the previous week." << endl;
    cout << "The neural network predicts that they would - LOSE" << endl;
    cout << "\n\n\n" << endl;
  }
  
  if(results2[0] > 0.5){
    cout << "Output Value: " << results2[0] << endl;
    cout << "In the second test the team does not have home field advantage, a worse offense, worse defense, and lost the previous week." << endl;
    cout << "The neural network predicts that they would - WIN" << endl;
    cout << "\n\n\n" << endl;
  }
  else{
    cout << "Output Value: " << results2[0] << endl;
    cout << "In the second test the team does not have home field advantage, has a worse offense, worse defense, and lost the previous week." << endl;
    cout << "The neural network predicts that they would - LOSE" << endl;
    cout << "\n\n\n" << endl;
  }

  if(results3[0] > 0.5){
    cout << "Output Value: " << results3[0] << endl;
    cout << "In the last test the team does has home field advantage, a worse offence, better defense, and lost the previous week." << endl;
    cout << "The neural network predicts that they would - WIN" << endl;
    cout << "\n\n\n" << endl;
  }
  else{
    cout << "Output Value: " << results3[0] << endl;
    cout << "In the last test the team does has home field advantage, a worse offence, better defense, and lost the previous week." << endl;
    cout << "The neural network predicts that they would - LOSE" << endl;
    cout << "\n\n\n" << endl;
  }

  system("PAUSE");
  return 0;
}
