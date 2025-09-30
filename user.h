#ifndef USER_H
#define USER_H

#include <string>
#include <set>

class User {
private:
    int id_;
    std::string name_;
    int year_;
    int zip_;
    std::set<int> friends_;

public:
    User();
    User(int id, std::string name, int year, int zip, std::set<int> friends);
    int getId() const;
    std::string getName() const;
    int getYear() const;
    int getZip() const;
    std::set<int>& getFriends();
    void addFriend(int id);
    void deleteFriend(int id);
};

#endif
