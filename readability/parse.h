
#pragma once

#include <string>

enum Format { BINARY, UNSIGNED_DECIMAL, SIGNED_DECIMAL, HEXADECIMAL };
class SyntaxError {};

int parseInt(const std::string &intString, const Format &format);
