#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

void bubble_sort(char *pt_data, int elements, void (order)(char*));
void order_strings(char *pt);

void bubble_sort(char *pt_data, int elements, void (order)(char*))
{
  int n = elements - 1;
  for (int i = 0; i < n; ++i)
    for (int j = n; j > i; --j)
      order(pt_data + j - 1);
}

void order_strings(char *pt)
{
  char temp;
  if (pt[0] > pt[1]) {
    temp = pt[0];
    pt[0] = pt[1];
    pt[1] = temp;
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2){
    cout << "Usage: my_sort <words>" << endl;
    exit(EXIT_FAILURE);
  }

  char *word = argv[1];

  //counting the length of word
  int Len = strlen(word);

  char *pt_word = new char [Len];

  cout << "The original lower alphabets list: " << endl;
  for( int i = 0; i < Len; ++i)
  {
    pt_word[i] = *(word+i);
    pt_word[i] = tolower(pt_word[i]);
    cout << pt_word[i] << endl;
  }

  cout << "Ordered lower alphabets list: " << endl;
  bubble_sort(pt_word, Len, order_strings);
  for( int i = 0; i < Len; ++i)
  {
    cout << pt_word[i] << endl;
  }

  return(EXIT_SUCCESS);
}
