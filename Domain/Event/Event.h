

#ifndef SDA_PROIECT_EVENT_H
#define SDA_PROIECT_EVENT_H


#include "../User/User.h"
#include <iostream>
using namespace std;

class Event {
private:
    int id;
    string name;
    int id_organizer;

public:
    Event();
    Event(const Event& event);
    Event(int id, string name, int id_organizer): id(id), name(move(name)), id_organizer(id_organizer) {}

    int get_id() const;
    const string &get_name() const;
    const string &get_location() const;
    const int &get_id_organizer() const;

    void set_id(int id);
    void set_name(string name);
    void set_location(string location);
    void set_id_organizer(int id_organizer);

    Event operator=(const Event& event);
    bool operator==(const Event& event);



    ~Event();

    Event(string args);
    void from_string(string args, char delimiter=',');
    friend istream &operator>>(istream &istream1, Event &event);
    friend ostream &operator<<(ostream &os, const Event &event);
};


#endif //SDA_PROIECT_EVENT_H
