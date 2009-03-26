#ifdef TestCode
#include <boost/test/minimal.hpp>
#include <iostream>

int test_main(int argc, char * argv[]){
    using namespace boost;
    BOOST_REQUIRE(1 == 1);
    std::cout<<"df";
    return 0; 
}
#endif
