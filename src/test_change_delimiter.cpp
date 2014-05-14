#include <string>
#include <map>
#include <iostream>
#include <fstream>
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>


#include "test_template_fixture.hpp"
#include "gmock_to_boost.hpp"

using namespace liaw2014;
using namespace std;

struct ChangeDelimiterTest : public TemplateFixture
{
	ChangeDelimiterTest()
	{
		template_string = "Hi I am {{name}}.\n";
		template_string += "{{=<\% \%>=}}";
		template_string += "I like <\%pet\%>.";

		set_tag_value("name", "Daniel");
		set_tag_value("pet", "turtles");
		generate_template();
	}

	~ChangeDelimiterTest()
	{
	}
};

// Tests that a simple mustache tag is replaced
TEST_F(ChangeDelimiterTest, TestChangeDelimiterFromString)
{
	std::string expected = "Hi I am Daniel.\n";
	expected += "I like turtles.";
	EXPECT_EQ(expected, result);
}