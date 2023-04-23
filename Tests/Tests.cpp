#include "Tests.h"
#include "../Domain/List/List.h"
#include "../Domain/User/User.h"
#include "../Domain/Event/Event.h"
#include "../Domain/Message/Message.h"
#include "../Domain/Friendship/Friendship.h"
#include "../Domain/Multimap/Multimap.h"
#include "../Repo/RepoUser/RepoUser.h"
#include "../Repo/RepoFriendship/RepoFriendship.h"
#include "../Repo/RepoMessage/RepoMessage.h"
#include "../Repo/RepoEvent/RepoEvent.h"
#include "../Service/ServiceUser/ServiceUser.h"
#include "../Service/ServiceFriendship/ServiceFriendship.h"
#include "../Service/ServiceMessage/ServiceMessage.h"
#include "../Service/ServiceEvent/ServiceEvent.h"
#include <cassert>
#include <iostream>


using namespace std;

void test_constructor1(){
    User user;

    assert(user.get_id() == 0);
    assert(user.get_First_name().empty());
    assert(user.get_last_name().empty());
    assert(user.get_username().empty());
    assert(user.get_age() == 0);
}

void test_constructor2(){
    User user(1, "Alexandra", "Stanciu", "ale_stanciu", 19);
    assert(user.get_id() == 1);
    assert(user.get_First_name() == "Alexandra");
    assert(user.get_last_name() == "Stanciu");
    assert(user.get_username() == "ale_stanciu");
    assert(user.get_age() == 19);
}

void test_setter_getter(){
    User user;
    user.set_id(1);
    user.set_first_name("Alexandra");
    user.set_last_name("Stanciu");
    user.set_username("ale_stanciu");
    user.set_age(19);

    assert(user.get_id() == 1);
    assert(user.get_First_name() == "Alexandra");
    assert(user.get_last_name() == "Stanciu");
    assert(user.get_username() == "ale_stanciu");
    assert(user.get_age() == 19);
}

void test_add(){
    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 19);
    User user2(2, "Popescu", "Maria", "popescu_maria", 33);
    User user3(3, "Marin", "Andrei", "andrei_marin", 25);
    User user4(4, "Baciu", "Marius", "marius_baciu", 22);

    List<User>* lista=new List<User>();
    lista->add(user1);
    lista->add(user2);
    lista->add(user3);
    lista->add(user4);

    assert(lista->get_size() == 4);
}

void test_delete() {
    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 19);
    User user2(2, "Popescu", "Maria", "popescu_maria", 33);
    User user3(3, "Marin", "Andrei", "andrei_marin", 25);
    User user4(4, "Baciu", "Marius", "marius_baciu", 22);

    List<User>* lista=new List<User>();
    lista->add(user1);
    lista->add(user2);
    lista->add(user3);
    lista->add(user4);

    assert(lista->get_size() == 4);

    lista->deletee(user1);

    assert(lista->get_size() == 3);
}

void test_update() {
    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 19);
    User user2(2, "Popescu", "Maria", "popescu_maria", 33);
    User user3(3, "Marin", "Andrei", "andrei_marin", 25);
    User user4(4, "Baciu", "Marius", "marius_baciu", 22);

    List<User>* lista=new List<User>();
    lista->add(user1);
    lista->add(user2);
    lista->add(user3);

    assert(lista->get_size() == 3);

    lista->update(user1, user4);
    assert(lista->get_size() == 3);

}

void test_constructor1_event(){
    Event event;
    assert(event.get_id() == 0);
    assert(event.get_name().empty());
    assert(event.get_id_organizer() == 0);
}


void test_constructor2_event() {
    Event event(1, "Neversea",1);

    assert(event.get_id() == 1);
    assert(event.get_name() == "Neversea");
    assert(event.get_id_organizer() == 1);
}

void test_setter_getter_event() {
    Event event;

    event.set_id(1);
    event.set_name("Neversea");
    event.set_id_organizer(1);

    assert(event.get_id() == 1);
    assert(event.get_name() == "Neversea");
    assert(event.get_id_organizer() == 1);
}


void test_constructor1_message(){
    Message message;

    assert(message.get_id() == 0);
    assert(message.get_id_receiver() == 0);
    assert(message.get_id_sender() == 0);
    assert(message.get_text().empty());
}

void test_constructor2_message() {
    Message message(1,1,1,"Buna");

    assert(message.get_id() == 1);
    assert(message.get_id_sender() == 1);
    assert(message.get_id_receiver() == 1);
    assert(message.get_text() == "Buna");
}

