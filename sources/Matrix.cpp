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
#include <string>
#include <ctype.h>
#include "Matrix.hpp"

void input_check(int rows1,int cols1, int rows2, int cols2){

    if(rows1 != rows2 || cols1!=cols2){
        std::__throw_length_error("matrices are not the same size mxn"); 
    }

}
void input_check_mult(int rows1,int cols1, int rows2, int cols2){
    if(cols1 != rows2){
        std::__throw_length_error("matrices are not the same size mxn"); 
    }
}

/* Ctors */
zich::Matrix::Matrix(){ /* Default is 10x10 */
    const int def = 10;
    _rows = def;
    _columns = def;
    int vec_len = _rows*_columns;
    _vec.resize((unsigned long)vec_len);
}

zich::Matrix::Matrix(std::vector<double> vec, int rows, int column){

    if(rows < 0 || column < 0){
        std:: __throw_invalid_argument("cannot init matrix with negative values");
    }
    if(rows*column != vec.size() ){
        std::__throw_out_of_range("rows,columns does not fit to init the matrix");
    }

    _rows = rows;
    _columns = column;
    int vec_len = _rows*_columns;
    _vec.resize((unsigned long)vec_len);
    std::string::size_type i = 0;
    std::string Vec_check;
    for(i = 0; i<vec_len; ++i){ /* Adds the data from the ctor vector*/
        _vec.at(i) = vec.at(i);
    }
}

zich::Matrix zich::Matrix::operator+(const zich::Matrix &Mat2){

    input_check(_rows,_columns,Mat2._rows,Mat2._columns);

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    std::string::size_type i = 0;

    Matrix new_mat(_vec,_rows,_columns); /* new object */

    for(i = 0; i<vec_len; ++i){ /* Adds the data from the mat2 vector to the curr vector */
        new_mat._vec.at(i) += Mat2._vec.at(i);
    }
    return new_mat; /* returns the new Matrix */
}

zich::Matrix zich::Matrix::operator+=(const zich::Matrix &Mat2){

    input_check(_rows,_columns,Mat2._rows,Mat2._columns);

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    std::string::size_type i = 0;

    for(i = 0; i<vec_len; ++i){ /* Adds the data from the mat2 vector to the curr vector */
        _vec.at(i) += Mat2._vec.at(i);
    }
    return *this; /* returns the current Matrix */

}

zich::Matrix zich::Matrix::operator+(){
    return Matrix(_vec,_rows,_columns); // MAYBE *this?
}

zich::Matrix zich::Matrix::operator-(const zich::Matrix &Mat2){

    input_check(_rows,_columns,Mat2._rows,Mat2._columns);

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    std::string::size_type i = 0;
    
    Matrix new_mat(_vec,_rows,_columns); /* new object */

    for(i = 0; i<vec_len; ++i){ /* Adds the data from the mat2 vector to the curr vector */
        new_mat._vec.at(i) -= Mat2._vec.at(i);
    }

    return new_mat; /* returns the new Matrix */

}

zich::Matrix zich::Matrix::operator-=(const zich::Matrix &Mat2){

    input_check(_rows,_columns,Mat2._rows,Mat2._columns);

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    std::string::size_type i = 0;

    for(i = 0; i<vec_len; ++i){ /* Adds the data from the mat2 vector to the curr vector */
        _vec.at(i) -= Mat2._vec.at(i);
    }

    return *this; /* returns the current Matrix */
}

zich::Matrix zich::Matrix::operator-(){

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    std::string::size_type i = 0;

    Matrix new_mat(_vec,_rows,_columns); /* new object */

    for(i = 0; i<vec_len; ++i){ /* replaces the sign from + to minus */
        new_mat._vec.at(i) = -(new_mat._vec.at(i));
    }
    return new_mat;
}

bool zich::Matrix::operator> (const zich::Matrix &Mat2)const{

    input_check(_rows,_columns,Mat2._rows,Mat2._columns);

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    double sum_Mat1 = 0;
    double sum_Mat2 = 0;
    std::string::size_type i = 0;

    for(i = 0; i<vec_len; ++i){  /*sums the size of each vector */
        sum_Mat1 += _vec.at(i);
        sum_Mat2 += Mat2._vec.at(i);
    }
    /* i check this because its greather than, not equal */
    return sum_Mat1>sum_Mat2;
}

