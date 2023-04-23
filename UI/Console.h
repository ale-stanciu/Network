//
// Created by User on 5/25/2022.
//

#ifndef SDA_PROIECT_CONSOLE_H
#define SDA_PROIECT_CONSOLE_H


#include "../Network/Network.h"

class Console {
private:
    Network network;
public:
//    Console(const Network& network1);
    Console();
    void run_menu_user();
    void run_menu_friendship();
    void run_menu_messages();
    void run_menu_event();
    void run_menu();

    void ui_add_user();
    void ui_delete_user();

    void ui_update_user();

    void ui_add_friendship();

    void ui_delete_friendship();

    void ui_add_message();

    void ui_delete_message();

    void ui_add_event();

    void ui_delete_event();
};


#endif //SDA_PROIECT_CONSOLE_H
