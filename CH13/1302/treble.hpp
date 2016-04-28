#ifndef TREBLE_ZERO_HPP
#define TREBLE_ZERO_HPP

#include "control.hpp"

class treble_zero : virtual public controller {
public:
  void input(double set_data);
protected:
  treble_zero(double set_max_data, const String &set_label, int set_scale_length) : 
  controller(set_max_data, set_label, set_scale_length) { }
};

#endif // TREBLE_ZERO_HPP
