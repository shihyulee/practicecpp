// Defines self-describing setting class

#ifndef SELF_DESCRIBING_STRING_HPP
#define SELF_DESCRIBING_STRING_HPP

#include <cstring>
using namespace std;

class String {
friend String operator+(const String &s1, const String &s2);
friend bool operator==(const String &s1, const String &s2);
friend bool operator!=(const String &s1, const String &s2);
public:
  String(void) {
    _characters = 0;
    _pt = NULL;
  }
  String(const String &s);
  String(char const *s);
  String &operator=(const String &s);
  char *char_array (void) const;
  int length(void) const { return _characters; }
  void print(void);
private:
  String(int set_length);
  int _characters;
  char *_pt;
};

inline bool operator==(const String &s1, const String &s2)
{
  if (s1._characters == s2._characters &&
    !memcmp(s1._pt, s2._pt, s1._characters))
    return true;
  else
    return false;
}

inline bool operator!=(const String &s1, const String &s2)
{
  if (s1._characters == s2._characters &&
    !memcmp(s1._pt, s2._pt, s1._characters))
    return false;
  else
    return true;
}

#endif //SELF_DESCRIBING_STRING_HPP
