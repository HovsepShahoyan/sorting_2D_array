#include "sorting_2D_array.h"
#include <iostream>

int main() {
    int row;
    int column;
    std::cin >> row;
    std::cout << std::endl;
    std::cin >> column;
    std::cout << std::endl;
    int** matrix = create_matrix(row, column);
    insert_matrix(matrix, row, column);
    std::cout << std::endl;
    print_matrix(matrix, row, column);
    std::cout << std::endl;
    sorting_rowWise(matrix, row, column);
    print_matrix(matrix, row, column);
    std::cout << std::endl;
    delete_matrix(matrix, row);
}
