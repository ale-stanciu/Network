#include <iostream>
#include "Tests/Tests.h"
#include "Service/ServiceUser/ServiceUser.h"
#include "Repo/RepoFriendship/RepoFriendship.h"
#include "Repo/RepoMessage/RepoMessage.h"
#include "Repo/RepoEvent/RepoEvent.h"
#include "Service/ServiceFriendship/ServiceFriendship.h"
#include "Service/ServiceMessage/ServiceMessage.h"
#include "Service/ServiceEvent/ServiceEvent.h"
#include "Network/Network.h"
#include "UI/Console.h"

using namespace std;

int main() {
    test_all();

    RepoUser repoUser;
    RepoFriendship repoFriendship;
    RepoMessage repoMessage;
    RepoEvent repoEvent;

    ServiceUser serviceUser(repoUser);
    ServiceFriendship serviceFriendship (repoFriendship);
    ServiceMessage serviceMessage (repoMessage);
    ServiceEvent serviceEvent (repoEvent);

    Network network;

    Console console;
    console.run_menu();


    //cout << "Hello, World!" << std::endl;
    return 0;
}
