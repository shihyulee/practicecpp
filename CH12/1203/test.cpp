// Tests doubly linked list class

#include <iostream>
#include <cstdlib>
#include "dlist.hpp"
using namespace std;

void print_forward(dlist &s)
{
  node *pt;
  s.set_cursor_head();
  cout << "forward list: ";
  if((pt = s.forward()) != 0)
    cout << "(" << pt->index << ", " << pt->data << ")";
  else
    cout << "empty";
  while((pt = s.forward()) != 0)
    cout << " -> " << "(" << pt->index << ", " << pt->data << ")";
  cout << endl;
}

void print_backward(dlist &s)
{
  node *pt;
  s.set_cursor_tail();
  cout << "Backward list: ";
  if ((pt = s.backward()) != 0)
    cout << "(" << pt->index << ", " << pt->data << ")";
  else
    cout << "empty";
  while ((pt = s.backward()) != 0){
    cout << " -> " << "(" << pt->index << ", " << pt->data << ")";
  }
  cout << endl;
}

int LengthOfSparse (double *v, const int lenght)
{
  unsigned VSNum = 0;
  for (int i = 0 ; i < lenght; ++i){
    if (*(v+i) == 0){
      continue;
    }
    else {
      VSNum++;
    }
  }
  return VSNum;
}

int main()
{
  // Create an empty list:
  dlist s;

  // Print the list forwards and backwards;
  //print_forward(s);
  //print_backward(s);

  const int length = 10;
  double v[length] = {0.0, 2.2, 1.4, 0.0, 4.0, 9.0, 0.0, 1.2, 0.0, 0.0};

  cout << "The original vector is:" << endl;
  for (int i = 0; i < length; ++i){
    cout << v[i] << "\t";
  }
  cout << endl;
  int SVlength = LengthOfSparse(v, length);
  matrix m(2, SVlength);
  int j = 0;
  for (int i = 0; i < length; ++i){
    if (*(v+i) == 0){
      continue;
    }
    else {
      m(0, j) = i;
      m(1, j) = *(v + i);
      j++;
    }
  }
  cout << " The Sparse Vector is" << endl;
  for (int i = 0; i < 2; ++i)
  {
    for (int j = 0; j < SVlength; j++)
    {
      cout << m(i, j) << "\t";
    }
    cout << endl;
  }
cout << endl;
cout << "Use Doubly linked lists"<< endl;
  for (int i = 0; i < SVlength; ++i){
      s.add_head();
      (s.cursor_position())->index = m(0, i);
      (s.cursor_position())->data = m(1, i);

  }

  print_forward(s);
  print_backward(s);

  return(EXIT_SUCCESS);
}
