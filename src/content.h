#include <cppcms/view.h>
#include <cppcms/form.h>
#include <string>

namespace content {
  struct design_form : public cppcms::form {
    cppcms::widgets::text numInputs;
    cppcms::widgets::text numHidden;
    cppcms::widgets::text numOutputs;
    cppcms::widgets::submit submit;

    design_form(){
      numInputs.message("Number of inputs");
      numHidden.message("Number of hidden neurons");
      numOutputs.message("Number of outputs");
      numInputs.size(4);
      numHidden.size(4);
      numOutputs.size(4);
      submit.value("Create Network");
      add(numInputs);
      add(numHidden);
      add(numOutputs);
      add(submit);
    }
  };

  struct train_form : public cppcms::form {
    cppcms::widgets::text input1;
    cppcms::widgets::text input2;
    cppcms::widgets::text input3;
    cppcms::widgets::text input4;
    cppcms::widgets::text actual1;
    cppcms::widgets::text actual2;
    cppcms::widgets::submit submit;

    train_form(){
      input1.size(4);
      input2.size(4);
      input3.size(4);
      input4.size(4);
      actual1.message("Acutal Output 1");
      actual2.message("Actual Output 2");
      actual1.size(4);
      actual2.size(4);
      submit.value("Train Network");
      add(input1);
      add(input2);
      add(input3);
      add(input4);
      add(actual1);
      add(actual2);
      add(submit);
    }
  };

  struct architecture : public cppcms::base_content {
    design_form structure;
  };

  struct training : public cppcms::base_content {
    train_form trainer;
    double output1;
    double output2;
    double error;
  };
}
