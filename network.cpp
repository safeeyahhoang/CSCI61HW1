#include "network.h"
#include <algorithm>
#include <cctype>
#include <iostream>

Network::Network() { }

Network::~Network() { }

std::string Network::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return str;
    size_t end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end);
}
