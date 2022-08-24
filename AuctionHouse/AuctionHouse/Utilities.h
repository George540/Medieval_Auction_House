#pragma once

#include "Utilities.h"
#include <string>
#include "Item.h"

bool EqualsIgnoreCase(const std::string s1, const std::string s2);
bool ContainsSubstrictIgnoreCase(std::string str1, std::string str2);

bool CompareItemsPriceIncreasing(const Item i1, const Item i2);
bool CompareItemsPriceDecreasing(const Item i1, const Item i2);
bool CompareItemsAlphabeticallyIncreasing(const Item i1, const Item i2);
bool CompareItemsAlphabeticallyDecreasing(const Item i1, const Item i2);

void DeleteLineFromSelectedFile(std::string path, std::string filename, std::string deleteLine);