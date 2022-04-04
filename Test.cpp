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

std::vector<double> vec1 = {1, 0, 0, 0, 1, 0, 0, 0, 1}; /*a*/
std::vector<double> vec2 = {3, 0, 0, 0, 3, 0, 0, 0, 3}; /*b*/
std::vector<double> vec3 = {-1, 0, 0, 0, -1, 0, 0, 0, -1}; /*c*/
std::vector<double> vec4 = {4, 0, 0, 0, 4, 0, 0, 0, 4}; /*d*/
std ::vector<double> vec5 = {-3,0,0,0,-3,0,0,0,-3}; /*e*/
Matrix a{vec1,3,3};
Matrix b{vec2,3,3};
Matrix c{vec3,3,3};
Matrix d{vec4,3,3};
Matrix e{vec5,3,3};
std ::vector<double> vec6 = {-1,0,0,
                            0,-1,0,
                            0,0,-1,
                            0,0,0}; /*e*/
Matrix f{vec6,4,3};


TEST_CASE("Good Input"){

    CHECK(((-a) == c)); 
    CHECK((a*3) == b);
    CHECK((a+b) == d);
    CHECK((-c)*3 == b);
    CHECK((3*b)==(-e)*3);
    CHECK((b*c)==e);
    CHECK(a<b);
    CHECK((-a)<=c);
    CHECK((e)!=(-e));
    CHECK(a==a);
    CHECK(b>a);

}

TEST_CASE("Negative Input") {

    CHECK_THROWS(Matrix mat(vec1, -1,-1));
    CHECK_THROWS(Matrix mat(vec1, -3,-3));
    
}

TEST_CASE("Out of bounds"){

    CHECK_THROWS(Matrix mat(vec5, 10,10));
    CHECK_THROWS(a-f); /*are not the same size of matrix */
    CHECK_THROWS((-a*f)); /* Cannot multiply this*/
    CHECK_THROWS(a+f); /* Not same size nXm*/
}

TEST_CASE("Bad characters"){

	CHECK_THROWS(Matrix mat(vec1,'5','6'));
    CHECK_THROWS(Matrix mat(vec1,'3','3'));
    CHECK_THROWS(Matrix mat(vec1,'a','b'));

}
