//
// Created by User on 5/22/2022.
//

#ifndef SDA_PROIECT_SERVICEEVENT_H
#define SDA_PROIECT_SERVICEEVENT_H


#include "../../Repo/RepoEvent/RepoEvent.h"

class ServiceEvent {
private:
    RepoEvent repoEvent;
public:
    ServiceEvent();
    ServiceEvent(RepoEvent &repoEvent1);

    void add_event(Event event);
    void delete_event(Event event);
    vector<Event> get_all();

    ~ServiceEvent();
};


#endif //SDA_PROIECT_SERVICEEVENT_H
