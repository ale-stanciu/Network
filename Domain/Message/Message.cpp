//
// Created by User on 5/20/2022.
//

#include <vector>
#include <sstream>
#include "Message.h"

Message::Message() {
    this->id = 0;
    this->id_sender = 0;
    this->id_receiver = 0;
    this->text = "";
}

Message::Message(const Message& message) {
    this->id = message.id;
    this->id_sender = message.id_sender;
    this->id_receiver = message.id_receiver;
    this->text = message.text;
}

Message::Message(int id, int id_sender, int id_receiver, string text) {
    this->id = id;
    this->id_sender = id_sender;
    this->id_receiver = id_receiver;
    this->text = move(text);
}

int Message::get_id() const {
    return this->id;
}

int Message::get_id_sender() const {
    return this->id_sender;
}

int Message::get_id_receiver() const {
    return this->id_receiver;
}

string Message::get_text() const {
    return this->text;
}

void Message::set_id(int id) {
    this->id = id;
}

void Message::set_id_sender(int id_sender) {
    this->id_sender = id_sender;
}

void Message::set_id_receiver(int id_receiver) {
    this->id_receiver = id_receiver;
}

void Message::set_text(string text) {
    this->text = text;
}

Message &Message::operator=(const Message &message) {
    this->set_id(message.id);
    this->set_id_sender(message.id_sender);
    this->set_id_receiver(message.id_receiver);
    this->set_text(message.text);
    return *this;
}

bool Message::operator==(const Message &message) const {
    return this->id == message.id && this->id_receiver == message.id_receiver && this->id_sender == message.id_sender
    && this->text == message.text;
}

istream &operator>>(istream &istream1, Message& message) {
    int id;
    cout << "Message id: ";
    istream1 >> id;
    message.id = id;

    int id1;
    cout << "First user id: ";
    istream1 >> id1;
    message.id_sender = id1;

    int id2;
    cout << "Second user id: ";
    istream1 >> id2;
    message.id_receiver = id2;

    string text;
    cout << "Message: ";
    getline(istream1, text);
    getline(istream1, text);
    message.text = text;

    return istream1;
}

Message::Message(string args) {
    this->from_string(args);
}

void Message::from_string(string args, char delimiter) {
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
        stringstream text (elements[3]);
        string texts;

        getline(text, texts);
        this->set_text(texts);
    }
}

ostream &operator<<(ostream &os, const Message &message) {
    os << "id: " << message.id << " id_sender: " << message.id_sender << " id_receiver: " << message.id_receiver
       << " text: " << message.text << endl;
    return os;
}

Message::~Message() = default;


