#ifndef LINEAR_HPP
#define LINEAR_HPP

#include "control.hpp"

class linear : virtual public controller {
public:
  void output(double &give_data) { give_data = data; }
protected:
  linear(double set_max_data, const String &set_label, int set_scale_length) : controller(set_max_data, set_label, set_scale_length) { }
};
#endif // LINEAR_H
