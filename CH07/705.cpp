// An Alphabetic Sort: Modify  section 7.8.2

#include <iostream>
#include <cstdlib>

#include <cstring>

#include <cstring>
#include <cctype>
#include <fstream>
using namespace std;

// Function declarations:
void list_words(char **pt_words, int words);

void list_words(string *pt_words, int words)
{
  cout << endl;
  for (int i = 0; i < words; ++i)
    cout << pt_words[i] << endl;
}


int main(int argc, char *argv[]){
  
  if (argc != 2){
    cout << "Usage: my_sort <number of words>" << endl;
    exit(EXIT_FAILURE);
  }
  string word = argv[1];
  string filewords[] = {"This", "is", "a", "test", "text", "is"};
  cout << filewords[2] << endl;
  cout << "\nOriginal list:" << endl;
  int num = 6;
  
  std::cout<<"number of words:"<<num<<std::endl;
  list_words(filewords, num);
  int count = 0;
  for (int i = 0; i < num; ++i)
  {
    if ( !filewords[i].compare(word)  ){
      count++;
    }
  }
  cout << endl << count << " OCCURRENCES OF " << word << endl << endl;

  
  count = 0;
  string buffer;
  ifstream file;
  file.open("test.txt");
  if(!file){
      cout << "The file is not exist!" << endl<< endl;
      exit(EXIT_FAILURE);
  }
  else{
    file >> buffer;
    while( !file.eof() ){
      if ( !buffer.compare(word) ){
	count++;
      }
      file >> buffer;
    }
  }
  file.close();
  
  cout << endl << count << " OCCURRENCES OF " << word << " IN FILE " << endl << endl;;
  
  return(EXIT_SUCCESS);
}
