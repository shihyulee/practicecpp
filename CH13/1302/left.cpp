#include "left.hpp"

void left_zero::input(double set_data)
{
  if (set_data <= 0.0){
    data = 0.0;
  }
  else if (set_data >= max_data){
    data = max_data;
  }
  else {
    data = set_data;
  }
  // Calculate cursor position (0.5 ensures rounding):
  cursor = static_cast<int>((data * scale_length) / max_data + 0.5);
}
