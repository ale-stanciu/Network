//
// Created by User on 5/22/2022.
//

#ifndef SDA_PROIECT_SERVICEFRIENDSHIP_H
#define SDA_PROIECT_SERVICEFRIENDSHIP_H


#include "../../Repo/RepoFriendship/RepoFriendship.h"

class ServiceFriendship {
private:
    RepoFriendship repoFriendship;
public:
    ServiceFriendship();
    ServiceFriendship(RepoFriendship &repoFriendship1);

    void add_friendship(Friendship friendship);
    void delete_friendship(Friendship friendship);
    Friendship get_friendship_by_id(int id);
    vector<Friendship> get_all_friendship();

    ~ServiceFriendship();
};


#endif //SDA_PROIECT_SERVICEFRIENDSHIP_H
