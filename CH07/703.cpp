// Integers Sort

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

// Function declarations:
void get_words(int *pt_words, int words);
void list_words(int *pt_words, int words);
void bubble_sort(int *pt_data, int elements, void (order)(int*));
void order_ints(int *pt);

void get_words(int *pt_words, int words)
{
  int value;
  for (int entry = 0; entry < words; ++entry){
    cin >> value;
    pt_words[entry] = value;
  }
}

void list_words(int *pt_words, int words)
{
  cout << endl;
  for (int i = 0; i < words; ++i)
    cout << pt_words[i] << endl;
}


void bubble_sort(int *pt_data, int elements, void (order)(int*))
{
  int n = elements - 1;
  for (int i = 0; i < n; ++i)
    for (int j = n; j > i; --j)
      order(pt_data + j - 1);
}

void order_ints(int *pt)
{
  int temp;
  if (pt[0] - pt[1] > 0) {
    temp = pt[0];
    pt[0] = pt[1];
    pt[1] = temp;
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2){
    cout << "Usage: my_sort <number of integers>" << endl;
    exit(EXIT_FAILURE);
  }
  int words = atoi(argv[1]);
  if (words < 1){
    cout << "Cannot enter " << words << " words" << endl;
    exit(EXIT_FAILURE);
  }
  int *pt_words = new int [words];

  get_words(pt_words, words);
  cout << "\nOriginal list:" << endl;
  list_words(pt_words, words);

  bubble_sort(pt_words, words, order_ints);
  cout << "\nOrdered lower case list:" << endl;
  list_words(pt_words, words);

  return(EXIT_SUCCESS);
}
