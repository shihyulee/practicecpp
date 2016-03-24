// Implement and test a cylinder class

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class cylinder {
public:
  void assign_centre(double x, double y, double z);
  void assign_radius(double r);
  void assign_height(double h);
  double volume(void);

  static void increment_cylinder(int new_cylinder);
  static int total_cylinder(void) { return total; }

private:
  double radius, height, x_centre, y_centre, z_centre;
  static int total;

};

inline void cylinder::assign_centre(double x, double y, double z)
{
  x_centre = x;
  y_centre = y;
  z_centre = z;
}

inline void cylinder::assign_radius(double r)
{
  radius = r;
}
inline void cylinder::assign_height(double h)
{
  height = h;
}

double cylinder::volume(void)
{
  return M_PI * pow(radius, 2) * height;
}

void cylinder::increment_cylinder(int new_cylinder)
{
  total += new_cylinder;
}

int cylinder::total;

int main()
{
  cout << "Initial number of cylinder = " << cylinder::total_cylinder() << endl;

  cylinder c;
  c.assign_radius(2.0);
  c.assign_height(3.0);

  cout << "The volume of cylinder is " << c.volume() << endl;

  cylinder::increment_cylinder(1);
  cout << "Total number of cylinder = " << cylinder::total_cylinder() << endl;

  return(EXIT_SUCCESS);
}
