#include <algorithm>
#include <string>
#include "Utilities.h"
#include <fstream>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

bool EqualsIgnoreCase(const std::string str1, const std::string str2)
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

bool CompareItemsPriceIncreasing(const Item i1, const Item i2)
{
    if (i1.getBuy() == i2.getBuy()) {
        return CompareItemsAlphabeticallyIncreasing(i1, i2);
    }
    return i1.getBuy() < i2.getBuy();
}

bool CompareItemsPriceDecreasing(const Item i1, const Item i2)
{
    if (i1.getBuy() == i2.getBuy()) {
        return CompareItemsAlphabeticallyDecreasing(i1, i2);
    }
    return i1.getBuy() > i2.getBuy();
}

bool CompareItemsAlphabeticallyIncreasing(const Item i1, const Item i2)
{
    if (i1.getName() == i2.getName()) {
        return CompareItemsPriceIncreasing(i1, i2);
    }
    return i1.getName() < i2.getName();
}

bool CompareItemsAlphabeticallyDecreasing(const Item i1, const Item i2)
{
    if (i1.getName() == i2.getName()) {
        return CompareItemsPriceDecreasing(i1, i2);
    }
    return i1.getName() > i2.getName();
}

void DeleteLineFromSelectedFile(std::string path, std::string filename, std::string deleteLine)
{
    fs::path current_path = path;
    std::cout << fs::absolute(current_path) << std::endl;
    auto current_path_string = fs::absolute(current_path).string();
    std::cout << current_path_string << std::endl;
    std::string fileNamePath = path + filename;
    std::string tempNamePath = path + "temp.txt";

    std::ifstream fin;
    fin.open(fileNamePath);
    std::ofstream temp;
    temp.open(tempNamePath);

    std::string line;

    while (getline(fin, line)) {
        auto position = line.find(deleteLine);

        if (position != std::string::npos) {
            line.replace(line.find(deleteLine), deleteLine.length(), " ");
        }

        if (!line.empty() && line != deleteLine && line != " ") {
            temp << line << std::endl;
        }
    }

    temp.close();
    fin.close();

    auto c = current_path_string + filename;
    std::cout << c << std::endl;
    auto success = remove(c.c_str());
    if (success == 0) {
        std::cout << "SUCCESS1" << std::endl;
    }
    else {
        perror("ERROR MAN");
        std::cout << "FAILURE1" << std::endl;
    }
    fs::path t = "temp.txt";
    success = std::rename(tempNamePath.c_str(), fileNamePath.c_str());
    if (success == 0) {
        std::cout << "SUCCESS2" << std::endl;
    }
    else {
        std::cout << "FAILURE2" << std::endl;
    }
}
