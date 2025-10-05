#ifndef NETWORK_H
#define NETWORK_H

#include <vector>
#include <string>
#include "user.h"

class Network {
private:
    std::vector<User*> users_;

    // take out extra space or tab from string
    std::string trim(const std::string& str);

public:
    // pre: none
    // post: make empty network
    Network();

    // pre: none
    // post: free all user memory
    ~Network();

    // pre: id must be real in user list
    // post: return pointer to user, or nullptr if wrong id
    User* getUser(int id);

    // pre: user pointer is not null
    // post: add user in the network
    void addUser(User* u);

    // pre: both user name exist
    // post: make both friend; return -1 if error
    int addConnection(std::string s1, std::string s2);

    // pre: both user name exist
    // post: remove both from friend; return -1 if error
    int deleteConnection(std::string s1, std::string s2);

    // pre: none
    // post: return id number from name, or -1 if not found
    int getId(std::string name);

    // pre: none
    // post: return how many user in network
    int numUsers();

    // pre: file name must be right
    // post: read all user info from file and put in network
    void readUsers(const char* fname);

    // pre: none
    // post: write all user info to file
    void writeUsers(const char* fname);
};

#endif // NETWORK_H