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
#include "Interface.h"

using namespace std;

int main(int argc, char** argv)
{
try {
  cppcms::service srv(argc,argv);
  srv.applications_pool().mount(cppcms::applications_factory<interface>());
  srv.run();
 }
 catch(std::exception const &e) {
   std::cerr << e.what() << std::endl;
 }
}
