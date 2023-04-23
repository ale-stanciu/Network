//
// Created by User on 5/22/2022.
//

#include "RepoFriendship.h"
#include <iostream>

using namespace std;


RepoFriendship::RepoFriendship() = default;

void RepoFriendship::add_friendship(Friendship friendship) {
    list.add(friendship);
}


void RepoFriendship::delete_friendship(Friendship friendship) {
    list.deletee(friendship);
}

int RepoFriendship::get_size() {
    list.get_size();
}

Friendship RepoFriendship::get_friendship_by_id(int id) {
    for(auto &friendship: list.get_all()) {
        if(id == friendship.get_id())
            return friendship;
    }
    throw runtime_error("Id was not found!");
}

vector<Friendship> RepoFriendship::get_all_friendship() {
    return list.get_all();
}

RepoFriendship::~RepoFriendship() = default;