bool zich::Matrix::operator>= (const zich::Matrix &Mat2)const{

    input_check(_rows,_columns,Mat2._rows,Mat2._columns);

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    double sum_Mat1 = 0;
    double sum_Mat2 = 0;
    std::string::size_type i = 0;

    for(i = 0; i<vec_len; ++i){  /*sums the size of each vector */
        sum_Mat1 += _vec.at(i);
        sum_Mat2 += Mat2._vec.at(i);
    }
    /* i check this because its greather than, not equal */
    return sum_Mat1 >= sum_Mat2;
}

bool zich::Matrix::operator< (const zich::Matrix &Mat2)const{

    input_check(_rows,_columns,Mat2._rows,Mat2._columns);

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    double sum_Mat1 = 0;
    double sum_Mat2 = 0;
    std::string::size_type i = 0;

    for(i = 0; i<vec_len; ++i){  /*sums the size of each vector */
        sum_Mat1 += _vec.at(i);
        sum_Mat2 += Mat2._vec.at(i);
    }
    /* i check this because its greather than, not equal */
    return sum_Mat2 > sum_Mat1;
    
}

bool zich::Matrix::operator<= (const zich::Matrix &Mat2)const{

    input_check(_rows,_columns,Mat2._rows,Mat2._columns);

    int vec_len = _rows*_columns; /* Size of vector >> 5x5 = 25 */
    double sum_Mat1 = 0;
    double sum_Mat2 = 0;
    std::string::size_type i = 0;

    for(i = 0; i<vec_len; ++i){  /*sums the size of each vector */
        sum_Mat1 += _vec.at(i);
        sum_Mat2 += Mat2._vec.at(i);
    }
    /* i check this because its greather than, not equal */
    return sum_Mat2 >= sum_Mat1;
}

bool zich::Matrix::operator== (const zich::Matrix &Mat2)const{
    
    input_check(_rows,_columns,Mat2._rows,Mat2._columns);

    int vec_len = _rows*_columns;
    std::string::size_type i = 0;

    for(i = 0; i<vec_len; ++i){ /* checks if all the variables are equal or not */
        if(_vec.at(i)!= Mat2._vec.at(i)){
            return false;
        }
    }
    return true;
}

bool zich::Matrix::operator!= (const zich::Matrix &Mat2)const{

    input_check(_rows,_columns,Mat2._rows,Mat2._columns);

    int vec_len = _rows*_columns;
    std::string::size_type i = 0;

    for(i = 0; i<vec_len; ++i){ /* checks if all the variables are equal or not */
        if(_vec.at(i)!= Mat2._vec.at(i)){
            return true;
        }
    }
    return false;
}

zich::Matrix& zich::Matrix::operator++(){ /*prefix*/
   
   int vec_len = _rows*_columns;
   std::string::size_type i = 0;

   for(i = 0; i<vec_len ; i++){
       ++(_vec.at(i));
   }
   return *this;

}

zich::Matrix zich::Matrix::operator++(int){ /*postfix*/

    int vec_len = _rows*_columns;
    std::string::size_type i = 0;
    Matrix new_mat = *this;
    
   for(i = 0; i<vec_len ; i++){
        (_vec.at(i))++;
   }
   return new_mat;

}

zich::Matrix& zich::Matrix::operator--() { /*prefix*/

    int vec_len = _rows*_columns;
    std::string::size_type i = 0;

    for(i = 0; i<vec_len ; i++){
       --(_vec.at(i));
    }
    return *this;
}

zich::Matrix zich::Matrix::operator--(int){ /*postfix*/

    int vec_len = _rows*_columns;
    std::string::size_type i = 0;
    Matrix new_mat = *this;

    for(i = 0; i<vec_len ; i++){
       (_vec.at(i))--;
    }
    return new_mat;
}

zich::Matrix zich::Matrix::operator* (double scalar){

    int vec_len = _rows*_columns;
    std::string::size_type i = 0 ;

    Matrix new_mat(_vec,_rows,_columns); /*creates a copy of the current matrix */

    for(i = 0; i<vec_len; ++i){ /* checks if all the variables are equal or not */
        new_mat._vec.at(i) *= scalar;
    }

    return new_mat; /*returns the new mat */
    
}

