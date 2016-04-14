#include <iostream>
#include <cstdlib>
#include "menu.hpp"
#include "complex.hpp"

using namespace std;

void print(const complex &z);
void to_system(void);
void start_complex_operand(void);
void Addition(void);
void Substruction(void);
void Multipulation(void);
void Division(void);
void leave_complex_operand(void);


complex z1(1, 2), z2(3, 3), z3, z4, z5, z6;
void print(const complex &z)
{
  cout << Real(z) << " + i * (" << Imag(z) << ")" << endl;
}

void to_system(void)
{
  cout << "\nReturning to system." << endl;
  exit(EXIT_SUCCESS);
}

void start_complex_operand(void)
{
  cout << "Given that:" << endl;
  cout << "z1 = ";
  print(z1);
  cout << "z2 = ";
  print(z2);
}

void leave_complex_operand(void)
{
  cout << "\nThe Complex Operand has been terminated." << endl;
}

void Addition(void)
{
  z3 = z1 + z2;
  cout << "z1 + z2 = ";
  print(z3);
}

void Substruction(void)
{
  z4 = z1 - z2;
  cout << "z1 - z2 = ";
  print(z4);
}

void Multipulation(void)
{
  z5 = z1 * z2;
  cout << "z1 * z2 = ";
  print(z5);
}

void Division(void)
{
  z6 = z1 / z2;
  cout << "z1 / z2 = ";
  print(z6);
}

int main()
{
  
  option* a; 

  const int top_menu_options = 2;
  const int operand_menu_options = 5;
  // Define menus:
  menu top_menu("Top menu", top_menu_options);
  menu operand_menu("MULTI-grid menu", operand_menu_options);
  // Set options for top menu:
  top_menu.set_option(new action("Return to system", to_system));
  top_menu.set_option(new action("Start complex operand", &start_complex_operand, &operand_menu));
  // Set options for multi-grid menu:
  operand_menu.set_option(new action("Leave complex operand", leave_complex_operand, &top_menu));
  operand_menu.set_option(new action("Slove z1 + z2", Addition, &operand_menu));
  operand_menu.set_option(new action("Slove z1 - z2", Substruction, &operand_menu));
  operand_menu.set_option(new action("Slove z1 * z2", Multipulation, &operand_menu));
  operand_menu.set_option(new action("Slove z1 / z2", Division, &operand_menu));
  // Start the menu a=system:
  top_menu.activate();
  return EXIT_SUCCESS;
}
