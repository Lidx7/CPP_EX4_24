#ifndef TREE_HPP
#define TREE_HPP

#pragma once
#include <iostream>
#include "Node.hpp"
#include "Iterators.hpp"

using namespace std;

template <typename T, int K> class BaseTree{
protected:
    Node<T>* root;

public:
    BaseTree(): root(nullptr){};
    BaseTree(Node<T>* root): root(root){};

    ~BaseTree() {
    if (root != nullptr) {
        clearTree(root);
        root = nullptr;
    }
}

    void clearTree(Node<T>* node) {
        if (node == nullptr) return;
        
        for (Node<T>* child : node->get_children()) {
            clearTree(child);
        }
        node->clear_children();
    }


    void add_root(Node<T>& root){
        this->root = &root;
    }

    void add_sub_node(Node<T>* node, Node<T>* subNode){
        if(node->get_children().size() < K){
            node->add_child(subNode);
        }
        else{
            throw runtime_error("Node has reached its maximum number of children, cant add any more");
        }
    }

    bfs_scan_iterator<T> begin(){
        return begin_bfs_scan();
    }

    bfs_scan_iterator<T> end(){
        return end_bfs_scan();
    }


    bfs_scan_iterator<T> begin_bfs_scan(){
        return bfs_scan_iterator<T>(root);
    }

    bfs_scan_iterator<T> end_bfs_scan(){
        return bfs_scan_iterator<T>(nullptr);
    }

    dfs_scan_iterator<T> begin_dfs_scan(){
        return dfs_scan_iterator<T>(root);
    }

    dfs_scan_iterator<T> end_dfs_scan(){
        return dfs_scan_iterator<T>(nullptr);
    }

    /*TODO: still needs to add a printing function*/


};


/*  This is athe implementation of the default 2-ary tree, called when no int argument is passed.
    It basically just creates the normal tree, leaving the basics unchanged, and then calls the new iterators*/
template <typename T, int K = 2> class Tree : public BaseTree <T, K>{
public:

    pre_order_iterator<T> begin_pre_order(){
        return pre_order_iterator<T>(this->root);
    }

    pre_order_iterator<T> end_pre_order(){
        return pre_order_iterator<T>(nullptr);
    }

    post_order_iterator<T> begin_post_order(){
        return post_order_iterator<T>(this->root);
    }

    post_order_iterator<T> end_post_order(){
        return post_order_iterator<T>(nullptr);
    }

    in_order_iterator<T> begin_in_order(){
        return in_order_iterator<T>(this->root);
    }

    in_order_iterator<T> end_in_order(){
        return in_order_iterator<T>(nullptr);
    }


};


/*Specialized template for binary tree option*/
template <typename T> class Tree<T, 2> : public BaseTree<T, 2>{
public:
    pre_order_iterator<T> begin_pre_order(){
        return pre_order_iterator<T>(this->root);
    }

    pre_order_iterator<T> end_pre_order(){
        return pre_order_iterator<T>(nullptr);
    }

    post_order_iterator<T> begin_post_order(){
        return post_order_iterator<T>(this->root);
    }

    post_order_iterator<T> end_post_order(){
        return post_order_iterator<T>(nullptr);
    }

    in_order_iterator<T> begin_in_order(){
        return in_order_iterator<T>(this->root);
    }

    in_order_iterator<T> end_in_order(){
        return in_order_iterator<T>(nullptr);
    }

    heap_iterator<T> begin_heap_iterator(){
        return heap_iterator<T>(this->root);
    }

    heap_iterator<T> end_heap_iterator(){
        return heap_iterator<T>(nullptr);
    }
};

#endif // TREE_HPP
