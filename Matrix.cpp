/**
 * @file Matrix.cpp
 * @author shaked levi
 * @brief This is the implemntation for the header file Matrix.hpp
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include "Matrix.hpp"

/* Ctors */
zich::Matrix::Matrix(){ /* Default is 10x10 */
    std::vector<std::vector<double>>_mat(10,std::vector<double>(10));
}

zich::Matrix::Matrix(std::vector<double> vec, unsigned long rows, unsigned long column){
    std::vector<std::vector<double>> _mat(rows,std::vector<double>(column)); /*Make this better */
}

zich::Matrix zich::Matrix::operator+(const zich::Matrix &Mat2){

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */

    for(int i = 0; i<vec_len; ++i){ /* Adds the data from the mat2 vector to the curr vector */
        _vec.at(i) += Mat2._vec.at(i);
    }

    return Matrix(_vec,_rows,_columns); /* Creates the new Matrix */
}

// zich::Matrix zich::Matrix::operator+=(const zich::Matrix &Mat2){
//   return Mat2;
// }

// zich::Matrix zich::Matrix::operator+(){
//     return Matrix();
// }

zich::Matrix zich::Matrix::operator-(const zich::Matrix &Mat2){

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */

    for(int i = 0; i<vec_len; ++i){ /* Adds the data from the mat2 vector to the curr vector */
        _vec.at(i) -= Mat2._vec.at(i);
    }

    return Matrix(_vec,_rows,_columns); /* Creates the new Matrix */

}

// zich::Matrix zich::Matrix::operator-=(const zich::Matrix &Mat2){
//     return Mat2;
// }

// zich::Matrix zich::Matrix::operator-(){
//     return Matrix();
// }

bool zich::Matrix::operator> (const zich::Matrix &Mat2)const{

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    int sum_Mat1 = 0;
    int sum_Mat2 = 0;

    for(int i = 0; i<vec_len; ++i){  /*sums the size of each vector */
        sum_Mat1 += _vec.at(i);
        sum_Mat2 += Mat2._vec.at(i);
    }
    /* i check this because its greather than, not equal */
    if( sum_Mat1 > sum_Mat2){
        return true; 
    }else{
        return false;
    }
}

bool zich::Matrix::operator>= (const zich::Matrix &Mat2)const{

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    int sum_Mat1 = 0;
    int sum_Mat2 = 0;

    for(int i = 0; i<vec_len; ++i){  /*sums the size of each vector */
        sum_Mat1 += _vec.at(i);
        sum_Mat2 += Mat2._vec.at(i);
    }
    /* i check this because its greather than, not equal */
    if( sum_Mat1 >= sum_Mat2){
        return true; 
    }else{
        return false;
    }
}

bool zich::Matrix::operator< (const zich::Matrix &Mat2)const{

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    int sum_Mat1 = 0;
    int sum_Mat2 = 0;

    for(int i = 0; i<vec_len; ++i){  /*sums the size of each vector */
        sum_Mat1 += _vec.at(i);
        sum_Mat2 += Mat2._vec.at(i);
    }
    /* i check this because its greather than, not equal */
    if( sum_Mat2 > sum_Mat1){
        return true; 
    }else{
        return false;
    }
}

bool zich::Matrix::operator<= (const zich::Matrix &Mat2)const{

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    int sum_Mat1 = 0;
    int sum_Mat2 = 0;

    for(int i = 0; i<vec_len; ++i){  /*sums the size of each vector */
        sum_Mat1 += _vec.at(i);
        sum_Mat2 += Mat2._vec.at(i);
    }
    /* i check this because its greather than, not equal */
    if( sum_Mat1 <= sum_Mat2){
        return true; 
    }else{
        return false;
    }
}

bool zich::Matrix::operator== (const zich::Matrix &Mat2)const{
    
    int vec_len = _rows*_columns;

    for(int i = 0; i<vec_len; ++i){ /* checks if all the variables are equal or not */
        if(_vec.at(i)!= Mat2._vec.at(i)){
            return false;
        }
    }
    return true;
}

bool zich::Matrix::operator!= (const zich::Matrix &Mat2)const{

    int vec_len = _rows*_columns;

    for(int i = 0; i<vec_len; ++i){ /* checks if all the variables are equal or not */
        if(_vec.at(i)!= Mat2._vec.at(i)){
            return true;
        }
    }
    return false;
}

// zich::Matrix& zich::Matrix::operator++(){
//     return _mat;
// }

const zich::Matrix zich::Matrix::operator++(int){
    return Matrix();
}

// zich::Matrix& zich::Matrix::operator--() {
//     return _mat;
// }

const zich::Matrix zich::Matrix::operator--(int){
    return Matrix();
}

zich::Matrix zich::Matrix::operator* (double scalar){

    int vec_len = _rows*_columns;

    for(int i = 0; i<vec_len; ++i){ /* checks if all the variables are equal or not */
        _vec.at(i) *= scalar;
    }

    return Matrix(_vec,_rows,_columns);
    
}

// zich::Matrix zich::Matrix::operator*= (double scalar){
//     return Matrix();
// }

zich::Matrix zich::operator*(double scalar, zich::Matrix &Mat){

    int vec_len = Mat._rows*Mat._columns;

    for(int i = 0; i<vec_len; ++i){ /* multiplies every variable */
        Mat._vec.at(i) *= scalar;
    }
    return Mat;
}

// zich::Matrix zich::Matrix::operator* (const zich::Matrix &Mat2){
//     return Mat2;
// }

// zich::Matrix zich::Matrix::operator*= (const zich::Matrix &Mat2){
//     return Mat2;
// }


std::ostream& zich::operator<<(std::ostream& os, const zich::Matrix& Mat){
    return os;
}

std::istream& zich::operator>>(std::istream& is, zich::Matrix& Mat){
    return is;
}