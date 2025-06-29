

#include <iostream>
#include <vector>

template<typename T> using matrix = std::vector<std::vector<T>>;

template <typename T> T dot_product(const std::vector<T>& x, const std::vector<T>& y);

template <typename T> matrix<T> multiply_matrix (const matrix<T>& A, const matrix<T>& B);
