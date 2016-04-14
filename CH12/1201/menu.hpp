#ifndef MENU_HPP
#define MENU_HPP

# include "string.hpp"

class option {
public:
  option(const String &option_label) { _label = option_label; }
  virtual void activate(void) = 0;
  void print_label(void) { _label.print(); }
private:
  String _label;
};

class menu : public option {
public:
  menu(const String &menu_label, int max_number_of_options);
  virtual ~menu();
  void set_option(option *op_pt);
  void activate(void);
private:
  option **_option_list;
  int _options, _max_options;
};

class action : public option {
public:
  action(const String &action_label, void (*function_pt)(void), option *option_pt = 0);
  void activate(void);
private:
  void (*f_pt)(void);
  option *op_pt;
};

#endif // MENU_HPP
