#line 1 "interface.tmpl"
#include "content.h" 
#line 2 "interface.tmpl"
namespace interface {
	#line 3 "interface.tmpl"
	struct architecture :public cppcms::base_view
	#line 3 "interface.tmpl"
	{
	#line 3 "interface.tmpl"
		content::architecture &content;
	#line 3 "interface.tmpl"
		architecture(std::ostream &_s,content::architecture &_content): cppcms::base_view(_s),content(_content)
	#line 3 "interface.tmpl"
		{
	#line 3 "interface.tmpl"
		}
		#line 4 "interface.tmpl"
		virtual void render() {
			#line 16 "interface.tmpl"
			out()<<"\r\n"
				"<html>\r\n"
				"\t<head>\r\n"
				"\t\t<title>Design Your Neural Network</title>\r\n"
				"\t\t<link rel=\"stylesheet\" type=\"text/css\" href=\"/css/default.css\" />\r\n"
				"\t\t<script type=\"text/javascript\" src=\"/js/default.js\"></script>\r\n"
				"\t\t<script src=\"//ajax.googleapis.com/ajax/libs/jquery/1.8.0/jquery.min.js\" type=\"text/javascript\"></script>\r\n"
				"\t</head>\r\n"
				"\t<body>\r\n"
				"\t\t<h1>Design Your Network</h1>\r\n"
				"\t\t<form method=\"post\" action=\"\">\r\n"
				"\t\t      <table>\r\n"
				"\t\t\t";
			#line 16 "interface.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_table); (content.structure).render(_form_context); }
			#line 22 "interface.tmpl"
			out()<<"\r\n"
				"\t\t      </table>\r\n"
				"\t\t</form>\r\n"
				"\t\t<a href=\"/interface/train\">Continue To Training...</a>\r\n"
				"\t</body>\r\n"
				"</html>\r\n"
				"";
		#line 22 "interface.tmpl"
		} // end of template render
	#line 23 "interface.tmpl"
	}; // end of class architecture
	#line 25 "interface.tmpl"
	struct training :public cppcms::base_view
	#line 25 "interface.tmpl"
	{
	#line 25 "interface.tmpl"
		content::training &content;
	#line 25 "interface.tmpl"
		training(std::ostream &_s,content::training &_content): cppcms::base_view(_s),content(_content)
	#line 25 "interface.tmpl"
		{
	#line 25 "interface.tmpl"
		}
		#line 26 "interface.tmpl"
		virtual void render() {
			#line 37 "interface.tmpl"
			out()<<"\r\n"
				"<html>\r\n"
				"\t<head>\r\n"
				"\t\t<title>Train Your Neural Network</title>\r\n"
				"\t\t<link rel=\"stylesheet\" type=\"text/css\" href=\"/css/default.css\" />\r\n"
				"\t\t<script type=\"text/javascript\" src=\"/js/default.js\"></script>\r\n"
				"\t</head>\r\n"
				"\t<body>\r\n"
				"\t\t<h1>Train Your Neural Network</h1>\r\n"
				"\t\t<form method=\"post\" action=\"\">\r\n"
				"\t\t<table>\r\n"
				"\t\t  ";
			#line 37 "interface.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_table); (content.trainer).render(_form_context); }
			#line 41 "interface.tmpl"
			out()<<"\r\n"
				"\t\t</table>\r\n"
				"\t\t</form><br><br>\r\n"
				"\t\t<h2>Results</h2>\r\n"
				"\t\t<p>Output 1: ";
			#line 41 "interface.tmpl"
			out()<<cppcms::filters::escape(content.output1);
			#line 42 "interface.tmpl"
			out()<<"</p>\r\n"
				"\t\t<p>Output 2: ";
			#line 42 "interface.tmpl"
			out()<<cppcms::filters::escape(content.output2);
			#line 43 "interface.tmpl"
			out()<<"</p>\r\n"
				"\t\t<p>Network Error: ";
			#line 43 "interface.tmpl"
			out()<<cppcms::filters::escape(content.error);
			#line 46 "interface.tmpl"
			out()<<"</p>\r\n"
				"\t</body>\r\n"
				"</html>\r\n"
				"";
		#line 46 "interface.tmpl"
		} // end of template render
	#line 47 "interface.tmpl"
	}; // end of class training
#line 49 "interface.tmpl"
} // end of namespace interface
#line 49 "interface.tmpl"
namespace {
#line 49 "interface.tmpl"
 cppcms::views::generator my_generator; 
#line 49 "interface.tmpl"
 struct loader { 
#line 49 "interface.tmpl"
  loader() { 
#line 49 "interface.tmpl"
   my_generator.name("interface");
#line 49 "interface.tmpl"
   my_generator.add_view<interface::architecture,content::architecture>("architecture",true);
#line 49 "interface.tmpl"
   my_generator.add_view<interface::training,content::training>("training",true);
#line 49 "interface.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 49 "interface.tmpl"
 }
#line 49 "interface.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 49 "interface.tmpl"
} a_loader;
#line 49 "interface.tmpl"
} // anon 
