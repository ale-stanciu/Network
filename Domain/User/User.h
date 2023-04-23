#ifndef SDA_PROIECT_USER_H
#define SDA_PROIECT_USER_H
#include<cstring>
#include<iostream>
using namespace std;



class User {
private:
    int id;
    string first_name;
    string last_name;
    string username;
    int age;

public:
    User();
    User(const User& user);
    User(int id1, string first_name1, string last_name1, string username1, int age1);

    int get_id();
    string get_First_name();
    string get_last_name();
    string get_username();
    int get_age();

    void set_id(int id1);
    void set_first_name(string first_name1);
    void set_last_name(string last_namee1);
    void set_username(string username1);
    void set_age(int age1);

    User &operator=(const User& user);
    bool operator==(const User& user);

    friend istream &operator>>(istream &istr, User &user);
        ~User();

    void from_string(string args, char delimiter=',');

    User(string args);

    friend ostream &operator<<(ostream &os, const User &user);
};


#endif //SDA_PROIECT_USER_H
