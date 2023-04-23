//
// Created by User on 5/16/2022.
//

#include <vector>
#include <sstream>
#include "Friendship.h"

Friendship::Friendship() {
    this->id = 0;
    this->id_sender = 0;
    this->id_receiver = 0;
    this->status = "";
}

Friendship::Friendship(const Friendship& friendship){
    this->id = friendship.id;
    this->id_sender = friendship.id_sender;
    this->id_receiver = friendship.id_receiver;
    this->status = friendship.status;
}

Friendship::Friendship(int id, int id_sender, int id_receiver, string status) {
    this->id = id;
    this->id_sender = id_sender;
    this->id_receiver = id_receiver;
    this->status = move(status);
}

int Friendship::get_id() const {
    return this->id;
}

int Friendship::get_id_sender() const {
    return this->id_sender;
}

int Friendship::get_id_receiver() const {
    return this->id_receiver;
}

string Friendship::get_status() const {
    return this->status;
}

void Friendship::set_id(int id) {
    this->id = id;
}

void Friendship::set_id_sender(int id_sender) {
    this->id_sender = id_sender;
}

void Friendship::set_id_receiver(int id_receiver) {
    this->id_receiver = id_receiver;
}

void Friendship::set_status(string status) {
    this->status = move(status);
}

Friendship& Friendship::operator=(const Friendship& friendship){
    this->set_id(friendship.id);
    this->set_id_sender(friendship.id_sender);
    this->set_id_receiver(friendship.id_receiver);
    this->set_status(friendship.status);
    return *this;
}

bool Friendship::operator==(const Friendship& friendship) const{
    return this->id == friendship.id && this->id_receiver == friendship.id_receiver &&
    this->id_sender == friendship.id_sender && this->status == friendship.status;
}

istream &operator>>(istream &istream1, Friendship &friendship) {
    int id;
    cout << "Friendship id: ";
    istream1 >> id;
    friendship.id = id;

    int id1;
    cout << "First user id: ";
    istream1 >> id1;
    friendship.id_sender = id1;

    int id2;
    cout << "Second user id: ";
    istream1 >> id2;
    friendship.id_receiver = id2;

    return istream1;
}

ostream &operator<<(ostream &os, const Friendship &friendship) {
    os << "id: " << friendship.id << " id_sender: " << friendship.id_sender << " id_receiver: "
       << friendship.id_receiver << " status: " << friendship.status << endl;
    return os;
}

Friendship::Friendship(string args) {
    this->from_string(args);
}

void Friendship::from_string(string args, char delimiter){
    vector<string> elements;
    stringstream ss(args);
    string item;
    while(getline(ss,item,delimiter)){
        elements.push_back(item);
    }
    if(elements.size() == 4) {
        stringstream id(elements[0]);
        id >> this->id;
        stringstream sender(elements[1]);
        sender >> this->id_sender;
        stringstream receiver(elements[2]);
        receiver >> this->id_receiver;
        stringstream status(elements[3]);
        status >> this->status;
    }
}

Friendship::~Friendship() = default;
