cmake_minimum_required(VERSION 3.21)
project(SDA_proiect)

set(CMAKE_CXX_STANDARD 14)

add_executable(SDA_proiect main.cpp Domain/User/User.cpp Domain/User/User.h Domain/List/List.h Domain/List/ListNode.h Tests/Tests.cpp Tests/Tests.h Domain/Event/Event.cpp Domain/Event/Event.h Domain/Friendship/Friendship.cpp Domain/Friendship/Friendship.h Domain/Multimap/MapNode.h Domain/Multimap/Multimap.h Domain/Message/Message.cpp Domain/Message/Message.h Repo/RepoEvent/RepoEvent.cpp Repo/RepoEvent/RepoEvent.h Repo/RepoUser/RepoUser.cpp Repo/RepoUser/RepoUser.h Repo/RepoFriendship/RepoFriendship.cpp Repo/RepoFriendship/RepoFriendship.h Repo/RepoMessage/RepoMessage.cpp Repo/RepoMessage/RepoMessage.h Service/ServiceUser/ServiceUser.cpp Service/ServiceUser/ServiceUser.h Service/ServiceMessage/ServiceMessage.cpp Service/ServiceMessage/ServiceMessage.h Service/ServiceFriendship/ServiceFriendship.cpp Service/ServiceFriendship/ServiceFriendship.h Service/ServiceEvent/ServiceEvent.cpp Service/ServiceEvent/ServiceEvent.h UI/Console.cpp UI/Console.h Network/Network.cpp Network/Network.h)
