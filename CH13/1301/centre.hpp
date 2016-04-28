#ifndef CENTRE_ZERO_H
#define CENTRE_ZERO_H

#include "control.hpp"

class centre_zero : virtual public controller {
public:
  void input(double set_data);
protected:
  centre_zero(double set_max_data, const String &set_label, int set_scale_length) : controller(set_max_data, set_label, set_scale_length) { }
};

#endif // CENTRE_ZERO_H
