/**
 * @file Matrix.hpp
 * @author shaked levi
 * @brief This is header file for matrix class
 * @version 0.1
 * @date 2022-04-01
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <iostream>
#include <vector>


namespace zich{

    class Matrix{

        private:
        
        int _rows;
        int _columns;
        std::vector<double> _vec;

        public:
        
        Matrix(); /* Default ctor */
        Matrix(std::vector<double> vec, int rows, int columns); /* Manual ctor */

        /* Arithmetic Operators */
        /* ---------------------------------------------------------- */
        
        /* PLUS */
        /**
         * @brief overloading the plus operator to support addition of matrixes.
         * 
         * @param Mat2 
         * @return Matrix 
         */
        Matrix operator+ (const Matrix &Mat2);
        /**
         * @brief overloading the += operator to support addition of matrixes in the same manner as above.
         * just in a prettier way.
         * 
         * @param Mat2 
         * @return Matrix 
         */
        Matrix operator+= (const Matrix &Mat2);
        /**
         * @brief Unary plus overloading.
         * 
         * @return Matrix 
         */
        Matrix operator+ ();
        
        /* MINUS */
        /**
         * @brief overloading the minus operator to support subtriction of matrixes.
         * 
         * @param Mat2 
         * @return Matrix 
         */
        Matrix operator-(const Matrix &Mat2);
        /**
         * @brief overloading the -= operator to support subtriction of matrixes in the same manner as above.
         * just in a prettier way.
         * 
         * @param Mat2 
         * @return Matrix 
         */
        Matrix operator-= (const Matrix &Mat2);
        /**
         * @brief Unary minus overloading.
         * 
         * @return Matrix 
         */
        Matrix operator- ();

        /* ---------------------------------------------------------- */

        /* Comparison Operators */
        /* ---------------------------------------------------------- */

        /**
         * @brief overloads the '>' operator to support equality between matrices.
         * equality is given upon the sum of the entire varialbes.
         * @param Mat2 
         * @return true our_mat > mat2
         * @return false our_mat < mat2
         */
        bool operator> (const Matrix &Mat2) const;

        /**
         * @brief Overloads the '>=' operator to support equality check between matrices.
         * equality is given upon the sum of the entire varialbes.
         * @param Mat2 
         * @return true our_mat >= mat2
         * @return false our_mat < mat2
         */
        bool operator>= (const Matrix &Mat2) const;

        /**
         * @brief overloads the '<' operator to support equality between matrices.
         * equality is given upon the sum of the entire varialbes.
         * @param Mat2 
         * @return true our_mat < mat2
         * @return false our_mat > mat2
         */
        bool operator< (const Matrix &Mat2) const;

        /**
         * @brief Overloads the '<=' operator to support equality check between matrices.
         * equality is given upon the sum of the entire varialbes.
         * @param Mat2 
         * @return true our_mat <= mat2
         * @return false our_mat > mat2
         */
        bool operator<= (const Matrix &Mat2) const;

        /**
         * @brief overloads the '==' oeprator to check if the matrices are equal
         * equality is given upon the sum of the entire varialbes.
         * @param Mat2 
         * @return true our_mat == mat2
         * @return false our_mat != mat2 
         */
        bool operator== (const Matrix &Mat2) const;

        /**
         * @brief overloads the '==' oeprator to check if the matrices are equal
         * equality is given upon the sum of the entire varialbes.
         * @param Mat2 
         * @return true our_mat == mat2
         * @return false our_mat != mat2 
         */
        bool operator!= (const Matrix &Mat2) const;

        /* ---------------------------------------------------------- */

        /* Postfix Prefix operators */
        /* ---------------------------------------------------------- */

        /**
         * @brief Overloads the '++' operator -> ++Matrix
         * will return the matrix increased by 1 
         * @return Matrix& 
         */
        Matrix& operator++();       
        /**
         * @brief Overloads the '++' operator -> Matrix++
         * will return the matrix increased by 1 
         * @return Matrix& 
         */
        Matrix operator++(int);

        /**
         * @brief Overloads the '--' operator -> --Matrix
         * will return the matrix increased by 1 
         * @return Matrix& 
         */
        Matrix& operator--();       
        /**
         * @brief Overloads the '--' operator -> Matrix--
         * will return the matrix increased by 1 
         * @return Matrix& 
         */
        Matrix operator--(int);

        /* ---------------------------------------------------------- */

        /* Multipliction Operators */
        /* ---------------------------------------------------------- */
        
        /**
         * @brief overloads the '*' operator to support scalar matrix multiplicion.
         * 
         * @param scalar double
         * @return Matrix * Scalar
         */
        Matrix operator* (double scalar);
        /**
         * @brief overloads the '*=' operator to support scalar matrix multiplicion.
         * just in a prettier way.
         * @param scalar double
         * @return Matrix * Scalar
         */
        Matrix operator*= (double scalar);

        /**
         * @brief add support of double * Mat (instead of Mat * double)
         * 
         * @param scalar 
         * @param Mat 
         * @return Matrix 
         */
        friend Matrix operator* (double scalar, Matrix &Mat);


        /**
         * @brief overloads the '*' operator to support matrix multipliction.
         * 
         * @param Mat2 Matrix
         * @return Matrix 
         */
        Matrix operator* (const Matrix &Mat2);
        /**
         * @brief overloads the '*=' operator to support matrix multipliction.
         * just in a prettier way.
         * @param Mat2 Matrix
         * @return Matrix 
         */
        Matrix operator*= (const Matrix &Mat2);

        /* ---------------------------------------------------------- */

        /* I/O Operators */ // < fix this <
        /* ---------------------------------------------------------- */

        /**
         * @brief override the operator '<<' which is the output operator cout
         * 
         * @param os 
         * @param Mat 
         * @return ostream& 
         */
        friend std::ostream& operator<< (std::ostream& output, const Matrix& Mat);

        /**
         * @brief override the operator '>>' which is the input operator cin.
         * 
         * @param os 
         * @param Mat 
         * @return isstream& 
         */
        friend std::istream& operator>> (std::istream& is, Matrix& Mat);

        /* ---------------------------------------------------------- */


    };
}
