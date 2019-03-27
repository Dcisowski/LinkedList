//
// Created by dawid on 27.03.19.
//

#ifndef ARRAYLIST_LINKEDLIST_HPP
#define ARRAYLIST_LINKEDLIST_HPP


template <typename T>
class LinkedList {
public:
    struct Node {
        T p;
        Node* prev;
        Node* next;
    };
    using position_t = Node*;
    Node* head;
    Node* tail;
    int size;
    void push_front(T x);
    T pop_front();
    Node* push_back(T x);
    T pop_back();
    Node* find(T x);
    Node* erase(Node* pos);
    Node* insert(Node* pos, T x);
    int Size();
    bool empty();
    LinkedList();

};
#endif //ARRAYLIST_LINKEDLIST_HPP


#include <iostream>

template <typename T>
LinkedList<T>::LinkedList(){

    this->head = nullptr;
    this->tail = nullptr;
    size = 0;
}
template <typename T>
typename LinkedList<T>::Node* LinkedList<T>::push_back(T x){
    Node *temp=new Node;
    temp->p=x;
    temp->next=nullptr;
    temp->prev=nullptr;
    if(head==nullptr)
    {
        temp->next = nullptr;
        temp->prev = nullptr;
        temp->p = x;
        head = temp;
        tail = temp;
        size++;
    }
    else
    {
        temp->p=x;
        temp->prev=tail;
        tail->next=temp;
        tail=temp;
        size++;
    }
    return temp;
}
template <typename T>
T LinkedList<T>::pop_back(){
    Node *temp=new Node;
    if(head==NULL){
        return NULL;
    }
    else{
        T g = tail->p;
        temp->p = tail->prev->p;
        temp->prev = tail->prev->prev;
        temp->next = temp;
        tail = temp;
        if(size == 1){
            head = temp;
        }
        size--;
        return g;
    }
}
template <typename T>
void LinkedList<T>::push_front(T x){
    Node *temp=new Node;
    temp->p=x;
    temp->next=nullptr;
    temp->prev=nullptr;
    if(head==nullptr)
    {
        temp->next = nullptr;
        temp->prev = nullptr;
        temp->p = x;
        head = temp;
        tail = temp;
        size++;
    }
    else{
        temp->p = x;
        temp->next = head;
        temp->prev = nullptr;
        head = temp;
        std::cout<<head->p;
        size++;

    }
}
template<typename T>
T LinkedList<T>::pop_front(){
    Node *temp=new Node;
    T b;
    b = head->p;
    temp->p = head->next->p;
    temp->next = head->next->next;
    head = temp;
    if(size == 1){
        tail = temp;
    }
    size--;
    return b;
}
template<typename T>
bool LinkedList<T>::empty(){
    if(size==0){
        return true;
    }
    else{
        return false;
    }
}
template<typename T>
int LinkedList<T>::Size(){
    return size;
}
template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::find(T x){
    Node *temp = new Node;
    Node *temp2 = new Node;
    for(int i = 0;i < size;i++){
        if(i==0){
            if(head->p == x){
                return head;
            }
            else{
                temp = head->next;
            }
        }
        else{
            if(temp->p == x){
                return temp;
            }
            else{
                temp = temp->next;
            }
        }
    }
    return nullptr;
}
template<typename T>
typename LinkedList<T>::Node* LinkedList<T>::erase(LinkedList::Node* pos){
    Node *temp = new Node;
    Node* POS;
    POS = pos->next;
    temp = pos->next;
    temp->prev = pos->prev;
    temp = POS;
    size--;
    return temp;

}
template <typename T>
typename LinkedList<T>::Node *LinkedList<T>::insert(LinkedList::Node* pos,T x){
    Node *temp = new Node;
    temp->p = x;
    temp->next = pos;
    temp->prev = pos->prev;
    pos->prev = temp;
    size++;
    std::cout<<temp->p<<std::endl;
    return temp;
}


