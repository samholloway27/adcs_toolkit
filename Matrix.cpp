

#include <iostream>
#include <vector>
#include "Matrix.hpp"

// #define DEBUG

template <typename T> T dot_product(const std::vector<T>& x,const std::vector<T>& y) {
    T result = 0;
    for (size_t i=0; i<x.size(); i++) {
        result += x[i] * y[i];
    }
    return result;

}

template <typename T> matrix<T> add_matrix (const matrix<T>& A, const matrix<T>& B) {

    // For now, assumes that A and B are the same dimensions


    matrix<T> C = {};

    for (size_t i=0; i < A.size(); i++) {
        std::vector<T> row;
        for (size_t j=0; j < A[0].size(); j++) {


            #ifdef DEBUG
                std::cout << "Adding " << A[i][j] << " and " << B[i][j] << std::endl;
            #endif

            row.push_back(A[i][j] + B[i][j]);

        }
        C.push_back(row);
    }


    return C;

}

template <typename T> matrix<T> multiply_matrix (const matrix<T>& A, const matrix<T>& B){
    matrix<T> C = {};

    for (size_t i=0; i < A.size(); i++) {
        std::vector<T> row;
        for (size_t j=0; j < A[0].size(); j++) {
            T value = 0;
            // Find the number of "columns" of A by finding length of first element
            int n = A[0].size();
            for (size_t k=0; k<n; k++) {
                value += A[i][k] * B[k][j];
            }

            row.push_back(value);

        }
        C.push_back(row);
    }


    return C;

}

template <typename T> void const print_matrix(const matrix<T>& A) {

    std::cout << "[";

    for (size_t i=0; i < A.size(); i++) {
        std::vector<T> row;
        for (size_t j=0; j < A[0].size(); j++) {
            if ( !((i==0) && (j==0)) ){
                std::cout << " ";
            }
            std::cout << " " << A[i][j] << ",";
        }
        if (i == A.size()-1){
            std::cout << "  ]";
        }
        std::cout << std::endl;
    }

}


int main (){


    // Use this area for testing

    matrix<double> *matrix1 = new matrix<double> {
        {2.4, 5.3, 6.5},
        {-5.7, 2.3, 8.5},
        {4.1, -1.3, -0.3},
        };

    matrix<double> *matrix2 = new matrix<double> {
        {1.2, 2.2, -3.7},
        {-3.7, -1.9, 3.5},
        {0.7, -1.1, 4.1},
    };

    // matrix<double> result = add_matrix(*matrix1, *matrix2);
    matrix<double> result = multiply_matrix(*matrix1, *matrix2);


    std::cout << result.size() << std::endl;

    for (size_t i=0; i < result.size(); i++) {
        for (size_t j=0; j < result[0].size(); j++) {
            std::cout << "Element (" << i << "," << j << ") is " << result[i][j] << std::endl;
        }
    }
    print_matrix(*matrix1);

    delete matrix1;


    return 0;

}