//
// Created by User on 5/21/2022.
//

#include "RepoEvent.h"

RepoEvent::RepoEvent() = default;

void RepoEvent::add_event(Event event) {
    multimap.add(event.get_id(), event);
}

void RepoEvent::delete_event(Event event) {
    multimap.deleteKey(event.get_id(), event);
}

int RepoEvent::get_size() {
    return multimap.get_size();
}

vector<Event> RepoEvent::get_all_event() {
    return multimap.get_all();
}

RepoEvent::~RepoEvent() = default;
