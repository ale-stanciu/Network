//
// Created by User on 5/22/2022.
//

#ifndef SDA_PROIECT_REPOFRIENDSHIP_H
#define SDA_PROIECT_REPOFRIENDSHIP_H


#include "../../Domain/List/List.h"
#include "../../Domain/Friendship/Friendship.h"

class RepoFriendship {
private:
    List<Friendship> list;
public:
    RepoFriendship();

    void add_friendship(Friendship friendship);
    void delete_friendship(Friendship friendship);
    int get_size();
    Friendship get_friendship_by_id(int id);
    vector<Friendship> get_all_friendship();

    ~RepoFriendship();
};


#endif //SDA_PROIECT_REPOFRIENDSHIP_H
