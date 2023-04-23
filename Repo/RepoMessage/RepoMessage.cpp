//
// Created by User on 5/22/2022.
//

#include "RepoMessage.h"

RepoMessage::RepoMessage() = default;

void RepoMessage::add_message(Message message) {
    list.add(message);
}

void RepoMessage::delete_message(Message message) {
    list.deletee(message);
}

int RepoMessage::get_size() {
    return list.get_size();
}

vector<Message> RepoMessage::get_all() {
    return list.get_all();
}

RepoMessage::~RepoMessage() = default;
