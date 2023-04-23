#ifndef SDA_PROIECT_REPOEVENT_H
#define SDA_PROIECT_REPOEVENT_H


#include "../../Domain/Multimap/Multimap.h"
#include "../../Domain/Event/Event.h"

class RepoEvent {
private:
    Multimap<int, Event> multimap;
public:
    RepoEvent();

    void add_event(Event event);
    void delete_event(Event event);
    int get_size();
    Event get_by_id();
    vector<Event> get_all_event();

    ~RepoEvent();
};


#endif //SDA_PROIECT_REPOEVENT_H
