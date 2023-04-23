//
// Created by User on 5/22/2022.
//

#ifndef SDA_PROIECT_SERVICEUSER_H
#define SDA_PROIECT_SERVICEUSER_H


#include "../../Repo/RepoUser/RepoUser.h"
#include "../../Domain/User/User.h"
#include <vector>
#include<iostream>

using  namespace std;

class ServiceUser {
private:
    RepoUser repoUser;
public:
    ServiceUser();
    ServiceUser(RepoUser &repoUser1);

    void add_user(User user);
    void delete_user(User user);
    void update_user(User old_user, User new_user);
    vector<User> get_all();
    User get_by_id(int id);

    ~ServiceUser();
};


#endif //SDA_PROIECT_SERVICEUSER_H
