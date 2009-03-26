#ifdef TestCode
#define BOOST_TEST_INCLUDE
#include <boost/test/unit_test.hpp>
#include <iostream>
//#include "../MouseActionParser.h"
//#include "../ActionParserHandle.h"

using namespace boost;

BOOST_AUTO_TEST_SUITE(parse)

BOOST_AUTO_TEST_CASE(mAParser)
{
    std::cout<<"234"<<std::endl;
    BOOST_CHECK_EQUAL(1,2);
  //  ActionParserHandle * handle = ActionParserHandle::getInstance();
  //  BOOST_CHECK_GT(handle, (void*)0);
  //  ActionParser* parser = handle->getActionParser(MouseActionParser::deviceType);
  //  BOOST_CHECK_EQUAL(parser, &mouseActionParser);
}

BOOST_AUTO_TEST_SUITE_END()
#endif
