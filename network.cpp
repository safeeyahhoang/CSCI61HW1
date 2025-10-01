#include "network.h"
#include <algorithm>
#include <cctype>

Network::Network() {}
Network::~Network() {
    for (auto u : users_) delete u;
    users_.clear();
}

std::string Network::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end - start + 1);
}

User* Network::getUser(int id) {
    if (id < 0 || id >= static_cast<int>(users_.size())) return nullptr;
    return users_[id];
}

void Network::addUser(User* u) {
    users_.push_back(u);
}

int Network::getId(std::string name) {
    name = trim(name);
    for (size_t i = 0; i < users_.size(); i++)
        if (trim(users_[i]->getName()) == name) return static_cast<int>(i);
    return -1;
}
