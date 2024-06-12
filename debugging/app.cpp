
#include "app.h"

App::App(std::ostream &os)
    : logger(std::cerr), displayOutStream(os), menu(this) {}

void App::run() {
  menu.display();

  int choice;
  std::cout << "Enter your choice: ";
  std::cin >> choice;
  while (true) {
    menu.handleUserInput(choice);
    if (choice == 1) {
      menu.display();
    } else if (choice == 4) {
      break;
    }
    std::cout << "Enter your choice: ";
    std::cin >> choice;
  }
}
