#include "sorting_2D_array.h"
#include <iostream>

int** create_matrix(int row, int column) {
    int** matrix = new int*[row];
    for(int i = 0; i < row; i++) {
        matrix[i] = new int[column];
    }
    return matrix;
}

void sorting_rowWise(int** matrix, int row, int column) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            for (int k = 0; k < column - j - 1; k++) {
                if(matrix[i][k] > matrix[i][k + 1]) {
                    int tmp = matrix[i][k];
                    matrix[i][k] = matrix[i][k+1];
                    matrix[i][k+1] = tmp;
                }
            }
        }        
    }
}

void delete_matrix(int** matrix, int row) {
    for(int i = row; i < row; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix = nullptr;
}

void print_matrix(int** matrix, int row, int column) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void insert_matrix(int** matrix, int row, int column) {
    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            std::cout << "Enter the element " << "[" << i << "]" << "[" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}