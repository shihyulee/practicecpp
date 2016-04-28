// Defines controller class

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "string.hpp"

class controller {
public:
  virtual void input(double set_data) { }
  virtual void output(double &give_data) { }
  virtual void display(void);
protected:
  controller(double set_max_data, const String &set_label, int set_scale_length);
  controller(const controller &c);
  controller &operator=(const controller &c);
  int cursor, scale_length;
  double max_data, data;
  String label;
};

#endif // CONTROLLER_HPP
