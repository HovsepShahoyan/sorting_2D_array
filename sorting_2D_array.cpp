#include <iostream>
// There is no reason to have recursive sorting for the matrix because it will
// consume a lot of memory comparing to iterative way of sorting, besides 
// we can have some problems with our stack memory in case we work with 
// a big matrix size.
void insert_matrix(int**, int, int);
void print_matrix(int**, int, int);
void delete_matrix(int**, int);
void sorting_byValue(int**, int, int);
int** create_matrix(int, int);

int main() {
    int row;
    int column;
    std::cout << "Enter the number of rows" << std::endl;
    std::cin >> row;
    std::cout << std::endl;
    std::cout << "Enter the number of columns" << std::endl;
    std::cin >> column;
    std::cout << std::endl;
    int** matrix = create_matrix(row, column);
    insert_matrix(matrix, row, column);
    std::cout << std::endl;
    print_matrix(matrix, row, column);
    std::cout << std::endl;
    sorting_byValue(matrix, row, column);
    print_matrix(matrix, row, column);
    std::cout << std::endl;
    delete_matrix(matrix, row);
}

int** create_matrix(int row, int column) {
    std::cout << "Input the matrix: " << std::endl; 
    int** matrix = new int*[row];
    for(int i = 0; i < row; i++) {
        matrix[i] = new int[column];
    }
    return matrix;
}

void sorting_byValue(int** matrix, int row, int column) {
   int min = matrix[0][0];
   for(int i = 0; i < row; i++) {
       for(int j = 0; j < column; j++) {
           if(matrix[i][j] < min) {
               min = matrix[i][j];
           }
       }
   }
   for(int i = 0; i < row; i++) {
       for(int k = 1; k < row * column; k++) {
           int tmp = matrix[i][k];
           for(int j = k; j >= 1 && matrix[i][j-1] > tmp && tmp >= min; j--)   
            matrix[i][j] = matrix[i][j - 1];  
            matrix[i][k] = tmp;
            if(tmp < min) { break; }
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
