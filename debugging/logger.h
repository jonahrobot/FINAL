
#pragma once

#include <iostream>
#include <string>

class Logger {
 private:
  std::ostream &outStream;

 public:
  Logger(std::ostream &os) : outStream(os) {}

  void log(const std::string &message) {
    outStream << "LOG: " << message << std::endl;
  }

  void logError(const std::string &message) {
    outStream << "ERROR: " << message << std::endl;
  }
};
