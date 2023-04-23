//
// Created by User on 5/21/2022.
//

#ifndef SDA_PROIECT_REPOUSER_H
#define SDA_PROIECT_REPOUSER_H


#include "../../Domain/List/List.h"
#include "../../Domain/User/User.h"
#include <vector>
#include <iostream>

using namespace std;

class RepoUser {
private:
    List<User> users;
public:
    RepoUser();

    void add_user(User user);
    void delete_user(User user);
    void update_user(User old_user, User new_user);
    int get_size();
    List<User> get_all_list();
    User get_by_id_user(int  id);
    vector<User> get_all_vector();

    ~RepoUser();
};


#endif //SDA_PROIECT_REPOUSER_H