void test_setter_getter_message() {
    Message message;
    message.set_id(1);
    message.set_id_receiver(1);
    message.set_id_sender(1);
    message.set_text("Buna");

    assert(message.get_id() == 1);
    assert(message.get_id_sender() == 1);
    assert(message.get_id_receiver() == 1);
    assert(message.get_text() == "Buna");

}

void test_constructor1_friendship() {
    Friendship friendship;

    assert(friendship.get_id() == 0);
    assert(friendship.get_id_receiver() == 0);
    assert(friendship.get_id_sender() == 0);
    assert(friendship.get_status() == "");
}

void test_constructor2_friendship() {
    Friendship friendship(1,1,1,"friends");

    assert(friendship.get_id() == 1);
    assert(friendship.get_id_sender() == 1);
    assert(friendship.get_id_receiver() == 1);
    assert(friendship.get_status() == "friends");
}

void test_setter_getter_freindship() {
    Friendship friendship;

    friendship.set_id(1);
    friendship.set_id_sender(1);
    friendship.set_id_receiver(1);
    friendship.set_status("friends");

    assert(friendship.get_id() == 1);
    assert(friendship.get_id_sender() == 1);
    assert(friendship.get_id_receiver() == 1);
    assert(friendship.get_status() == "friends");
}

void test_add_multimap() {
    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 20);
    User user2(2, "Zarnescu", "Bogdan", "bibi_zarnescu", 19);
    User user3(3, "Stejeroiu", "Oana", "oana_steje", 19);

    Friendship friendship1(1,1,2,"friends");
    Friendship friendship2(2,1,3,"friends");

    Multimap<int, Friendship> multimap;
    multimap.add(1, friendship1);
    multimap.add(2, friendship2);

    assert(multimap.get_size() == 2);
}

void test_delete_multimap() {
    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 20);
    User user2(2, "Zarnescu", "Bogdan", "bibi_zarnescu", 19);
    User user3(3, "Stejeroiu", "Oana", "oana_steje", 19);

    Friendship friendship1(1,1,2,"friends");
    Friendship friendship2(2,1,3,"friends");

    Multimap<int, Friendship> multimap;
    multimap.add(1, friendship1);
    multimap.add(2, friendship2);

    assert(multimap.get_size() == 2);

    multimap.deleteKey(2, friendship2);
    assert(multimap.get_size() == 1);
}

void test_get_all_multimap() {
    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 20);
    User user2(2, "Zarnescu", "Bogdan", "bibi_zarnescu", 19);
    User user3(3, "Stejeroiu", "Oana", "oana_steje", 19);

    Friendship friendship1(1,1,2,"friends");
    Friendship friendship2(2,1,3,"friends");

    Multimap<int, Friendship> multimap;
    multimap.add(1, friendship1);
    multimap.add(2, friendship2);

    assert(multimap.get_size() == 2);

    vector<Friendship> v = multimap.get_all();
    assert(v[0] == friendship1);
}

void test_add_repo() {
    RepoUser repoUser;
    List<User>* list = new List<User>;

    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 20);
    User user2(2, "Zarnescu", "Bogdan", "bibi_zarnescu", 19);
    User user3(3, "Stejeroiu", "Oana", "oana_steje", 19);

    repoUser.add_user(user1);
    repoUser.add_user(user2);
    repoUser.add_user(user3);

    assert(repoUser.get_size() == 3);
    assert(repoUser.get_all_vector().size() == 3);
}

void test_delete_repo() {
    RepoUser repoUser;
    List<User>* list = new List<User>;

    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 20);
    User user2(2, "Zarnescu", "Bogdan", "bibi_zarnescu", 19);
    User user3(3, "Stejeroiu", "Oana", "oana_steje", 19);

    repoUser.add_user(user1);
    repoUser.add_user(user2);
    repoUser.add_user(user3);
    assert(repoUser.get_size() == 3);

    repoUser.delete_user(user3);

    assert(repoUser.get_size() == 2);
}

void test_modify_repo() {
    RepoUser repoUser;
    List<User>* list = new List<User>;

    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 20);
    User user2(2, "Zarnescu", "Bogdan", "bibi_zarnescu", 19);
    User user3(3, "Stejeroiu", "Oana", "oana_steje", 19);

    repoUser.add_user(user1);
    repoUser.add_user(user2);
    assert(repoUser.get_size() == 2);

    repoUser.update_user(user2, user3);

}

