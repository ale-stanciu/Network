//
// Created by User on 5/20/2022.
//

#ifndef SDA_PROIECT_MAPNODE_H
#define SDA_PROIECT_MAPNODE_H

template<class K, class V>
class MapNode{
public:
    K key;
    V value;
    MapNode<K, V> *next;

    MapNode(K key, V value): key(key), value(value) {
        this->next = nullptr;
    }
};

#endif //SDA_PROIECT_MAPNODE_H
