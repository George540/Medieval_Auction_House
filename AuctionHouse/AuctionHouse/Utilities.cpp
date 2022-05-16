#include <algorithm>
#include <string>
#include "Utilities.h"

bool EqualsIgnoreCase(const std::string& str1, const std::string& str2)
{
    return str1.size() == str2.size() && std::equal(str1.begin(), str1.end(), str2.begin(), [](auto a, auto b) {return std::tolower(a) == std::tolower(b); });
}

bool ContainsSubstrictIgnoreCase(std::string str1, std::string str2)
{
    // turn str1 to lower case
    std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);

    // turn str2 to lower case
    std::transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    // find if l1 contains l2 with case insensitive, since all characters are lowercase
    return str1.find(str2) != std::string::npos;
}