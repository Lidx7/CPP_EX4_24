#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>
#include "Node.hpp"

using namespace std;

template <typename T> class pre_order_iterator {
    stack<Node<T>*> _stack;

public:
    pre_order_iterator(Node<T>* root) {
        cout << "pre_order_iterator constructor" << endl;
        if(root != nullptr) {
            _stack.push(root);
        }
        cout << "pre_order_iterator constructor end" << endl;
    }

    T& operator*() {
        if (_stack.empty()) throw runtime_error("Dereferencing end iterator");
        return _stack.top()->get_value();
    }

    Node<T>* operator->() {
        if (_stack.empty()) throw runtime_error("Dereferencing end iterator");
        return _stack.top();
    }

    pre_order_iterator& operator++() {
        if (!_stack.empty()) {
            Node<T>* curr = _stack.top();
            _stack.pop();
            for(int i = curr->children.size() - 1; i >= 0; i--) {
                if(curr->children[i] != nullptr) {
                    _stack.push(curr->children[i]);
                }
            }
        }
        return *this;
    }

    bool operator==(const pre_order_iterator& other) const {
        return (_stack.empty() && other._stack.empty()) || 
               (!_stack.empty() && !other._stack.empty() && _stack.top() == other._stack.top());
    }

    bool operator!=(const pre_order_iterator& other) const {
        return !(*this == other);
    }
};


template <typename T> class post_order_iterator {
private:
    stack<pair<Node<T>*, size_t>> _stack;

public:
    post_order_iterator(Node<T>* root) {
        if (root != nullptr) {
            _stack.push({root, 0});
            while (root->children.size() > 0) {
                root = root->children[0];
                _stack.push({root, 0});
            }
        }
    }

    T& operator*() {
        if (_stack.empty()) throw runtime_error("Dereferencing end iterator");
        return _stack.top().first->get_value();
    }

    Node<T>* operator->() {
        if (_stack.empty()) throw runtime_error("Dereferencing end iterator");
        return _stack.top().first;
    }

    post_order_iterator& operator++() {
        if (_stack.empty()) return *this;

        while (!_stack.empty()) {
            auto& [node, child_index] = _stack.top();

            if (child_index < node->children.size()) {
                Node<T>* next_child = node->children[child_index];
                ++child_index;
                
                _stack.push({next_child, 0});
                while (next_child->children.size() > 0) {
                    next_child = next_child->children[0];
                    _stack.push({next_child, 0});
                }
                break;
            } else {
                _stack.pop();
                if (!_stack.empty()) {
                    ++_stack.top().second;
                }
            }
        }

        return *this;
    }

    bool operator==(const post_order_iterator& other) const {
        return (_stack.empty() && other._stack.empty()) || 
               (!_stack.empty() && !other._stack.empty() && _stack.top().first == other._stack.top().first);
    }

    bool operator!=(const post_order_iterator& other) const {
        return !(*this == other);
    }
};

template <typename T> class in_order_iterator {
private:
    stack<Node<T>*> _stack;

public:
    in_order_iterator(Node<T>* root) {
        while (root != nullptr) {
            _stack.push(root);
            if (!root->children.empty()) {
                root = root->children[0];
            } else {
                root = nullptr;
            }
        }
    }

    T& operator*() {
        if (_stack.empty()) throw runtime_error("Dereferencing end iterator");
        return _stack.top()->get_value();
    }

    Node<T>* operator->() {
        if (_stack.empty()) throw runtime_error("Dereferencing end iterator");
        return _stack.top();
    }

    in_order_iterator& operator++() {
        if (_stack.empty()) return *this;

        Node<T>* node = _stack.top();
        _stack.pop();

        if (!node->children.empty() && node->children.size() > 1) {
            node = node->children[1];
            while (node != nullptr) {
                _stack.push(node);
                if (!node->children.empty()) {
                    node = node->children[0];
                } else {
                    node = nullptr;
                }
            }
        }

        return *this;
    }

    bool operator==(const in_order_iterator& other) const {
        return (_stack.empty() && other._stack.empty()) || 
               (!_stack.empty() && !other._stack.empty() && _stack.top() == other._stack.top());
    }

    bool operator!=(const in_order_iterator& other) const {
        return !(*this == other);
    }
};

