#ifndef CENTRE_LINEAR_HPP
#define CENTRE_LINEAR_HPP
#include "centre.hpp"
#include "linear.hpp"

class centre_linear : public centre_zero, public linear {
public:
  centre_linear(double set_max_data, const String &set_label, int set_scale_length) : centre_zero(set_max_data, set_label, set_scale_length), linear(set_max_data, set_label, set_scale_length), controller(set_max_data, set_label, set_scale_length) { }
};

#endif // CENTRE_LINEAR_HPP
