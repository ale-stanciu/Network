//
// Created by User on 5/21/2022.
//


#include "RepoUser.h"
#include "../../Domain/User/User.h"

RepoUser::RepoUser() = default;

void RepoUser::add_user(User user) {
    users.add(user);
}

void RepoUser::delete_user(User user) {
    users.deletee(user);
}

void RepoUser::update_user(User old_user, User new_user) {
    users.update(old_user, new_user);
}

int RepoUser::get_size() {
    return users.get_size();
}

List<User> RepoUser::get_all_list() {
    return users;
}

User RepoUser::get_by_id_user(int id) {
    for(auto& user: users.get_all()) {
        if(id == user.get_id())
            return user;
    }
    throw runtime_error("The id was not found!");
}

vector<User> RepoUser::get_all_vector() {
    return users.get_all();
}

RepoUser::~RepoUser() = default;