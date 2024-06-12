
#include <string>
// #include <iostream>

#include "parse.h"

int parseInt_OLD(const std::string &intString, const Format &format) {
  if (intString.size() == 0) throw SyntaxError();
  if (intString.size() == 1 && intString[0] == '-') throw SyntaxError();

  //
  int accumulator = 0;
  bool negative = 0;

  // for loop to go through intString
  for (int i = 0; i < intString.size(); i++) {
    const char ch = intString[i];  // ch is the char currently being parsed

    int temp = 0;
    switch (format) {
      case BINARY:
        if (!(ch == '0' || ch == '1')) throw SyntaxError();
        temp = ch - '0';
        accumulator *= 2;  // 2 for binary
        accumulator += temp;
        break;

      case UNSIGNED_DECIMAL:
        if (!(ch >= '0' && ch <= '9')) throw SyntaxError();
        temp = ch - '0';
        accumulator *= 10;  // 10 for decimal
        accumulator += temp;
        break;
      case SIGNED_DECIMAL:
        if (!((ch >= '0' && ch <= '9') || (i == 0 && ch == '-')))
          throw SyntaxError();
        temp = ch - '0';
        accumulator *= 10;  // 10 for decimal
        if (i == 0 && ch == '-') {
          negative = 1;
          // std::cout << "test" << std::endl;
        } else {
          accumulator += temp;
        }

        break;
      case HEXADECIMAL:
        if (!((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') ||
              (ch >= 'A' && ch <= 'F')))
          throw SyntaxError();
        temp = (ch >= '0' && ch <= '9')   ? (ch - '0')
               : (ch >= 'a' && ch <= 'f') ? (ch - 'a' + 10)
                                          : (ch - 'A' + 10);
        accumulator *= 16;  // 16 for hexadecimal
        accumulator += temp;
        // std::cout << "test again" << std::endl;
        break;
      default:
        throw SyntaxError();
    }
  }

  // if negative, return negative, otherwise return positve
  return negative ? -accumulator : accumulator;
}

int parseInt(const std::string &intString, const Format &format) {
  
}
