
#pragma once

#include <string>

enum Format { BINARY, UNSIGNED_DECIMAL, SIGNED_DECIMAL, HEXADECIMAL };
class SyntaxError {};

int parseInt(const std::string &intString, const Format &format);

void parseBinary(const char ch, int &temp, int &accumulator);

void parseUnsignedDecimal(const char ch, int &temp, int &accumulator);

void parseSignedDecimal(const char ch, int i, int &temp, int &accumulator, bool &negative);

void parseHexadecimal(const char ch, int &temp, int &accumulator);
