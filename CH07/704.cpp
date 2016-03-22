// An Alphabetic Sort

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
using namespace std;

// Function declarations:
void get_words(char **pt_words, int words);
void list_words(char **pt_words, int words);
void words_to_lower_case(char **pt_words, int words);
void word_to_lower_case(char *word);
void bubble_sort(char **pt_data, int elements, void (*order)(char**));
void order_strings(char **pt);

void get_words(char **pt_words, int words)
{
  char buffer[128];
  for (int entry = 0; entry < words; ++entry){
    cin >> buffer;
    int length = 1 + strlen(buffer);
    pt_words[entry] = new char[length];
    memcpy(pt_words[entry], buffer, length);
  }
}

void list_words(char **pt_words, int words)
{
  cout << endl;
  for (int i = 0; i < words; ++i)
    cout << pt_words[i] << endl;
}

void words_to_lower_case(char **pt_words, int words)
{
  for (int i = 0; i < words; ++i)
    word_to_lower_case(pt_words[i]);
}

void word_to_lower_case(char *pt)
{
  while (*pt){
    *pt = tolower(*pt);
    ++pt;
  }
}

void bubble_sort(char **pt_data, int elements, void (*order)(char**))
{
  int n = elements - 1;
  for (int i = 0; i < n; ++i){
    for (int j = n; j > i; --j){
      order(pt_data + j - 1);
    }
  }
}

void order_strings(char **pt)
{
  char *temp;
  if (strcmp(pt[0], pt[1]) > 0) {
    temp = pt[0];
    pt[0] = pt[1];
    pt[1] = temp;
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2){
    cout << "Usage: my_sort <number of words>" << endl;
    exit(EXIT_FAILURE);
  }
  int words = atoi(argv[1]);
  if (words < 1){
    cout << "Cannot enter " << words << " words" << endl;
    exit(EXIT_FAILURE);
  }
  char **pt_words = new char *[words];

  get_words(pt_words, words);
  cout << "\nOriginal list:" << endl;
  list_words(pt_words, words);

  words_to_lower_case(pt_words, words);
  cout << "\nLower case list:" << endl;
  list_words(pt_words, words);

  bubble_sort(pt_words, words, order_strings);
  cout << "\nOrdered lower case list:" << endl;
  list_words(pt_words, words);

  return(EXIT_SUCCESS);
}
