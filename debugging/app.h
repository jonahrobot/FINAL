
#pragma once

#include "logger.h"
#include "menu.h"

class Menu;

class App {
 private:
  Logger logger;
  Menu menu;
  std::ostream &displayOutStream;

 public:
  friend class Menu;

  App(std::ostream &os);
  void run();
};
