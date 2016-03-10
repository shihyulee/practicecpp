// Modify matrix addition in section 7.8 to matrix multiplication

#include <iostream>
#include <cstdlib>
using namespace std;

//Function declaration
double *create_matrix(int rows, int columns);
double &element(double *pt_matrix, int columns, int row, int column);
void multi_matrices(double *pt_result_matrix, double *pt_matrix_a, double *pt_matrix_b, int rows, int columns, int columns_k);
void print_matrix(double *pt_matrix, int rows, int columns);

double *create_matrix(int rows, int columns) //Dynamically allocates matrix
{
  double *pt = new double[rows * columns];
  return pt;
}

double &element(double *pt_matrix, int columns, int row, int column)
{
  return *(pt_matrix + (row - 1) * columns + column - 1);
}

void multi_matrices(double *pt_result_matrix, double *pt_matrix_a, double *pt_matrix_b, int rows, int columns, int columns_k)
{
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < columns; ++j){
      double result = 0.0;
      for (int l = 0; l < columns_k; ++l){
        result += (*(pt_matrix_a + i * columns_k + l)) * (*(pt_matrix_b + l * columns + j ));
      }
      *(pt_result_matrix + i * columns + j) = result;
    }
  }
}

void print_matrix(double *pt_matrix, int rows, int columns)
{
  for (int i = 1; i <= rows; ++i){
    for (int j = 1; j < columns; ++j){
      cout << element(pt_matrix, columns, i, j) << " ";
    }
    if (columns != 1)
    cout << element(pt_matrix, columns, i, columns) << endl;
  }
  cout << endl;
}

int main(int argc, char *argv[])
{
  if (argc != 5) {
    cout << "Usage: mult<rows><columns><rows2><columns2>" << endl;
    exit(EXIT_FAILURE);
  }
  int rows = atoi(argv[1]);
  if(rows < 1){
    cout << "Rows in matrix A= " << rows << ".\nMust have: 0 < rows." << endl;
    exit(EXIT_FAILURE);
  }
  int columns_k = atoi(argv[2]);
  if (columns_k < 1){
    cout << "Columns in matrix A =" << columns_k << ".\nMust have: 0 < columns." << endl;
    exit(EXIT_FAILURE);
  }
  int rows_k = atoi(argv[3]);
  if(rows_k < 1){
    cout << "Rows in matrix B = " << rows_k << ".\nMust have: 0 < rows." << endl;
    exit(EXIT_FAILURE);
  }
  int columns = atoi(argv[4]);
  if (columns < 1){
    cout << "Columns in matrix B =" << columns << ".\nMust have: 0 < columns." << endl;
    exit(EXIT_FAILURE);
  }
  if (columns_k != rows_k){
    cout << "The matrix A can not be multipied by matrix B." << endl;
    exit(EXIT_FAILURE);
  }

  //Create matrices:
  double *pt_a = create_matrix(rows, columns_k);
  double *pt_b = create_matrix(rows_k, columns);
  double *pt_c = create_matrix(rows, columns);

  //Fill matrices;
  for (int i = 1; i <= rows; ++i){
    for (int j = 1; j <= columns_k; ++j){
      element(pt_a, columns_k, i, j) = i * (j + 1);
    }
  }

  for (int i = 1; i <= rows_k; ++i){
    for (int j = 1; j <= columns; ++j){
      element(pt_b, columns, i, j) = (i + 1) * (j + 1);
    }
  }
  //Print matrices:
  cout << "Matrix A:" << endl;
  print_matrix(pt_a, rows, columns_k);
  cout << "Matrix B:" << endl;
  print_matrix(pt_b, rows_k, columns);

  //Multiplication matrices:
  multi_matrices(pt_c, pt_a, pt_b, rows, columns, columns_k);

  //Print results:
  cout << "Result of multipling matrices:" << endl;
  print_matrix(pt_c, rows, columns);

  return(EXIT_SUCCESS);
}