zich::Matrix zich::Matrix::operator*= (double scalar){
    
    int vec_len = _rows*_columns;
    std::string::size_type i = 0 ;

    for(i = 0; i<vec_len; ++i){ /* checks if all the variables are equal or not */
        _vec.at(i) *= scalar;
    }

    return *this;
}

zich::Matrix zich::operator*(double scalar, zich::Matrix &Mat){
    
    int vec_len = Mat._rows*Mat._columns;
    std::string::size_type i = 0;
    
    Matrix new_mat(Mat._vec, Mat._rows, Mat._columns);

    for(i = 0; i<vec_len; ++i){ /* multiplies every variable */
        new_mat._vec.at(i) *= scalar;
    }
    return new_mat;
}

zich::Matrix zich::Matrix::operator* (const zich::Matrix &Mat2){

    input_check_mult(_rows,_columns,Mat2._rows,Mat2._columns);

    std::string::size_type i = 0;
    std::string::size_type j = 0;
    std::string::size_type k = 0;
    std::string::size_type bounds = 0;
/***********************************************************************/
/*Temporary matrixes convertion*/

    /* i create here matrix _rows*Mat2.columns bcz its hard to calcualte matrix mult on vector<double> */
    std::vector<std::vector<double>> matrix; 
    matrix.resize((unsigned int)_rows, std::vector<double>((unsigned int)Mat2._columns, 0));

    std::vector<std::vector<double>> this_matrix;
    this_matrix.resize((unsigned int)_rows, std::vector<double>((unsigned int)_columns, 0));

    for(i = 0; i<_rows; ++i){
        for(j = 0; j<_columns; ++j){
            this_matrix.at(i).at(j) = _vec.at(bounds);
            ++bounds;
        }
    }

    bounds = 0;
    std::vector<std::vector<double>> other_matrix;
    other_matrix.resize((unsigned int)Mat2._rows, std::vector<double>((unsigned int)Mat2._columns, 0));

    for(i = 0; i<Mat2._rows; ++i){
        for(j = 0; j<Mat2._columns; ++j){
            other_matrix.at(i).at(j) = Mat2._vec.at(bounds);
            ++bounds;
        }
    }
/*******************************************************************************/
    for(i = 0; i< _rows; ++i){
        for(j = 0; j<Mat2._columns; ++j){
            for(k = 0; k<_columns; ++k){
                matrix.at(i).at(j) += this_matrix.at(i).at(k) * other_matrix.at(k).at(j);
            }
        }
    }

    bounds = 0;
    std::vector<double>new_vec((unsigned int)(_rows*Mat2._columns),0);
    Matrix new_mat(new_vec,_rows,Mat2._columns);

    for(i = 0; i<_rows; ++i){
        for(j = 0; j<Mat2._columns; ++j){
            new_mat._vec.at(bounds) = matrix.at(i).at(j);
            ++bounds;
        }
    }

    return new_mat;
    
}

zich::Matrix zich::Matrix::operator*= (const zich::Matrix &Mat2){

    input_check_mult(_rows,_columns,Mat2._rows,Mat2._columns);
    std::string::size_type i = 0;
    std::string::size_type j = 0;
    std::string::size_type k = 0;
    std::string::size_type bounds = 0;
/***********************************************************************/
/*Temporary matrixes convertion*/

    /* i create here matrix _rows*Mat2.columns bcz its hard to calcualte matrix mult on vector<double> */
    std::vector<std::vector<double>> matrix; 
    matrix.resize((unsigned int)_rows, std::vector<double>((unsigned int)Mat2._columns, 0));

    std::vector<std::vector<double>> this_matrix;
    this_matrix.resize((unsigned int)_rows, std::vector<double>((unsigned int)_columns, 0));

    for(i = 0; i<_rows; ++i){
        for(j = 0; j<_columns; ++j){
            this_matrix.at(i).at(j) = _vec.at(bounds);
            ++bounds;
        }
    }

    bounds = 0;
    std::vector<std::vector<double>> other_matrix;
    other_matrix.resize((unsigned int)Mat2._rows, std::vector<double>((unsigned int)Mat2._columns, 0));

    for(i = 0; i<Mat2._rows; ++i){
        for(j = 0; j<Mat2._columns; ++j){
            other_matrix.at(i).at(j) = Mat2._vec.at(bounds);
            ++bounds;
        }
    }
/*******************************************************************************/
    for(i = 0; i< _rows; ++i){
        for(j = 0; j<Mat2._columns; ++j){
            for(k = 0; k<_columns; ++k){
                matrix.at(i).at(j) += this_matrix.at(i).at(k) * other_matrix.at(k).at(j);
            }
        }
    }

    bounds = 0;
    this->_vec.resize((unsigned int)(_rows*Mat2._columns),0); /*updates the this_vec */
    this->_columns = Mat2._columns;

    for(i = 0; i<_rows; ++i){
        for(j = 0; j<Mat2._columns; ++j){
            _vec.at(bounds) = matrix.at(i).at(j);
            ++bounds;
        }
    }

    return *this;
    
}


