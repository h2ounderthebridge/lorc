#include <cppcms/application.h>
#include <cppcms/service.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>
#include <cppcms/applications_pool.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <vector>
#include <stdlib.h>
#include "content.h"
#include "Neuron.h"
#include "Network.h"
#include "Layer.h"

using namespace std;

class hello : public cppcms::application {
public:
  hello(cppcms::service &srv):
    cppcms::application(srv)
  {
    dispatcher().assign("/classifier",&hello::classifier,this);
    mapper().assign("classifier","/classifier");

    dispatcher().assign("",&hello::welcome,this);
    mapper().assign("");

    mapper().root("/hello");
  }

  void welcome(){
    response().out() << "<a href='" << url("/classifier") << "'>Classifier</a>";
  }
  
  void classifier(){
    content::data c;
    if(request().request_method()=="POST") {
      c.info.load(context());
      double i1;
      double i2;
      double i3;
      double i4;
      if(c.info.input1.selected_id() == "Yes"){
	i1 = 1.0;
      }
      else{
	i1 = 0.0;
      }

      if(c.info.input2.selected_id() == "Yes"){
	i2 = 1.0;
      }
      else{
	i2 = 0.0;
      }
      
      if(c.info.input3.selected_id() == "Yes"){
	i3 = 1.0;
      }
      else{
	i3 = 0.0;
      }

      if(c.info.input4.selected_id() == "Yes"){
	i4 = 1.0;
      }
      else{
	i4 = 0.0;
      }

      vector<unsigned> arch;
      vector<double> inputs;
      vector<double> outputs;
      arch.push_back(4);
      arch.push_back(4);
      arch.push_back(1);
      inputs.push_back(i1);
      inputs.push_back(i2);
      inputs.push_back(i3);
      inputs.push_back(i4);
      Network mynet(arch,0.8);
      outputs = mynet.feedforward(inputs);
      c.results = outputs[0];
      c.info.clear();
    }
    render("data",c);
  }
    
  
};

int main(int argc,char ** argv)
{
  try {
    cppcms::service srv(argc,argv);
    srv.applications_pool().mount(cppcms::applications_factory<hello>());
    srv.run();
  }
  catch(std::exception const &e) {
    std::cerr << e.what() << std::endl;
  }
}
