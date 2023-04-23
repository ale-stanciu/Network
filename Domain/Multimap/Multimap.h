//
// Created by User on 5/20/2022.
//

#ifndef SDA_PROIECT_MULTIMAP_H
#define SDA_PROIECT_MULTIMAP_H

#include "../List/ListNode.h"
#include "MapNode.h"
#include <vector>
#include <iostream>

using namespace std;

template<class Key, class Value>
class Multimap {
private:
    template<class V>
    class ListNode {
    public:
        V info;
        ListNode<V> *next;
        ListNode(V info, ListNode<V> *next) : info(info), next(next) {}
        ListNode(V info) : info(info) { next = nullptr; }
    };


    int size;
    MapNode<Key, ListNode<Value> *> *first;
    MapNode<Key, ListNode<Value> *> *searchAddress(Key k) {
        if(this->size == 0)
            return nullptr;
        MapNode<Key, ListNode<Value> *> *p = first;
        while (p->next != nullptr) {
            if(p->key == k)
                return p;
            p = p->next;
        }
        return p;
    }

public:
    Multimap() {
        this->first = nullptr;
        this->size = 0;
    }

    void add(Key key, Value value) {
        MapNode<Key, ListNode<Value> *> *position = searchAddress(key);

        if(position == nullptr) {
            this->first = new MapNode<Key, ListNode<Value> *>(key, new ListNode<Value>(value));
            this->size++;
        } else {
            if(position->key == key) {
                auto *node = new ListNode<Value>(value, position->value);
                position->value = node;
            } else {
                position->next = new MapNode<Key, ListNode<Value> *>(key, new ListNode<Value>(value));
                this->size++;
            }
        }
    }


/*
    template<class T, class U>
    inline void Multimap<T, U>::deleteKey(T key, U value) {
        DictNode* current = searchAddress(key);
        if (current == nullptr) {
            return;
        }
        else {
            ListNode* curr = current->value;
            ListNode* prev = nullptr;
            while (curr != nullptr) {
                if (curr->value == value) {
                    if (prev == nullptr) {
                        current->value = curr->next;
                    }
                    else {
                        prev->next = curr->next;
                    }
                    delete curr;
                    return;
                }
                prev = curr;
                curr = curr->next;
            }
        }
    }

*/



    void deleteKey(Key key, Value value) {
        MapNode<Key, ListNode<Value> *> *position = searchAddress(key);
        if(position != nullptr && position->key == key) {
            ListNode<Value> *p = position->value;
            if(p->info == value) {
                position->value = p->next;
                delete p;
                this->size--;
            } else {
                while (p->next != nullptr && !(p->next->info == value)) {
                    p = p->next;
                }
                if(p->next != nullptr && p->next->info == value) {
                    ListNode<Value> *q = p->next;
                    p->next = q->next;
                    delete q;
                    this->size--;
                }
            }
        }
    }


    vector<Value> get(Key key) {
        vector<Value> result;
        MapNode<Key, ListNode<Value> *> *position = searchAddress(key);
        if(position == nullptr)
            return result;
        ListNode<Value> *p = position->value;
        while (p != nullptr) {
            result.push_back(p->info);
            p = p->next;
        }
        return result;
    }

    int get_size() {
        return this->size;
    }

    vector<Value> get_all(){
        vector<Value> result;
        MapNode<Key, ListNode<Value> *> *p = first;
        while (p != nullptr) {
            ListNode<Value> *q = p->value;
            p = p->next;
            result.push_back(q->info);
        }
        return result;
    }

    ~Multimap() {
        MapNode<Key, ListNode<Value> *> *p = first;
        while (p != nullptr) {
            MapNode<Key, ListNode<Value> *> *q = p;
            p = p->next;
            delete q;
        }
    }
};

#endif //SDA_PROIECT_MULTIMAP_H
