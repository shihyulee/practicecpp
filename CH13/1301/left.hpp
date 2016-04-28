#ifndef LEFT_ZERO_HPP
#define LEFT_ZERO_HPP

#include "control.hpp"

class left_zero : virtual public controller {
public:
  void input(double set_data);
protected:
  left_zero(double set_max_data, const String &set_label, int set_scale_length) : controller(set_max_data, set_label, set_scale_length) { }
};

#endif // LEFT_ZERO_HPP
