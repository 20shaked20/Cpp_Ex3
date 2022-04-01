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

#include <vector>


namespace zich{

    class Matrix{

        private:

        public:
        
        Matrix(std::vector<double> vec, int rows, int column);

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
        Matrix operator- (const Matrix &Mat2);
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
        bool operator> (const Matrix &Mat2);

        /**
         * @brief Overloads the '>=' operator to support equality check between matrices.
         * equality is given upon the sum of the entire varialbes.
         * @param Mat2 
         * @return true our_mat >= mat2
         * @return false our_mat < mat2
         */
        bool operator>= (const Matrix &Mat2);

        /**
         * @brief overloads the '<' operator to support equality between matrices.
         * equality is given upon the sum of the entire varialbes.
         * @param Mat2 
         * @return true our_mat < mat2
         * @return false our_mat > mat2
         */
        bool operator< (const Matrix &Mat2);

        /**
         * @brief Overloads the '<=' operator to support equality check between matrices.
         * equality is given upon the sum of the entire varialbes.
         * @param Mat2 
         * @return true our_mat <= mat2
         * @return false our_mat > mat2
         */
        bool operator<= (const Matrix &Mat2);

        /**
         * @brief overloads the '==' oeprator to check if the matrices are equal
         * equality is given upon the sum of the entire varialbes.
         * @param Mat2 
         * @return true our_mat == mat2
         * @return false our_mat != mat2 
         */
        bool operator== (const Matrix &Mat2);

        /**
         * @brief overloads the '==' oeprator to check if the matrices are equal
         * equality is given upon the sum of the entire varialbes.
         * @param Mat2 
         * @return true our_mat == mat2
         * @return false our_mat != mat2 
         */
        bool operator!= (const Matrix &Mat2);

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
        const Matrix operator++(int);

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
        const Matrix operator--(int);

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

        /* I/O Operators */
        friend ostream& operator<< (ostream& os, const Matrix& Mat);
        friend ostream& operator>> (ostream& os, const Matrix& Mat);


    };
}
