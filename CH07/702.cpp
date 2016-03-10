#include <iostream>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 3) {
  cout << "Usage: mult<rows><columns>" << endl;
  exit(EXIT_FAILURE);
  }
  int rows = atoi(argv[1]);
  if(rows < 1){
  cout << "Rows in matrix = " << rows << ".\nMust have: 0 < rows." << endl;
  exit(EXIT_FAILURE);
  }
  int columns = atoi(argv[2]);
  if (columns < 1){
  cout << "Columns in matrix A =" << columns << ".\nMust have: 0 < columns." << endl;
  exit(EXIT_FAILURE);
  }
  // Dynamically allocates matrix A
  int **pt_a = new int*[rows];
  for (int i = 0; i < rows; ++i){
      pt_a[i] = new int[columns];
  }
  // Dynamically allocates matrix B
  int **pt_b = new int*[columns];
  for (int i = 0; i < columns; ++i){
      pt_b[i] = new int[rows];
  }
  // Fill matrix A
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < columns; ++j){
      pt_a[i][j] = (i+1) + 2 * j;
    }
  }

  // print matrix A
  cout << "Matrix A = " << endl;
  for (int i = 0; i < rows; ++i){
    for (int j = 0; j < columns; ++j){
      cout << pt_a[i][j] <<  " ";
    }
    cout << endl;
  }
  cout << endl;

  // transpose matrix A to B
  for (int i = 0; i < columns; ++i){
    for (int j = 0; j < rows; ++j){
      pt_b[i][j] = pt_a[j][i];
    }
  }

  // print matrix B
  cout << "Matrix B = " << endl;
  for (int i = 0; i < columns; ++i){
    for (int j = 0; j < rows; ++j){
      cout << pt_b[i][j] <<  " ";
    }
    cout << endl;
  }
  cout << endl;

  for (int i = 0; i < rows; ++i){
    delete[] pt_a[i];
  }
  delete[] pt_a;

  for (int i = 0; i < columns; ++i){
    delete[] pt_b[i];
  }
  delete[] pt_b;

  return(EXIT_SUCCESS);
}
