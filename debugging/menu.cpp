
#include "menu.h"

#include "app.h"

Menu::Menu(App *app) {}

void Menu::display() {
  app->displayOutStream << TITLE << std::endl;
  app->displayOutStream << "1. Menu" << std::endl;
  app->displayOutStream << "2. Option 2" << std::endl;
  app->displayOutStream << "3. Option 3" << std::endl;
  app->displayOutStream << "4. Exit" << std::endl;
}

void Menu::handleUserInput(int choice) {
  switch (choice) {
    case 1:
      app->logger.log("User selected Option 1: Menu");
      break;
    case 2:
      app->logger.log("User selected Option 2");

    case 3:
      app->logger.log("User selected Option 3");

    case 4:
      app->logger.log("User selected Exit");

    default:
      app->logger.logError("Invalid option selected");
      break;
  }
}
