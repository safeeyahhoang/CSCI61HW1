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

User* Network::getUser(int id) {
    if (id < 0 || id >= users_.size()) return nullptr;
    return users_[id];
}

void Network::addUser(User* u) {
    users_.push_back(u); 
}

int Network::getId(std::string name) {
    for (size_t i = 0; i < users_.size(); i++)
        if (users_[i]->getName() == name) return i;
    return -1;
}
