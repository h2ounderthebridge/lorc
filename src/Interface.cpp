#include "Interface.h"
#include "content.h"
#include "Network.h"
#include <iostream>
#include <cppcms/service.h>
#include <cppcms/json.h>
#include <cppcms/http_response.h>
#include <cppcms/url_dispatcher.h>
#include <cppcms/url_mapper.h>

using namespace std;

interface::interface(cppcms::service &srv) : cppcms::application(srv)
{
  dispatcher().assign("/train",&interface::train,this);
  mapper().assign("train","/train");
  
  dispatcher().assign("/train/json",&interface::jtrain,this);
  mapper().assign("jtrain","/train/json");

  dispatcher().assign("/classify",&interface::classify,this);
  mapper().assign("classify","/classify");

  dispatcher().assign("",&interface::create,this);
  mapper().assign("");

  mapper().root("/interface");
}

void interface::create()
{
  content::architecture c;
  if(request().request_method()=="POST"){
    response().out() << request().post("message");
  }
  else{
    render("architecture",c);
  }
}

void interface::train()
{
  response().out() << "Hello";
}

void interface::jtrain()
{
  response().out() << "Hello";
}

void interface::classify()
{
  response().out() << "Hello";
}
    
      
  
