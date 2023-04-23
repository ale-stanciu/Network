#include <vector>
#include <sstream>
#include "User.h"

User::User() {
    this->id = 0;
    this->first_name = "";
    this->last_name = "";
    this->username = "";
    this->age = 0;
}

User::User(const User &user) {
    this->id = user.id;
    this->first_name = user.first_name;
    this->last_name = user.last_name;
    this->username = user.username;
    this->age = user.age;
}

User::User(int id1, string first_name1, string last_name1, string username1, int age1) {
    this->id = id1;
    this->first_name = move(first_name1);
    this->last_name = move(last_name1);
    this->username = move(username1);
    this->age = age1;
}

int User::get_id() {
    return this->id;
}

string User::get_First_name() {
    return this->first_name;
}

string User::get_last_name() {
    return this->last_name;
}

string User::get_username() {
    return this->username;
}

int User::get_age() {
    return this->age;
}


void User::set_id(int id1) {
    this->id = move(id1);
}

void User::set_first_name(string first_name1) {
    this->first_name = move(first_name1);
}

void User::set_last_name(string last_name1) {
    this->last_name = move(last_name1);
}

void User::set_username(string username1) {
    this->username = move(username1);
}

void User::set_age(int age1) {
    this->age = move(age1);
}

User &User::operator=(const User &user) {
    this->set_id(user.id);
    this->set_first_name(user.first_name);
    this->set_last_name(user.last_name);
    this->set_username(user.username);
    this->set_age(user.age);
    return *this;
}

bool User::operator==(const User &user) {
    return ((this->first_name == user.first_name) and (this->last_name == user.last_name) and
    (this->username == user.username) and (this->age == user.age));
}

istream &operator>>(istream &istr, User &user)
{
    int idd;
    cout << "Enter id: ";
    istr >> idd;
    user.id = idd;

    string fn;
    cout << "Enter first name: ";
    istr >> fn;
    user.first_name = fn;

    string ln;
    cout << "Enter last name: ";
    istr >> ln;
    user.last_name = ln;

    string un;
    cout << "Enter username: ";
    istr >> un;
    user.username = un;

    int ag;
    cout << "Enter age: ";
    istr >> ag;
    user.age = ag;

    return istr;
}

User::User(string args){
    this->from_string(args);
}
void User::from_string(string args, char delimiter){
    vector<string> elements;
    stringstream ss(args);
    string item;
    while(getline(ss,item,delimiter)){
        elements.push_back(item);
    }
    if(elements.size()==5){
        stringstream id(elements[0]);
        id >> this->id;
        stringstream fname(elements[1]);
        fname >> this->first_name;
        stringstream lname(elements[2]);
        lname >> this->last_name;
        stringstream username(elements[3]);
        username >> this->username;
        stringstream age(elements[4]);
        age >> this->age;
    }
}

ostream &operator<<(ostream &os, const User &user) {
    os << "id: " << user.id << " first_name: " << user.first_name << " last_name: " << user.last_name << " username: "
       << user.username << " age: " << user.age << endl;
    return os;
}

User::~User() {
    this->id = 0;
    this->first_name = "";
    this->last_name = "";
    this->username = "";
    this->age = 0;
}
