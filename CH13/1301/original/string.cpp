// Implements string class

#include <iostream>
#include "string.hpp"
using namespace std;

String::String(const String &s)
{
  _characters = s. _characters;
  _pt = new char[_characters];
  memcpy(_pt, s._pt, _characters);
}

String::String(char const *s)
{
  _characters = strlen(s);
  _pt = new char[_characters];
  memcpy(_pt, s, _characters);
}

String &String::operator=(const String &s)
{
  delete _pt;
  _characters = s. _characters;
  _pt = new char[_characters];
  memcpy(_pt, s._pt, _characters);
  return *this;
}

char *String::char_array(void) const
{
  char *buffer = new char[1 + _characters];
  memcpy(buffer, _pt, _characters);
  buffer[_characters] = '\0';
  return buffer;
}

String::String(int set_length)
{
  _characters = set_length;
  _pt = new char[_characters];
}

void String::print(void)
{
  for (int i = 0; i < _characters; ++i)
    cout << _pt[i];
}

// friend function implementation
String operator+(const String &s1, const String &s2)
{
  int s1_length = s1.length();
  int s2_length = s2.length();
  String new_String(s1_length + s2_length);
  memcpy(new_String._pt, s1._pt, s1_length);
  memcpy(new_String._pt + s1_length, s2._pt, s2_length);
  return new_String;
}
