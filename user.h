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
    // pre: none
    // post: make one user, use default year=1934 and zip=89591
    User();

    // pre: none
    // post: make user with info given by parameter
    User(int id, std::string name, int year, int zip, std::set<int> friends);

    // pre: none
    // post: return id of user
    int getId() const;

    // pre: none
    // post: return name of user
    std::string getName() const;

    // pre: none
    // post: return year born of user
    int getYear() const;

    // pre: none
    // post: return zip number of user
    int getZip() const;

    // pre: none
    // post: return friend list (can change it)
    std::set<int>& getFriends();

    // pre: none
    // post: add new friend id if not there yet
    void addFriend(int id);

    // pre: none
    // post: delete friend id if already in list
    void deleteFriend(int id);
};

#endif // USER_H
