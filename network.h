#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <string>
#include "user.h"

class Network {
private:
    std::vector<User*> users_;
    std::string trim(const std::string& str);

public:
    Network();
    ~Network();
    User* getUser(int id);
    void addUser(User* u);
    int addConnection(std::string s1, std::string s2);
    int deleteConnection(std::string s1, std::string s2);
    int getId(std::string name);
    int numUsers();
    void readUsers(const char* fname);
    void writeUsers(const char* fname);
};

#endif
