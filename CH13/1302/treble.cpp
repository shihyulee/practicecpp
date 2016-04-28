#include "treble.hpp"

void treble_zero::input(double set_data)
{
  if (set_data <= -max_data){
    data = -max_data;
  }
  else if (set_data >= max_data){
    data = max_data;
  }
  else{
    data = set_data;
  }
  // Calculate cursor position (0.5 ensures rounding):
  cursor = static_cast<int>((2.0/3.0) * (data + max_data) * scale_length / max_data + 0.5);
}
