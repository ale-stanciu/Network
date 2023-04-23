//
// Created by User on 5/25/2022.
//

#include "Console.h"
#include "../Network/Network.h"
#include "../Service/ServiceUser/ServiceUser.h"

Console::Console() = default;

void Console::run_menu_user() {
    int ok = 1;
    while (ok) {
        cout << endl;
        cout << "1. Add an user" << endl;
        cout << "2. Delete an user" << endl;
        cout << "3. Update an user" << endl;
        cout << "s. Show all users" << endl;
        cout << "x. Exit" << endl;

        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                ui_add_user();
                break;
            }
            case '2': {
                ui_delete_user();
                break;
            }
            case '3': {
                ui_update_user();
                break;
            }
            case 's': {
                for(int i = 0;i<this->network.get_all_user().size();i++){
                    cout << this->network.get_all_user()[i];
                }
                break;
            }
            case 'x': {
                ok = 0;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}


void Console::run_menu_friendship() {
    int ok = 1;
    while (ok) {
        cout << endl;
        cout << "1. Add a friendship" << endl;
        cout << "2. Delete a friendship" << endl;
        cout << "s. Show all friendships" << endl;
        cout << "x. Exit" << endl;

        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                ui_add_friendship();
                break;
            }
            case '2': {
                ui_delete_friendship();
                break;
            }
            case 's': {
                for(int i = 0;i<this->network.get_all_friendship().size();i++){
                    cout << this->network.get_all_friendship()[i];
                }
                break;
            }
            case 'x': {
                ok = 0;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}


void Console::run_menu_messages() {
    int ok = 1;
    while (ok) {
        cout << endl;
        cout << "1. Add a message" << endl;
        cout << "2. Delete a message" << endl;
        cout << "s. Show all messages" << endl;
        cout << "x. Exit" << endl;

        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                ui_add_message();
                break;
            }
            case '2': {
                ui_delete_message();
                break;
            }
            case 's': {
                for(int i = 0; i< this->network.get_all_message().size(); i++) {
                    cout << this->network.get_all_message()[i];
                }
                break;
            }
            case 'x': {
                ok = 0;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}


void Console::run_menu_event() {
    int ok = 1;
    while (ok) {
        cout << endl;
        cout << "1. Add an event" << endl;
        cout << "2. Delete an event" << endl;
        cout << "s. Show all events" << endl;
        cout << "x. Exit" << endl;

        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                ui_add_event();
                break;
            }
            case '2': {
                ui_delete_event();
                break;
            }
            case 's': {
                if(this->network.get_all_event().size()){
                    for(auto &ev: this->network.get_all_event()){
                        cout << ev;
                    }
                }
                break;
            }
            case 'x': {
                ok = 0;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}


void Console::run_menu() {
    int ok = 1;
    while (ok) {
        cout << endl;
        cout << "1. Users menu" << endl;
        cout << "2. Friendships menu" << endl;
        cout << "3. Messages menu" << endl;
        cout << "4. Events menu" << endl;
        cout << "x. Exit" << endl;

        char option;
        cout << "Give option: ";
        cin >> option;
        cout << endl;
        switch (option) {
            case '1': {
                run_menu_user();
                break;
            }
            case '2': {
                run_menu_friendship();
                break;
            }
            case '3': {
                run_menu_messages();
                break;
            }
            case '4': {
                run_menu_event();
                break;
            }
            case 'x': {
                ok = 0;
                break;
            }
            default:
                cout << "Wrong option! Try again!" << endl;
        }
    }
}

void Console::ui_add_user() {
    User user;

    cin >> user;
    bool ok = true;
    for(auto &useer:this->network.get_all_user()) {
        if(useer == user || user.get_id() == useer.get_id()) {
            ok = false;
        }
    }
    if(!ok) {
        cout << "The id you introduced already exists!";
    }
    else
        this->network.add_user(user);
}

void Console::ui_delete_user(){
    cout << "The id of the user you want to delete: " << endl;
    int id;
    bool ok = false;
    cin >> id;
    for(auto &useer: this->network.get_all_user()) {
        if(id == useer.get_id()) {
            this->network.delete_user(useer);
            ok = true;
        }
    }
    if(!ok){
        cout << "There is no user with given id!";
    }
}

void Console::ui_update_user() {
    cout << "The id of the user you want to update: " << endl;
    int id;
    bool ok = false;
    cin >> id;
    cout << "Give the new user info: " << endl;
    User user;
    cin >> user;
    for(auto &useer: this->network.get_all_user()) {
        if(id == useer.get_id()) {
            network.update_user(useer, user);
            ok = true;
        }
    }
    if(!ok){
        cout << "There is no user with given id!";
    }

}

void Console::ui_add_friendship() {
    Friendship friendship;
    cin >> friendship;
    int nr = 0;
    for(auto &useer: this->network.get_all_user()) {
        if(friendship.get_id_receiver() == useer.get_id() || friendship.get_id_sender() == useer.get_id()) {
            nr ++;
        }
    }
    if (nr == 2) {
        bool ok2 = true;
        for(auto &friendship1: this->network.get_all_friendship())
            if(friendship1 == friendship) {
                ok2 = false;
            }
        if(ok2){
            friendship.set_status("friends");
            network.add_friendship(friendship);
        } else {
            cout << "The friendship can't be done! ";
        }
    }
}

void Console::ui_delete_friendship() {
    cout << "Id of the friendship you want to delete: " << endl;
    int id;
    bool ok = false;
    cin >> id;
    for(auto &friendship1: network.get_all_friendship()) {
        if (id == friendship1.get_id()) {
            network.delete_friendship(friendship1);
            ok = true;
        }
    }
    if(!ok) {
        cout << "There is no friendship with this id! ";
    }
}

void Console::ui_add_message() {
    Message message;
    cin >> message;
    int nr = 0;
    for(auto &useer: network.get_all_user()) {
        if(message.get_id_sender() == useer.get_id() || message.get_id_receiver() == useer.get_id()) {
            nr ++;
        }
    }
    if(nr == 2) {
        bool ok = true;
        for(auto &message1: network.get_all_message()) {
            if(message1.get_id() == message.get_id()){
                ok = false;
            }
            if(ok) {
                network.add_message(message);
            } else {
                cout << "The message can't be send! " << endl;
            }
        }
    }
}

void Console::ui_delete_message() {
    cout << "Id of the message you want to delete: " << endl;
    int id;
    bool ok = false;
    cin >> id;
    for(auto &message1:network.get_all_message()) {
        if(id == message1.get_id()) {
            network.delete_message(message1);
            ok = true;
        }
    }
    if(!ok) {
        cout << "There is no message with given id! ";
    }
}

void Console::ui_add_event() {
    Event event;
    cin >> event;
    bool ok1 = false;
    bool ok2 = true;
    for (auto &useer: network.get_all_user()) {
        if (event.get_id() == useer.get_id()) {
            ok1 = true;
        }
    }
    if(ok1) {
        for (auto &event1: network.get_all_event()) {
            if (event.get_id() == event1.get_id()) {
                ok2 = false;
            }
        }
        if(ok2){
            network.add_event(event);
        } else {
            cout << "There is already an event with given id!";
        }

    }
    else {
        cout << "There is no user with given id! ";
    }
}

void Console::ui_delete_event() {
    cout << "Give the id of the event you want to delete:";
    int id_event;
    bool ok = false;
    cin >> id_event;
    for (auto &e: network.get_all_event()) {
        if (id_event == e.get_id()) {
            ok = true;
            network.delete_event(e);
        }
    }
    if (!ok)
        cout << "There is no event with given id!";
}