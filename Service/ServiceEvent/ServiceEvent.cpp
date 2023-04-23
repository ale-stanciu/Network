#include "ServiceEvent.h"

ServiceEvent::ServiceEvent() = default;

ServiceEvent::ServiceEvent(RepoEvent &repoEvent1) : repoEvent(repoEvent1) {}

void ServiceEvent::add_event(Event event) {
    repoEvent.add_event(event);
}

void ServiceEvent::delete_event(Event event) {
    repoEvent.delete_event(event);
}

vector<Event> ServiceEvent::get_all() {
    return repoEvent.get_all_event();
}


ServiceEvent::~ServiceEvent() = default;
