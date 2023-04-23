#ifndef SDA_PROIECT_LISTNODE_H
#define SDA_PROIECT_LISTNODE_H


template <typename T>
class List;

template <class T>
class ListNode {
private:
    T info;
    ListNode<T>* next;
public:
    ListNode(T info, ListNode<T>* next) : info(info), next(next){}
    ListNode(T info) : info(info){ next= nullptr;}
    friend class List<T>;
};

#endif //SDA_PROIECT_LISTNODE_H
