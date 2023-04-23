#ifndef SDA_PROIECT_LIST_H
#define SDA_PROIECT_LIST_H
#include "ListNode.h"
#include <vector>
#include <iostream>

using namespace std;

template <class T>
class List {
private:
    ListNode<T>* head;
    int size_elem;
public:
    List(){head = nullptr;
    size_elem =0;
    }
    void add(T elem){
        if (head==nullptr)
        {
            head=new ListNode<T>(elem);
            this->size_elem++;
        }
        else
        {
            ListNode<T>* p=head;
            while (p->next!=nullptr) p=p->next;
            p->next=new ListNode<T>(elem);
            this->size_elem++;
        }
    }





    T deletee(T e){
        ListNode<T> *nodeToDelete = nullptr;
        T infoToReturn;

        if (head!= nullptr) {
            if (head->info == e) {
                nodeToDelete = head;
                head = head->next;
            } else {
                ListNode<T> *p= head->next;
                ListNode<T> *q=head;
                while (p!= nullptr)
                    if (p->info == e) {
                        nodeToDelete = p;
                        p= nullptr;
                    } else {
                        p = p->next;
                        q = q->next;
                    }
                if (nodeToDelete != nullptr)
                    q->next= nodeToDelete->next;
            }
        }
        if (nodeToDelete != nullptr) {
            infoToReturn = nodeToDelete->info;
            delete nodeToDelete;
            this->size_elem--;
            return infoToReturn;
        }
        return T();
    }


    void update(T e,  T new_e) {
        if (head != nullptr) {
            if (head->info == e) {
                head->info = new_e;
            } else {
                ListNode<T> *p = head->next;
                ListNode<T> *q = head;
                while (p != nullptr)
                    if (p->info == e) {
                        p->info = new_e;
                    } else {
                        p = p->next;
                        q = q->next;
                    }
            }}}

    T& operator[](int index) const{

    }

    vector<T> get_all(){
        vector<T> v;
        ListNode<T>* p=head;
        while (p != nullptr) {
            v.push_back(p->info);
            p=p->next;
        }
        return v;
    }





    int get_size() {
        return this->size_elem;
    }
};

#endif //SDA_PROIECT_LIST_H
