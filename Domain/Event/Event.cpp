
#include <vector>
#include <sstream>
#include "Event.h"

Event::Event() {
    this->id = 0;
    this->name = "";
    this->id_organizer = 0;
}

Event::Event(const Event &event) {
    this->id = event.id;
    this->name = event.name;
    this->id_organizer = event.id_organizer;
}

int Event::get_id() const {
    return this->id;
}

const string &Event::get_name() const {
    return this->name;
}

const int &Event::get_id_organizer() const {
    return this->id_organizer;
}

void Event::set_id(int id) {
    this->id = id;
}

void Event::set_name(string name) {
    this->name = move(name);
}


void Event::set_id_organizer(int id_organizer) {
    this->id_organizer = id_organizer;
}

Event Event::operator=(const Event &event) {
    this->id = event.id;
    this->id_organizer = event.id_organizer;
    this->name = event.name;
    return *this;
}

bool Event::operator==(const Event &event) {
    return ((this->name == event.name) and (this->id_organizer == event.id_organizer));
}

Event::Event(string args) {
    this->from_string(args);
}

istream &operator>>(istream &istream1, Event &event) {
    int id;
    cout << "Enter id: ";
    istream1 >> id;
    event.id = id;

    string ename;
    cout << "Enter name event: ";
    istream1 >> ename;
    event.name = ename;

    int org;
    cout << "Enter organizer id: ";
    istream1 >> org;
    event.id_organizer = org;
    return istream1;
}

ostream &operator<<(ostream &os, const Event &event) {
    os << "id: " << event.id << " name: " << event.name << " id_organizer: " << event.id_organizer << endl;
    return os;
}

void Event::from_string(string args, char delimiter) {
    vector<string> elements;
    stringstream ss(args);
    string item;
    while(getline(ss,item,delimiter)){
        elements.push_back(item);
    }
    if(elements.size() == 3) {
        stringstream id(elements[0]);
        id >> this->id;
        stringstream name(elements[1]);
        name >> this->name;
        stringstream organizer(elements[2]);
        organizer >> this->id_organizer;
    }
}


Event::~Event() = default;
