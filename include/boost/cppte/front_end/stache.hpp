/**
 *  \file stache.hpp
 *
 *  Copyright 2014 Michael Caisse
 *
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */
#ifndef BOOST_CPPTE_FRONT_END_STACHE_HPP
#define BOOST_CPPTE_FRONT_END_STACHE_HPP

#include <stache_grammar.hpp>
#include <stache_ast.hpp>

namespace boost { namespace cppte { namespace format
{
   struct stache
   {
      typedef stach::grammar grammar_t;
      typedef stach::skipper skipper_t;
      typedef stach::ast ast_t;
   };
}}}


#endif
