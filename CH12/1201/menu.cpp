#include <iostream>
#include <cstdlib>
#include "menu.hpp"

using namespace std;

menu::menu(const String &menu_label, int max_number_of_options) : option(menu_label)
{
  _max_options = max_number_of_options;
  if (_max_options <= 0) {
    cout << "Error in menu(): options = " << _max_options << endl;
    exit(EXIT_FAILURE);
  }
  else {
    _option_list = new option *[_max_options];
  }
  _options = 0;
}

menu ::~menu()
{
  delete _option_list;
}
void menu::set_option(option *op_pt)
{
  if (_options < _max_options) {
    _option_list[_options] = op_pt;
    ++_options;
  }
  else {
    cerr << "Attempt to set " << _options + 1 << " menu options\n Only " << _max_options << " options are allowed" << endl;
    exit(EXIT_FAILURE);
  }
}

void menu::activate(void)
{
  int i, choice;
  do {
    cout << endl;
    print_label();
    cout << endl;
    for (i = 0; i < _options; ++i){
      cout << i << "\t";
      _option_list[i]->print_label();
      cout << endl;
    }
    cout << "Select option: ";
    cin >> choice;
  } while (choice < 0 || choice >= _options);
  _option_list[choice]->activate();
}

action::action(const String &action_label, void (*function_pt)(void), option *option_pt) : option(action_label)
{
  f_pt = function_pt;
  op_pt = option_pt;
}

void action::activate(void)
{
  f_pt();
  op_pt->activate();
}
