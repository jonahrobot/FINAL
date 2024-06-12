
#include <string>
#include "parse.h"

int parseInt_OLD(const std::string &intString, const Format &format) {

  // Pre-condition checks
  if (intString.size() == 0) throw SyntaxError();
  if (intString.size() == 1 && intString[0] == '-') throw SyntaxError();
  
  int accumulator = 0;
  bool negative = false;

  if(intString[0] == '-'){
    negative = true;
  }

  for(const char currentCharacter: intString){

    switch (format) {
      case BINARY:
        parseBinary(currentCharacter, accumulator);
        break;

      case UNSIGNED_DECIMAL:
        parseDecimal(currentCharacter, accumulator);
        break;

      case SIGNED_DECIMAL:
        parseDecimal(currentCharacter,accumulator);
        break;

      case HEXADECIMAL:
        parseHexadecimal(currentCharacter, accumulator);
        break;
        
      default:
        throw SyntaxError();
    }
  }

  // if negative, return negative, otherwise return positve
  return negative ? -accumulator : accumulator;
}

void parseHexadecimal(const char ch, int &accumulator)
{
  if (!((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'f') ||
        (ch >= 'A' && ch <= 'F')))
    throw SyntaxError();

  int currentIntValue = (ch >= '0' && ch <= '9')   ? (ch - '0')
         : (ch >= 'a' && ch <= 'f') ? (ch - 'a' + 10)
                                    : (ch - 'A' + 10);
  accumulator *= 16; // 16 for hexadecimal
  accumulator += currentIntValue;
  // std::cout << "test again" << std::endl;
}

void parseDecimal(const char ch, int &accumulator)
{
  if (!((ch >= '0' && ch <= '9')))
    throw SyntaxError();
  int currentIntValue = ch - '0';
  accumulator *= 10; // 10 for decimal
  accumulator += currentIntValue;
}


void parseBinary(const char ch, int &accumulator)
{
  if (!(ch == '0' || ch == '1'))
    throw SyntaxError();
  int currentIntValue = ch - '0';
  accumulator *= 2; // 2 for binary
  accumulator += currentIntValue;
}

int parseInt(const std::string &intString, const Format &format) {
  
}
