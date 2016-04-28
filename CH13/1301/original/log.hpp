#ifndef LOG_HPP
#define LOG_HPP

#include <cmath>
#include "control.hpp"
using namespace std;

class logarithmic : virtual public controller {
public:
  void output(double &give_data) {
    give_data = log(1.0 + data);
  }
protected:
  logarithmic(double set_max_data, const String &set_label, int set_scale_length) : controller(set_max_data, set_label, set_scale_length) { }
};
#endif // LOG_HPP 
