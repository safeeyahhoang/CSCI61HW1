#include "network.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cctype>

Network::Network() { }

Network::~Network() {
    for (auto u : users_) {
        delete u;
    }
    users_.clear();
}

// take space and tab away from front and end
std::string Network::trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\r\n");
    if (start == std::string::npos) return "";
    size_t end = str.find_last_not_of(" \t\r\n");
    return str.substr(start, end - start + 1);
}

User* Network::getUser(int id) {
    if (id < 0 || id >= static_cast<int>(users_.size())) {
        return nullptr;
    }
    return users_[id];
}

void Network::addUser(User* u) {
    users_.push_back(u);
}

int Network::getId(std::string name) {
    name = trim(name);
    for (size_t i = 0; i < users_.size(); i++) {
        if (trim(users_[i]->getName()) == name) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

int Network::addConnection(std::string s1, std::string s2) {
    int id1 = getId(s1);
    int id2 = getId(s2);
    if (id1 == -1 || id2 == -1 || id1 == id2) {
        return -1;
    }
    users_[id1]->addFriend(id2);
    users_[id2]->addFriend(id1);
    return 0;
}

int Network::deleteConnection(std::string s1, std::string s2) {
    int id1 = getId(s1);
    int id2 = getId(s2);
    if (id1 == -1 || id2 == -1) {
        return -1;
    }
    users_[id1]->deleteFriend(id2);
    users_[id2]->deleteFriend(id1);
    return 0;
}

int Network::numUsers() {
    return static_cast<int>(users_.size());
}

void Network::readUsers(const char* fname) {
    std::ifstream file(fname);
    if (!file) {
        std::cerr << "error: cannot open file " << fname << std::endl;
        return;
    }

    // delete old data before read new
    for (auto u : users_) delete u;
    users_.clear();

    int num;
    file >> num;
    file.ignore();

    for (int i = 0; i < num; i++) {
        int id, year, zip;
        std::string nameLine, name;
        std::set<int> friends;

        if (!(file >> id)) break;
        file.ignore();

        std::getline(file, nameLine);
        name = trim(nameLine);

        if (!(file >> year >> zip)) break;
        file.ignore();

        std::string line;
        std::getline(file, line);
        std::stringstream ss(line);
        int f;
        while (ss >> f) {
            friends.insert(f);
        }

        User* u = new User(id, name, year, zip, friends);
        users_.push_back(u);
    }
}

void Network::writeUsers(const char* fname) {
    std::ofstream file(fname);
    if (!file) {
        std::cerr << "error: cannot write file " << fname << std::endl;
        return;
    }

    file << users_.size() << std::endl;
    for (size_t i = 0; i < users_.size(); i++) {
        User* u = users_[i];
        file << u->getId() << std::endl;
        file << "\t" << u->getName() << std::endl;
        file << "\t" << u->getYear() << std::endl;
        file << "\t" << u->getZip() << std::endl;
        file << "\t";
        std::set<int>& friends = u->getFriends();
        for (auto it = friends.begin(); it != friends.end(); ++it) {
            file << *it;
            if (std::next(it) != friends.end()) {
                file << " ";
            }
        }
        file << std::endl;
    }
}
