#ifndef SDA_PROIECT_SERVICEMESSAGE_H
#define SDA_PROIECT_SERVICEMESSAGE_H


#include "../../Repo/RepoMessage/RepoMessage.h"

class ServiceMessage {
private:
    RepoMessage repoMessage;
public:
    ServiceMessage();
    ServiceMessage(RepoMessage &repoMessage1);

    void add_message(Message message);
    void delete_message(Message message);
    vector<Message> get_all_message();
    int message_size();

    ~ServiceMessage();
};


#endif //SDA_PROIECT_SERVICEMESSAGE_H
