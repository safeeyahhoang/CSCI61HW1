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

int Network::addConnection(std::string s1, std::string s2) {
    int id1 = getId(s1), id2 = getId(s2);
    if (id1 == -1 || id2 == -1 || id1 == id2) return -1;
    users_[id1]->addFriend(id2);
    users_[id2]->addFriend(id1);
    return 0;
}

int Network::deleteConnection(std::string s1, std::string s2) {
    int id1 = getId(s1), id2 = getId(s2);
    if (id1 == -1 || id2 == -1) return -1;
    users_[id1]->deleteFriend(id2);
    users_[id2]->deleteFriend(id1);
    return 0;
}

int Network::numUsers() { return static_cast<int>(users_.size()); }