void test_friendship_repo() {
    RepoFriendship repoFriendship;
    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 20);
    User user2(2, "Zarnescu", "Bogdan", "bibi_zarnescu", 19);
    User user3(3, "Stejeroiu", "Oana", "oana_steje", 19);

    Friendship friendship1(1,1,2,"friends");
    Friendship friendship2(2,1,3,"friends");

    repoFriendship.add_friendship(friendship1);
    repoFriendship.add_friendship(friendship2);

    assert(repoFriendship.get_size() == 2);

    repoFriendship.delete_friendship(friendship2);

    assert(repoFriendship.get_size() == 1);

}

void test_message_repo() {
    RepoMessage repoMessage;
    Message message1(1,1,2,"buna");
    Message message2(2,3,1,"salut");

    repoMessage.add_message(message1);
    repoMessage.add_message(message2);

    assert(repoMessage.get_size() == 2);

    repoMessage.delete_message(message2);

    assert(repoMessage.get_size() == 1);
}

void test_event_repo() {
    RepoEvent repoEvent;
    Event event1(1, "Neversea", 1);
    Event event2(2, "Artistree", 1);

    repoEvent.add_event(event1);
    repoEvent.add_event(event2);

    assert(repoEvent.get_size() == 2);

    repoEvent.delete_event(event2);

    assert(repoEvent.get_size() == 1);
}

void test_user_service() {
    RepoUser repoUser;
    ServiceUser serviceUser(repoUser);

    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 20);
    User user2(2, "Zarnescu", "Bogdan", "bibi_zarnescu", 19);
    User user3(3, "Stejeroiu", "Oana", "oana_steje", 19);
    User user4(4, "Popescu", "Maria", "maria_popescu",22);

    serviceUser.add_user(user1);
    serviceUser.add_user(user2);
    serviceUser.add_user(user3);

    assert(serviceUser.get_all().size() == 3);

    serviceUser.delete_user(user3);

    assert(serviceUser.get_all().size() == 2);

    serviceUser.update_user(user1, user4);

    assert(serviceUser.get_all().size() == 2);

}

void test_friendship_service() {
    RepoFriendship repoFriendship;
    ServiceFriendship serviceFriendship(repoFriendship);
    User user1(1, "Stanciu", "Alexandra", "ale_stanciu", 20);
    User user2(2, "Zarnescu", "Bogdan", "bibi_zarnescu", 19);
    User user3(3, "Stejeroiu", "Oana", "oana_steje", 19);

    Friendship friendship1(1,1,2,"friends");
    Friendship friendship2(2,1,3,"friends");
    Friendship friendship3(3,2,3,"friends");

    serviceFriendship.add_friendship(friendship1);
    serviceFriendship.add_friendship(friendship2);

    assert(serviceFriendship.get_all_friendship().size() == 2);

    serviceFriendship.delete_friendship(friendship1);

    assert(serviceFriendship.get_all_friendship().size() == 1);
}

void test_message_service() {
    RepoMessage repoMessage;
    ServiceMessage serviceMessage(repoMessage);
    Message message1(1,1,1,"buna");
    Message message2(2,2,3,"hei");
    Message message3(3,2,1,"ce faci?");

    serviceMessage.add_message(message1);
    serviceMessage.add_message(message2);
    serviceMessage.add_message(message3);

    assert(serviceMessage.get_all_message().size() == 3);

    serviceMessage.delete_message(message2);

    assert(serviceMessage.get_all_message().size() == 2);
}

void test_event_service() {
    RepoEvent repoEvent;
    ServiceEvent serviceEvent(repoEvent);
    Event event1(1,"Neversea",1);
    Event event2(2,"Artistree",3);

    serviceEvent.add_event(event1);
    serviceEvent.add_event(event2);

    assert(serviceEvent.get_all().size() == 2);

    serviceEvent.delete_event(event1);

    //assert(serviceEvent.get_all().size() == 1);
}

void test_all() {

    ///User:
    test_constructor1();
    test_constructor2();
    test_setter_getter();

    ///Friendship:
    test_constructor1_friendship();
    test_constructor2_friendship();
    test_setter_getter_freindship();

    ///Event:
    test_constructor1_event();
    test_constructor2_event();
    test_setter_getter_event();

    ///Message:
    test_constructor1_message();
    test_constructor2_message();
    test_setter_getter_message();

    ///List:
    test_add();
    test_delete();
    test_update();

    ///Multimap:
    test_add_multimap();
    test_delete_multimap();
    test_get_all_multimap();

    ///Repo User:
    test_add_repo();
    test_delete_repo();
    test_modify_repo();

    ///Repo:
    test_friendship_repo();
    test_message_repo();
    test_event_repo();

    ///Service
    test_user_service();
    test_friendship_service();
    test_message_service();
    test_event_service();
}