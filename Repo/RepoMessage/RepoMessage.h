//
// Created by User on 5/22/2022.
//

#ifndef SDA_PROIECT_REPOMESSAGE_H
#define SDA_PROIECT_REPOMESSAGE_H


#include "../../Domain/List/List.h"
#include "../../Domain/Message/Message.h"
#include <iostream>

using namespace std;

class RepoMessage {
private:
    List<Message> list;
public:
    RepoMessage();

    void add_message(Message message);
    void delete_message(Message message);
    int get_size();
    vector<Message> get_all();

    ~RepoMessage();
};


#endif //SDA_PROIECT_REPOMESSAGE_H
