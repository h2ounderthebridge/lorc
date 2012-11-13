#line 1 "training.tmpl"
#include "content.h" 
#line 2 "training.tmpl"
namespace interface {
	#line 3 "training.tmpl"
	struct training :public cppcms::base_view
	#line 3 "training.tmpl"
	{
	#line 3 "training.tmpl"
		content::training &content;
	#line 3 "training.tmpl"
		training(std::ostream &_s,content::training &_content): cppcms::base_view(_s),content(_content)
	#line 3 "training.tmpl"
		{
	#line 3 "training.tmpl"
		}
		#line 4 "training.tmpl"
		virtual void render() {
			#line 13 "training.tmpl"
			out()<<"\r\n"
				"<html>\r\n"
				"\t<head>\r\n"
				"\t\t<title>Train Your Neural Network</title>\r\n"
				"\t\t<link rel=\"stylesheet\" type=\"text/css\" href=\"/css/default.css\" />\r\n"
				"\t\t<script type=\"text/javascript\" src=\"/js/default.js\"></script>\r\n"
				"\t</head>\r\n"
				"\t<body>\r\n"
				"\t\t<h1>Train Your Neural Network</h1>\r\n"
				"\t\t<p>";
			#line 13 "training.tmpl"
			out()<<cppcms::filters::escape(content.numInputs);
			#line 14 "training.tmpl"
			out()<<"</p>\r\n"
				"\t\t<p>";
			#line 14 "training.tmpl"
			out()<<cppcms::filters::escape(content.numHidden);
			#line 15 "training.tmpl"
			out()<<"</p>\r\n"
				"\t\t<p>";
			#line 15 "training.tmpl"
			out()<<cppcms::filters::escape(content.numOutputs);
			#line 18 "training.tmpl"
			out()<<"</p>\r\n"
				"\t</body>\r\n"
				"</html>\r\n"
				"";
		#line 18 "training.tmpl"
		} // end of template render
	#line 19 "training.tmpl"
	}; // end of class training
#line 20 "training.tmpl"
} // end of namespace interface
#line 20 "training.tmpl"
namespace {
#line 20 "training.tmpl"
 cppcms::views::generator my_generator; 
#line 20 "training.tmpl"
 struct loader { 
#line 20 "training.tmpl"
  loader() { 
#line 20 "training.tmpl"
   my_generator.name("interface");
#line 20 "training.tmpl"
   my_generator.add_view<interface::training,content::training>("training",true);
#line 20 "training.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 20 "training.tmpl"
 }
#line 20 "training.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 20 "training.tmpl"
} a_loader;
#line 20 "training.tmpl"
} // anon 
