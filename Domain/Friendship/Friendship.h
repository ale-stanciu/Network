//
// Created by User on 5/16/2022.
//

#ifndef SDA_PROIECT_FRIENDSHIP_H
#define SDA_PROIECT_FRIENDSHIP_H
#include <string>
#include <iostream>

using namespace std;

class Friendship {
private:

    int id;
    int id_sender;
    int id_receiver;
    string status;

public:

    Friendship();
    Friendship(const Friendship& friendship);
    Friendship(int id, int id_sender, int id_receiver, string status);

    int get_id() const;
    int get_id_sender() const;
    int get_id_receiver() const;
    string get_status() const;

    void set_id(int id);
    void set_id_sender(int id_sender);
    void set_id_receiver(int id_receiver);
    void set_status(string status);

    ~Friendship();

    Friendship& operator=(const Friendship& friendship);
    bool operator==(const Friendship& friendship) const;

    friend istream &operator>>(istream &istream1, Friendship& friendship);
        void from_string(string args, char delimiter=',');

    Friendship(string args);

    friend ostream &operator<<(ostream &os, const Friendship &friendship);
};


#endif //SDA_PROIECT_FRIENDSHIP_H
