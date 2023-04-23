//
// Created by User on 5/20/2022.
//

#ifndef SDA_PROIECT_MESSAGE_H
#define SDA_PROIECT_MESSAGE_H

#include <string>
#include <iostream>

using namespace std;

class Message {
private:
    int id;
    int id_sender;
    int id_receiver;
    string text;

public:
    Message();
    Message(const Message& message);
    Message(int id, int id_sender, int id_receiver, string text);

    int get_id() const;
    int get_id_sender() const;
    int get_id_receiver() const;
    string get_text() const;

    void set_id(int id);
    void set_id_sender(int id_sender);
    void set_id_receiver(int id_receiver);
    void set_text(string text);

    Message& operator=(const Message& message);
    bool operator==(const Message& message) const;

    friend istream  &operator>>(istream &istream1, Message& message);
        ~Message();

    void from_string(string args, char delimiter=',');
    Message(string args);

    friend ostream &operator<<(ostream &os, const Message &message);
};


#endif //SDA_PROIECT_MESSAGE_H
