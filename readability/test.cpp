#include <cassert>
#include <iostream>

#include "parse.h"

void testParseValid(const std::string &intString, const Format &format,
                    int expectedValue) {
  try {
    int result = parseInt(intString, format);
    assert(result == expectedValue);
    std::cout << "Test passed for input \"" << intString << "\"" << std::endl;
  } catch (const SyntaxError &e) {
    std::cerr << "Caught SyntaxError for input \"" << intString << "\""
              << std::endl;
  }
}

void testParseError(const std::string &intString, const Format &format) {
  try {
    parseInt(intString, format);
    std::cerr << "Expected SyntaxError for input \"" << intString << "\""
              << std::endl;
  } catch (const SyntaxError &e) {
    std::cout << "Correctly caught SyntaxError for input \"" << intString
              << "\"" << std::endl;
  }
}

int main() {
  testParseValid("101", BINARY, 5);
  testParseValid("10", UNSIGNED_DECIMAL, 10);
  testParseValid("-10", SIGNED_DECIMAL, -10);
  testParseValid("1a", HEXADECIMAL, 26);

  testParseError("", BINARY);
  testParseError("-1", BINARY);
  testParseError("2", BINARY);
  testParseError("a", BINARY);
  testParseError("-1", UNSIGNED_DECIMAL);
  testParseError("1.0", UNSIGNED_DECIMAL);
  testParseError("-", SIGNED_DECIMAL);
  testParseError("--", SIGNED_DECIMAL);
  testParseError("1-", SIGNED_DECIMAL);
  testParseError("a", SIGNED_DECIMAL);
  testParseError("-1", HEXADECIMAL);
  testParseError("1g", HEXADECIMAL);
  testParseError("12x", HEXADECIMAL);

  return 0;
}
