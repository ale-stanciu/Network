#include "ServiceMessage.h"


ServiceMessage::ServiceMessage() = default;

ServiceMessage::ServiceMessage(RepoMessage &repoMessage1) : repoMessage(repoMessage1) {}

void ServiceMessage::add_message(Message message) {
    repoMessage.add_message(message);
}

void ServiceMessage::delete_message(Message message) {
    repoMessage.delete_message(message);
}

vector<Message> ServiceMessage::get_all_message() {
    return repoMessage.get_all();
}

int ServiceMessage::message_size() {
    return repoMessage.get_size();
}


ServiceMessage::~ServiceMessage() = default;
