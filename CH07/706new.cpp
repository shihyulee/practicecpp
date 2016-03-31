// Integers Sort

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>

using namespace std;

// Function declarations:
void get_words(int *pt_words, int words);
void list_words(int *pt_words, int words);
void bubble_sort(int *pt_data, int elements, void (order)(int*));
void order_ints(int *pt);
int cmp(const void *s1, const void *s2);

void get_words(int *pt_words, int words)
{
  srand(time(0));
  int value;
  for (int entry = 0; entry < words; ++entry){
    value = rand() % 1000;
    pt_words[entry] = value;
  }
}

void list_words(int *pt_words, int words)
{
  cout << endl;
  for (int i = 0; i < words; ++i)
    cout << pt_words[i] << " ";
  cout << endl;
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

int cmp(const void *s1, const void *s2)
{
    return (int *)s1 - (int *)s2;
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
  clock_t start_time = clock();
  bubble_sort(pt_words, words, order_ints);
  clock_t stop_time = clock();
  cout << "\nOrdered lower case list:" << endl;
  list_words(pt_words, words);

  //cout << endl << "[qsort] version:" << endl;
  clock_t start_time2 = clock();
  qsort(pt_words, words, sizeof(int), cmp);
  clock_t stop_time2 = clock();
  //list_words(pt_words, words);
  cout << endl;
  cout << "Time taken of the [Bubble] version = " << static_cast<float> (stop_time - start_time) / CLOCKS_PER_SEC << " secs. " << endl;

  cout << "Time taken of the [qsort] version = " << static_cast<float> (stop_time2 - start_time2) / CLOCKS_PER_SEC << " secs. " << endl;


  return(EXIT_SUCCESS);
}