std::ostream& zich::operator<<(std::ostream& output, const zich::Matrix& Mat){

    int i = 0;
    int j = 0;
    std::string::size_type  bounds = 0;
    std::string matrix;
    for( i = 0; i<Mat._rows; ++i){
        output << '[';
        for(j = 0; j<Mat._columns; ++j){
            if(Mat._vec.at(bounds) == 0){ /* Avoids -0 case */
                output << 0; 
            }
            else{
                output << Mat._vec.at(bounds);
            }
            ++bounds;
            if(j <Mat._columns -1){ // this is to make sure there is no space in the last place.
                output << ' ';
            }
        }
        output << ']';
        if(i<Mat._rows-1){ // this is to make sure there is no \n in the last place.
            output << '\n';
        }

    }
    return output;
}

std::istream& zich::operator>>(std::istream& is, zich::Matrix& Mat){
    
    /*istringstream is7{"[1 1 1 1], [1 1 1 1], [1 1 1 1]\n"};*/
    
    std::string input;
    getline(is,input);
    size_t i = 0;
    int rows = 0;
    int columns = 0;
    int tmp_columns = 0;
    int brackets = 0; /* for brackets balance */
    size_t z = 0;
    /*Input check*/
    if(input[0]!= '['){
        std::__throw_invalid_argument("idx 0 is only [ ");
    }
    for(i = 0; i<input.length(); ++i){
        if(input[i]== '['){
            brackets ++;
            tmp_columns = 0;
            z = 0;
            while(input[z]!=']'){
                tmp_columns++;
                z++;
            }
            tmp_columns/=2;
            if(tmp_columns != columns && columns!=0){
                std::__throw_invalid_argument("Columns does not match");
            }
            else{columns = tmp_columns;}
        } 
        if(input[i]==']'){
            brackets--;
            if(i == input.length()-1){
                rows++;
            }
            else if(input[i+1]==',' && input[i+2]==' '){
                ++rows;
            }else{
                std::__throw_invalid_argument("Bad input");
            }
        }
    }
    if(brackets!=0){
        std::__throw_invalid_argument("Bad input,brackets are not equal");
    }
    
    int const ten = 10;

    std::vector<double> new_vec((unsigned int)(rows*columns));
    z = 0; /*vector bounds */
    size_t x = 0; /*iterator for inside loop*/
    double str_to_double = 0;
    for(i =0 ; i< input.length(); ++i){
        if(isdigit(input[i])!=0){
            str_to_double = input[i] -'0';
            x = i+1;
            while((input[x]!=' ' && input[x]!=']') && x<input.length()){   /* if there's a number larger than one digit */
                str_to_double *= (ten);
                str_to_double += input[x] - '0';
                ++x;
            }
            i = x; /*returns i to be the x-1 in case it was moved */
            std::cout<< str_to_double <<", ";
            new_vec.at(z) = str_to_double;
            ++z;
        } 
        else{/*Skip non number values */
                continue;
            }
        
    }
    std::cout<< std::endl;
    Mat._vec = new_vec;
    Mat._rows = rows;
    Mat._columns = columns;

    return is;
}