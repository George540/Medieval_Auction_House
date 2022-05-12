#include <algorithm>
#include <string>
#include "Utilities.h"

static bool EqualsIgnoreCase(const std::string& str1, const std::string& str2)
{
    return str1.size() == str2.size() && std::equal(str1.begin(), str1.end(), str2.begin(), [](auto a, auto b) {return std::tolower(a) == std::tolower(b); });
}

static bool ContainsInsensitiveString(const std::string& str1, const std::string& str2)
{
    // turn str1 to lower case
    std::string l1;
    l1.resize(str1.size());
    std::transform(str1.begin(), str1.end(), l1.begin(), asciiToLower);

    // turn str2 to lower case
    std::string l2;
    l2.resize(str1.size());
    std::transform(str2.begin(), str2.end(), l2.begin(), asciiToLower);

    // find if l1 contains l2 with case insensitive, since all characters are lowercase
    return std::find(l1.begin(), l1.end(), l2) != std::end(l1);
}

// Sets character to lower case (predicate helper function)
char asciiToLower(char c) {
    if (c <= 'Z' && c >= 'A')
        return c - ('Z' - 'z');
    return c;
}
