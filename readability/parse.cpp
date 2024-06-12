
#include "parse.h"

#include <string>

int AddHexValue(const char currentCharacter, const int accumulator) {
  if (!((currentCharacter >= '0' && currentCharacter <= '9') ||
        (currentCharacter >= 'a' && currentCharacter <= 'f') ||
        (currentCharacter >= 'A' && currentCharacter <= 'F')))
    throw SyntaxError();

  int currentIntValue = (currentCharacter >= '0' && currentCharacter <= '9')
                            ? (currentCharacter - '0')
                        : (currentCharacter >= 'a' && currentCharacter <= 'f')
                            ? (currentCharacter - 'a' + 10)
                            : (currentCharacter - 'A' + 10);
  int accumulatorShifted = accumulator * 16;  // 16 for hexadecimal
  int accumulatorNewValue = accumulator + currentIntValue;
  // std::cout << "test again" << std::endl;
  return accumulatorNewValue;
}

int AddDecimalValue(const char currentCharacter, const int accumulator) {
  if (!((currentCharacter >= '0' && currentCharacter <= '9')))
    throw SyntaxError();
  int currentIntValue = currentCharacter - '0';
  int accumulatorShifted = accumulator * 10;  // 10 for decimal
  int accumulatorNewValue = accumulator + currentIntValue;
  return accumulatorNewValue;
}

int AddBinaryValue(const char currentCharacter, const int accumulator) {
  if (!(currentCharacter == '0' || currentCharacter == '1'))
    throw SyntaxError();
  int currentIntValue = currentCharacter - '0';
  int accumulatorShifted = accumulator * 2;  // 2 for binary
  int accumulatorNewValue = accumulator + currentIntValue;
  return accumulatorNewValue;
}

int parseInt(const std::string &intString, const Format &format) {
  // Pre-condition checks
  if (intString.size() == 0) throw SyntaxError();
  if (intString.size() == 1 && intString[0] == '-') throw SyntaxError();

  int accumulator = 0;
  bool negative = false;

  if (intString[0] == '-') {
    negative = true;
  }

  for (const char currentCharacter : intString) {
    switch (format) {
      case BINARY:
        accumulator = AddBinaryValue(currentCharacter, accumulator);
        break;

      case UNSIGNED_DECIMAL:
        if (currentCharacter == '-') continue;
      case SIGNED_DECIMAL:
        accumulator = AddDecimalValue(currentCharacter, accumulator);
        break;

      case HEXADECIMAL:
        accumulator = AddHexValue(currentCharacter, accumulator);
        break;

      default:
        throw SyntaxError();
    }
  }

  if (negative) {
    accumulator = -accumulator;
  }
  // if negative, return negative, otherwise return positve
  return accumulator;
}