template <typename T> class bfs_scan_iterator {
private:
    queue<Node<T>*> _queue;

public:
    bfs_scan_iterator(Node<T>* root) {
        if (root != nullptr) {
            _queue.push(root);
        }
    }

    T& operator*() {
        if (_queue.empty()) throw runtime_error("Dereferencing end iterator");
        return _queue.front()->get_value();
    }

    Node<T>* operator->() {
        if (_queue.empty()) throw runtime_error("Dereferencing end iterator");
        return _queue.front();
    }

    bfs_scan_iterator& operator++() {
        if (!_queue.empty()) {
            Node<T>* node = _queue.front();
            _queue.pop();
            for (auto child : node->children) {
                if (child != nullptr) {
                    _queue.push(child);
                }
            }
        }
        return *this;
    }

    bool operator==(const bfs_scan_iterator& other) const {
        return (_queue.empty() && other._queue.empty()) || 
               (!_queue.empty() && !other._queue.empty() && _queue.front() == other._queue.front());
    }

    bool operator!=(const bfs_scan_iterator& other) const {
        return !(*this == other);
    }
};

// DFS scan iterator (which is essentially the same as pre-order)
template <typename T> class dfs_scan_iterator {
private:
    stack<Node<T>*> _stack;

public:
    dfs_scan_iterator(Node<T>* root) {
        if (root != nullptr) {
            _stack.push(root);
        }
    }

    T& operator*() {
        if (_stack.empty()) throw runtime_error("Dereferencing end iterator");
        return _stack.top()->get_value();
    }

    Node<T>* operator->() {
        if (_stack.empty()) throw runtime_error("Dereferencing end iterator");
        return _stack.top();
    }

    dfs_scan_iterator& operator++() {
        if (!_stack.empty()) {
            Node<T>* node = _stack.top();
            _stack.pop();
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                if (*it != nullptr) {
                    _stack.push(*it);
                }
            }
        }
        return *this;
    }

    bool operator==(const dfs_scan_iterator& other) const {
        return (_stack.empty() && other._stack.empty()) || 
               (!_stack.empty() && !other._stack.empty() && _stack.top() == other._stack.top());
    }

    bool operator!=(const dfs_scan_iterator& other) const {
        return !(*this == other);
    }
};

// Heap iterator remains largely the same, but with some improvements
template <typename T> class heap_iterator {
private:
    vector<Node<T>*> _heap;
    size_t _index;

public:
    heap_iterator(Node<T>* root) : _index(0) {
        if (root != nullptr) {
            bfs_scan_iterator<T> bfs_it(root);
            bfs_scan_iterator<T> bfs_end(nullptr);
            for (; bfs_it != bfs_end; ++bfs_it) {
                _heap.push_back(bfs_it.operator->());
            }
            make_heap(_heap.begin(), _heap.end(), [](Node<T>* a, Node<T>* b) {
                return a->get_value() > b->get_value();
            });
        }
    }

    T& operator*() {
        if (_index >= _heap.size()) throw runtime_error("Dereferencing end iterator");
        return _heap[_index]->get_value();
    }

    Node<T>* operator->() {
        if (_index >= _heap.size()) throw runtime_error("Dereferencing end iterator");
        return _heap[_index];
    }

    heap_iterator& operator++() {
        if (_index < _heap.size()) {
            pop_heap(_heap.begin(), _heap.end() - _index);
            ++_index;
        }
        return *this;
    }

    bool operator==(const heap_iterator& other) const {
        return _index == other._index;
    }

    bool operator!=(const heap_iterator& other) const {
        return !(*this == other);
    }
};