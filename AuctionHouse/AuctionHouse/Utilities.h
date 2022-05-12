#pragma once

#include "Utilities.h"
#include <string>

static bool EqualsIgnoreCase(const std::string& s1, const std::string& s2);
static bool ContainsInsensitiveString(const std::string& s1, const std::string& s2);
static char asciiToLower(char c);