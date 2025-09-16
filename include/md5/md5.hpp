#pragma once
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "export.hpp"

class SCANNERLIB_API MD5 {
public:
    MD5() = default;

    static std::string hashString(const std::string& input);

    static std::string hashFile(const std::string& filename);
};
