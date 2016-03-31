// An Alphabetic Sort: Modify  section 7.8.2

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

// Function declarations:
void list_words(char **pt_words, int words);

void list_words(char **pt_words, int words)
{
  cout << endl;
  for (int i = 0; i < words; ++i)
    cout << pt_words[i] << endl;
}


int main(int argc, char *argv[])
{
  if (argc != 2){
    cout << "Usage: my_sort <number of words>" << endl;
    exit(EXIT_FAILURE);
  }
  char *word = argv[1];
  char *filewords[] = {"This", "is", "a", "test", "text"};
  cout << *filewords[2] << endl;
  cout << "\nOriginal list:" << endl;
  int num = strlen(*filewords);
  list_words(filewords, num);
  int count = 0;
  for (int i = 0; i < num; ++i)
  {
    if (*filewords[i] == *word){
      count++;
    }
  }
  cout << endl << count << " OCCURRENCES OF " << word << endl << endl;
/*
  char buffer[200];
  fstream file;
  file.open("test.txt",ios::in);
  if(!file){
      cout << "The file is not exist!" << endl<< endl;
      exit(EXIT_FAILURE);
  }
  else{
    while(file.getline(buffer, sizeof(buffer), ' ')){
      cout << buffer << endl;
    }
    cout << buffer[2]<< endl;
    file.close();
  }
*/

//   char **pt_words = new char *[words];
//
//   get_words(pt_words, words);
//   cout << "\nOriginal list:" << endl;
//   list_words(pt_words, words);
//
//   words_to_lower_case(pt_words, words);
//   cout << "\nLower case list:" << endl;
//   list_words(pt_words, words);

  return(EXIT_SUCCESS);
}
