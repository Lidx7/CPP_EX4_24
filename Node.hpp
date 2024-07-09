#ifndef NODE_HPP
#define NODE_HPP

#pragma once
#include <iostream>
#include <vector>
using namespace std;

template <typename T> class Node{
public:
    T data;
    Node<T>* parent;
    vector<Node<T> *> children;

public:
    Node(T data): data(data){};

    ~Node(){
        children.clear();
    }

    const T& get_value() const{
        return data;
    }

    vector<Node<T> *> get_children() const{
        return children;
    }

    void add_child(Node<T>* child){
        this->children.push_back(child);
    }

    Node* get_parent() const{
        return parent;
    }

    void clear_children(){
        children.clear();
    }

};

#endif // NODE_HPP
