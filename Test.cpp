/**
 * @file Test.cpp
 * @author shaked levi
 * @brief This is a tests file for the Notebook project.
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "doctest.h"
#include "Matrix.hpp"

#include <string>
#include <algorithm>

using namespace zich;


TEST_CASE("Negative Input") {
    Matrix mat;
    std::vector<double> test_v(10);
    
    CHECK_THROWS(Matrix mat(test_v, -10,-20));

}
// This might be not right >> check those tests
TEST_CASE("Override Input"){
	
}

TEST_CASE("Bad characters"){
	
}
