// Implement and test a cylinder class

#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;

class cylinder {
public:
  cylinder(const double & x, const double & y, const double & z, const double & r, const double & h ){ 
    _total++;
    _radius = r;
    _height = h; 
    _x_centre = x; 
    _y_centre = y;
    _z_centre = z;     
  };
  
  cylinder(const cylinder & c1){
    _total++;
    _radius   = c1._radius;
    _height   = c1._height; 
    _x_centre = c1._x_centre; 
    _y_centre = c1._y_centre;
    _z_centre = c1._z_centre;     
  }
  
  
  void assign_centre(const double & x, const double & y, const double & z);
  void assign_radius(const double &r);
  void assign_height(const double &h);
  double volume(void);

  static int total_cylinder(void) { return _total; }

private:
  double _radius, _height, _x_centre, _y_centre, _z_centre;
  static int _total;

};

inline void cylinder::assign_centre(const double & x, const double & y, const double & z)
{
  _x_centre = x;
  _y_centre = y;
  _z_centre = z;
}

inline void cylinder::assign_radius(const double & r)
{
  _radius = r;
}
inline void cylinder::assign_height(const double & h)
{
  _height = h;
}

double cylinder::volume(void)
{
  return M_PI * _radius*_radius * _height;
}


int cylinder::_total = 0;

int main()
{
  cout << "Initial number of cylinder = " << cylinder::total_cylinder() << endl;

  cylinder c(0.,0.,1.,3.,3.);
  
  
  
  c.assign_radius(2.0);
  c.assign_height(3.0);

  cout << "The volume of cylinder is " << c.volume() << endl;

  cout << "Total number of cylinder = " << c.total_cylinder() << endl;

  cylinder c2(c);
    
  cout << "The volume of cylinder is " << c2.volume() << endl;

  cout << "Total number of cylinder = " << c2.total_cylinder() << endl;

  
  return(EXIT_SUCCESS);
}
