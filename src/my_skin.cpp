#line 1 "my_skin.tmpl"
#include "content.h" 
#line 2 "my_skin.tmpl"
namespace my_skin {
	#line 3 "my_skin.tmpl"
	struct data :public cppcms::base_view
	#line 3 "my_skin.tmpl"
	{
	#line 3 "my_skin.tmpl"
		content::data &content;
	#line 3 "my_skin.tmpl"
		data(std::ostream &_s,content::data &_content): cppcms::base_view(_s),content(_content)
	#line 3 "my_skin.tmpl"
		{
	#line 3 "my_skin.tmpl"
		}
		#line 4 "my_skin.tmpl"
		virtual void render() {
			#line 14 "my_skin.tmpl"
			out()<<"\r\n"
				"<html>\r\n"
				"\t<title>Test Applicatin</title>\r\n"
				"\t<head>\r\n"
				"\t\t<link rel=\"stylesheet\" type=\"text/css\" href=\"/css/default.css\" />\r\n"
				"\t</head>\r\n"
				"\t<body>\r\n"
				"\t\t<h1>Please answer the following questions</h1>\r\n"
				"\t\t<form method=\"post\" action=\"\">\r\n"
				"\t\t<table>\r\n"
				"\t\t";
			#line 14 "my_skin.tmpl"
			{ cppcms::form_context _form_context(out(),cppcms::form_flags::as_html,cppcms::form_flags::as_table); (content.info).render(_form_context); }
			#line 17 "my_skin.tmpl"
			out()<<"\r\n"
				"\t\t</table>\r\n"
				"\t\t</form>\r\n"
				"\t\t";
			#line 17 "my_skin.tmpl"
			if(content.results) {
				#line 18 "my_skin.tmpl"
				out()<<"\r\n"
					"\t\t   <h1>Output: ";
				#line 18 "my_skin.tmpl"
				out()<<cppcms::filters::escape(content.results);
				#line 19 "my_skin.tmpl"
				out()<<"</h1>\r\n"
					"\t\t";
			#line 19 "my_skin.tmpl"
			}else{
				#line 21 "my_skin.tmpl"
				out()<<"\r\n"
					"\t\t   <p>You have not answered the questions</p>\r\n"
					"\t\t";
			#line 21 "my_skin.tmpl"
			}
			#line 24 "my_skin.tmpl"
			out()<<"   \r\n"
				"\t</body>\r\n"
				"</html>\r\n"
				"";
		#line 24 "my_skin.tmpl"
		} // end of template render
	#line 25 "my_skin.tmpl"
	}; // end of class data
#line 26 "my_skin.tmpl"
} // end of namespace my_skin
#line 27 "my_skin.tmpl"
namespace {
#line 27 "my_skin.tmpl"
 cppcms::views::generator my_generator; 
#line 27 "my_skin.tmpl"
 struct loader { 
#line 27 "my_skin.tmpl"
  loader() { 
#line 27 "my_skin.tmpl"
   my_generator.name("my_skin");
#line 27 "my_skin.tmpl"
   my_generator.add_view<my_skin::data,content::data>("data",true);
#line 27 "my_skin.tmpl"
    cppcms::views::pool::instance().add(my_generator);
#line 27 "my_skin.tmpl"
 }
#line 27 "my_skin.tmpl"
 ~loader() {  cppcms::views::pool::instance().remove(my_generator); }
#line 27 "my_skin.tmpl"
} a_loader;
#line 27 "my_skin.tmpl"
} // anon 
