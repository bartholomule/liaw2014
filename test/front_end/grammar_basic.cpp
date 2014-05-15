#include <boost/spirit/include/qi.hpp>
#include <boost/cppte/front_end/stache_ast.hpp>
#include <boost/cppte/front_end/stache_grammar_def.hpp>
#include <iostream>


namespace fe = boost::cppte::front_end;
namespace qi = boost::spirit::qi;

int main()
{
   using fe::stache_skipper;

   typedef std::string::iterator iterator_t;
   typedef fe::stache_grammar<iterator_t> grammar_t;

   fe::ast::stache_root ast;
   grammar_t grammar;

   std::string input( "Hello world "
                      "{{name}} is here." );

   iterator_t iter = input.begin();
   iterator_t iter_end = input.end();

   if( qi::phrase_parse( iter, iter_end
                       , grammar
                       , stache_skipper<iterator_t>()
                       , ast) )
   {
      std::cout << "parse succeeded" << std::endl;
   }
   else
   {
      std::cout << "parse failed" << std::endl;
   }
}

