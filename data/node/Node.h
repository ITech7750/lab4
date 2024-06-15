
#ifndef LAB4_NODE_H
#define LAB4_NODE_H

#include "../dynamicarray/DynamicArray.h"
#include "../../linkedlist/LinkedList.h"

template<class T>
class Node {
private:
    T value;
    Node<T>* parent;
    LinkedList<Node<T>*>* _child;

public:
    Node() {
        parent = nullptr;
        _child = new LinkedList<Node<T>*>();
    }

    explicit Node(T value): Node() {
        this->value = value;
    }

    Node(T value, Node<T>* parent): Node() {
        this->value = value;
        this->parent = parent;
    }

    Node(T value, Node<T>* parent, Node<T>** child): Node() {
        this->value = value;
        this->parent = parent;
        int i = 0;
        while(child[i]) {
            this->_child->append(child[i]);
            i++;
        }
    }

    T get() {
        return value;
    }

    Node<T>* getParent() {
        return parent;
    }

    int childAmount() {
        return _child->getLength();
    }

    virtual Node<T>* getChild(int index) {
        return (*_child)[index];
    }

    virtual Node<T>* getFirst() {
        return (*_child)[0];
    }

    virtual Node<T>* getSecond() {
        return (*_child)[1];
    }

    virtual void addChild(Node<T>* child) {
        if (child->parent != this) {
            child->parent = this;
        }
        this->_child->append(child);
    }

    virtual Node<T>* deleteChild(int index) {
        this->_child->remove(index);
    }

    void deleteChild(Node<T>* child) {
        for (int i = 0;i<childAmount();i++) {
            if (this->_child->get(i) == child) {
                auto node = new LinkedList<Node<T>*>();
                this->_child->remove(i);
                node->append(child);
                while (!node->isEmpty()) {
                    Node<T>* n = node->get(0);
                    for (int j = 0;j<n->childAmount();j++) {
                        node->append(n->getChild(j));
                    }
                    delete n;
                    node->remove(0);
                }
            }
        }
    }

    friend std::ostream &operator<<(std::ostream &os, const Node &c) {
        os << "n(" << c.value << "->";
        for (int i = 0;i<c._child->getLength();i++) {
            if (i != 0) os << ", ";
            os << c._child->get(i)->get();
        }
        os << ")";
        return os;
    }
};

#endif //LAB4_NODE_H
