#ifndef TREBLE_LINEAR_HPP
#define TREBLE_LINEAR_HPP
#include "treble.hpp"
#include "linear.hpp"

class treble_linear : public treble_zero, public linear {
public:
  treble_linear(double set_max_data, const String &set_label, int set_scale_length) : treble_zero(set_max_data, set_label, set_scale_length), linear(set_max_data, set_label, set_scale_length), controller(set_max_data, set_label, set_scale_length) { }
};

#endif // TREBLE_LINEAR_HPP
