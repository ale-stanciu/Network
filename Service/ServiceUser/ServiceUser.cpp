//
// Created by User on 5/22/2022.
//

#include "ServiceUser.h"

ServiceUser::ServiceUser() = default;

ServiceUser::ServiceUser(RepoUser &repoUser1): repoUser(repoUser1) {}

void ServiceUser::add_user(User user) {
    repoUser.add_user(user);
}

void ServiceUser::delete_user(User user) {
    repoUser.delete_user(user);
}

void ServiceUser::update_user(User old_user, User new_user) {
    repoUser.update_user(old_user, new_user);
}

vector<User> ServiceUser::get_all() {
    return repoUser.get_all_vector();
}

User ServiceUser::get_by_id(int id) {
    return repoUser.get_by_id_user(id);
}


ServiceUser::~ServiceUser() = default;


