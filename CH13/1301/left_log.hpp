#ifndef LEFT_LOG_HPP
#define LEFT_LOG_HPP
#include "left.hpp"
#include "log.hpp"

class left_log : public left_zero, public logarithmic {
public:
  left_log(double set_max_data, const String &set_label, int set_scale_length) : 
  controller(set_max_data, set_label, set_scale_length),
  left_zero(set_max_data, set_label, set_scale_length), 
  logarithmic(set_max_data, set_label, set_scale_length){ }
};

#endif // LEFT_LOG_HPP
