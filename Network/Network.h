//
// Created by User on 5/25/2022.
//

#ifndef SDA_PROIECT_NETWORK_H
#define SDA_PROIECT_NETWORK_H


#include "../Service/ServiceUser/ServiceUser.h"
#include "../Service/ServiceFriendship/ServiceFriendship.h"
#include "../Service/ServiceMessage/ServiceMessage.h"
#include "../Service/ServiceEvent/ServiceEvent.h"
#include <iostream>
#include <fstream>

using namespace std;

class Network {
private:
    ServiceUser serviceUser;
    ServiceFriendship serviceFriendship;
    ServiceMessage serviceMessage;
    ServiceEvent serviceEvent;
public:

//    Network(ServiceUser user, ServiceFriendship friendship, ServiceMessage message, ServiceEvent event)
//            : serviceUser(), serviceFriendship(), serviceMessage(), serviceEvent() {}
    Network(): serviceUser(), serviceFriendship(), serviceMessage(), serviceEvent(){
        string line;
        ifstream user_file("../Domain/users.txt");
        while(getline(user_file, line)){
            User user(line);
            add_user(user);
        }
        ifstream friendship_file("../Domain/friends.txt");
        while(getline(friendship_file, line)){
            Friendship friendship(line);
            add_friendship(friendship);
        }
        ifstream message_file("../Domain/messages.txt");
        while (getline(message_file, line)) {
            Message message(line);
            add_message(message);
        }
        ifstream events_file("../Domain/events.txt");
        while (getline(events_file, line)) {
            Event event(line);
            add_event(line);
        }
}

    void add_user(User user) {
        serviceUser.add_user(user);
    }

    void delete_user(User user) {
        serviceUser.delete_user(user);
    }

    void update_user(User old_user, User new_user) {
        serviceUser.update_user(old_user, new_user);
    }

    vector<User> get_all_user() {
        return serviceUser.get_all();
    }

    User get_by_id(int id){
       return serviceUser.get_by_id(id);
    }

    void add_friendship(Friendship friendship) {
        serviceFriendship.add_friendship(friendship);
    }

    void delete_friendship(Friendship friendship) {
        serviceFriendship.delete_friendship(friendship);
    }

    vector<Friendship> get_all_friendship(){
        return serviceFriendship.get_all_friendship();
    }

    Friendship get_by_id_friendship(int id){
        return serviceFriendship.get_friendship_by_id(id);
    }

    void add_message(Message message) {
        serviceMessage.add_message(message);
    }

    void delete_message(Message message) {
        serviceMessage.delete_message(message);
    }

    vector<Message> get_all_message() {
        return serviceMessage.get_all_message();
    }

    int get_size_message() {
        return serviceMessage.message_size();
    }

    void add_event(Event event) {
        serviceEvent.add_event(event);
    }

    void delete_event(Event event) {
        serviceEvent.delete_event(event);
    }

    vector<Event> get_all_event() {
       return serviceEvent.get_all();
    }


    ~Network() {

    }
};


#endif //SDA_PROIECT_NETWORK_H
