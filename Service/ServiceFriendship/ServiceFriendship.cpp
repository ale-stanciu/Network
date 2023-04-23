#include "ServiceFriendship.h"

ServiceFriendship::ServiceFriendship() = default;

ServiceFriendship::ServiceFriendship(RepoFriendship &repoFriendship1) : repoFriendship(repoFriendship1) {}


void ServiceFriendship::add_friendship(Friendship friendship) {
    repoFriendship.add_friendship(friendship);
}

void ServiceFriendship::delete_friendship(Friendship friendship) {
    repoFriendship.delete_friendship(friendship);
}

Friendship ServiceFriendship::get_friendship_by_id(int id) {
    return repoFriendship.get_friendship_by_id(id);
}

vector<Friendship> ServiceFriendship::get_all_friendship() {
    return repoFriendship.get_all_friendship();
}

ServiceFriendship::~ServiceFriendship() = default;
