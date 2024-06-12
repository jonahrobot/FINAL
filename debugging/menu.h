
#pragma once

class App;

class Menu {
 public:
  static constexpr char TITLE[] = "Welcome to my App";

 private:
  App *app;

 public:
  Menu(App *app);
  void display();
  void handleUserInput(int choice);
};
