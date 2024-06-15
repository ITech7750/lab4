
#ifndef LAB4_TREE_H
#define LAB4_TREE_H

#include "../node/Node.h"
#include "../heap/Heap.h"
#include "../../util/exception/NodeNotInTree.h"

template<class T>
class Tree {
private:
    Node<T>* root;
public:
    Tree() {
        this->root = new Node<T>();
    }

    explicit Tree(Node<T>* root) {
        this->root = root;
    }

    explicit Tree(T value) {
        this->root = new Node<T>(value);
    }

    bool contains(Node<T>* node) {
        auto* nodes = new LinkedList<Node<T>*>();
        if (root == node) return true;
        nodes->append(root);
        while (nodes->getLength()!=0) {
            Node<T>* n = (*nodes)[0];
            for (int i = 0;i<n->childAmount();i++) {
                auto *tmp = n->getChild(i);
                if (tmp == node) return true;
                else {
                    nodes->append(tmp);
                }
            }
            nodes->remove(0);
        }
        return false;
    }

    void addNode(Node<T>* node) {
        if (contains(node->getParent())) {
            node->getParent()->addChild(node);
        }
    }

    void deleteNode(Node<T>* node) {
        if (contains(node)) {
            node->getParent()->deleteChild(node);
        } else {
            throw NodeNotInTree();
        }
    }

    template<class R>
    Tree<R>* map(R (*transform)(T value)) {
        auto* rootR = new Node<R>(transform(root->get()));
        auto* treeR = new Tree<R>(rootR);
        auto* nodesT = new LinkedList<Node<T>*>();
        auto* nodesR = new LinkedList<Node<R>*>();
        nodesT->append(root);
        nodesR->append(rootR);

        while(!nodesT->isEmpty()) {
            auto* nT = (*nodesT)[0];
            auto* nR = (*nodesR)[0];
            for (int i = 0;i<nT->childAmount();i++) {
                auto* tmp = nT->getChild(i);
                auto* tmpR = new Node<R>(transform(tmp->get()), nR);
                treeR->addNode(tmpR);
                nodesT->append(tmp);
                nodesR->append(tmpR);
            }
            nodesT->remove(0);
            nodesR->remove(0);
        }
        return treeR;
    }

    T reduce(T (*transform)(T v1, T v2), T c) {
        T result = transform(root->get(), c);
        auto* nodes = new LinkedList<Node<T>*>();
        nodes->append(root);
        while(nodes->getLength()!=0) {
            auto* n = nodes->get(0);
            for (int i = 0;i<n->childAmount();i++) {
                auto tmp = n->getChild(i);
                result = transform(tmp->get(), result);
                nodes->append(tmp);
            }
            nodes->remove(0);
        }
        return result;
    }

    Tree<T>* subTree(Node<T>* node) {
        auto subTree = new Tree<T>(node);
        if (contains(node)) {
            return subTree;
        } else {
            return new Tree<T>();
        }
    }

    bool containTree(Tree<T>* tree) {
        auto* subRoot = tree->root;
        if (root->childAmount() != subRoot->childAmount() || root->get() != subRoot->get()) {
            return false;
        }
        auto* nodes = new LinkedList<Node<T>*>();
        auto* subNodes = new LinkedList<Node<T>*>();
        nodes->append(root);
        subNodes->append(subRoot);
        while (nodes->getLength() != 0) {
            auto s = subNodes->get(0);
            auto n = nodes->get(0);
            for (int i = 0;i<n->childAmount();i++) {
                auto* nChild = n->getChild(i);
                auto* sChild = s->getChild(i);
                if (nChild->childAmount() != sChild->childAmount() || nChild->get() != sChild->get()) {
                    return false;
                }
                nodes->append(nChild);
                subNodes->append(sChild);
            }
            nodes->remove(0);
            subNodes->remove(0);
        }
        return true;
    }

    friend std::ostream &operator<<(std::ostream &os, const Tree &c) {
        os << "t[";
        auto* nodes = new LinkedList<Node<T>*>();
        nodes->append(c.root);
        while(nodes->getLength()!=0) {
            auto* n = nodes->get(0);
            os << n->get() << "->(";
            for (int i = 0;i<n->childAmount();i++) {
                if (i != 0) {
                    os << ", ";
                }
                auto tmp = n->getChild(i);
                os << tmp->get();
                nodes->append(tmp);
            }
            os << ")";
            nodes->remove(0);
            if (!nodes->isEmpty()) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }
};

#endif //LAB4_TREE_H
