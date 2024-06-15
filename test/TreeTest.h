#ifndef LAB4_TREETEST_H
#define LAB4_TREETEST_H

#include <iostream>
#include "../data/tree/Tree.h"
#include "../data/type/Complex.h"

void treeInit() {
    std::cout << "Tree init" << "\n";
    auto tree = new Tree<int>();
    std::cout << "Expected: " << "t[0->()]" << "\n";
    std::cout << "Found:    " << *tree;
    std::cout << "\n\n";
}

void treeInit2() {
    std::cout << "Tree init 2" << "\n";
    auto tree = new Tree<int>(2);
    std::cout << "Data:     " << 2 << "\n";
    std::cout << "Expected: " << "t[2->()]" << "\n";
    std::cout << "Found:    " << *tree;
    std::cout << "\n\n";
}


void treeInit3() {
    std::cout << "Tree init 3" << "\n";
    auto node = new Node<String>("test");
    auto tree = new Tree<String>(node);
    std::cout << "Data:     " << *node << "\n";
    std::cout << "Expected: " << "t[test->()]" << "\n";
    std::cout << "Found:    " << *tree;
    std::cout << "\n\n";
}

void treeAddNode() {
    std::cout << "Tree add node" << "\n";
    auto node = new Node<String>("test");
    auto tree = new Tree<String>(node);
    auto n = new Node<String>("text", node);
    auto n1 = new Node<String>("name", node);
    auto n2 = new Node<String>("error", n1);
    tree->addNode(n);
    tree->addNode(n1);
    tree->addNode(n2);
    std::cout << "Data:     " << *node << "\n";
    std::cout << "Expected: " << "t[test->(text, name), text->(), name->(error), error->()]" << "\n";
    std::cout << "Found:    " << *tree;
    std::cout << "\n\n";
}

void treeDeleteNode() {
    std::cout << "Tree delete node" << "\n";
    auto node = new Node<String>("test");
    auto tree = new Tree<String>(node);
    auto n = new Node<String>("text", node);
    auto n1 = new Node<String>("name", node);
    auto n2 = new Node<String>("error", n1);
    auto n3 =  new Node<String>("not error", n1);
    auto n4 = new Node<String>("end", n3);
    tree->addNode(n);
    tree->addNode(n1);
    tree->addNode(n2);
    tree->addNode(n3);
    tree->addNode(n4);
    std::cout << "Data:     " << *tree << "\n";
    tree->deleteNode(n1);
    std::cout << "Expected: " << "t[test->(text), text->()]" << "\n";
    std::cout << "Found:    " << *tree;
    std::cout << "\n\n";
}

void treeDeleteNodeException() {
    std::cout << "Tree delete node" << "\n";
    auto node = new Node<String>("test");
    auto tree = new Tree<String>(node);
    auto n = new Node<String>("text", node);
    auto n1 = new Node<String>("name", node);
    auto n2 = new Node<String>("error", n1);
    auto n3 =  new Node<String>("not error", n1);
    auto n4 = new Node<String>("end", n3);
    tree->addNode(n);
    tree->addNode(n1);
    tree->addNode(n2);
    tree->addNode(n3);
    tree->addNode(n4);
    std::cout << "Data:     " << *tree << "\n";
    std::cout << "Expected: " << "Exception NodeNotInTree: tree does not contain node" << "\n";
    try {
        tree->deleteNode(new Node<String>("asa", n1));
        std::cout << "Found:    " << *tree;
    } catch (Exception& e) {
        std::cout << e._message;
    }

    std::cout << "\n\n";
}

void treeMap() {
    std::cout << "Tree map" << "\n";
    auto node = new Node<Complex>(Complex(-1, 23));
    auto tree = new Tree<Complex>(node);
    auto n = new Node<Complex>(Complex(7, 3), node);
    auto n1 = new Node<Complex>(Complex(4, -1), node);
    auto n2 = new Node<Complex>(Complex(0.5, 7), n1);
    auto n3 =  new Node<Complex>(Complex(4.5, 4), n1);
    auto n4 = new Node<Complex>(Complex(12, 3), n3);
    tree->addNode(n);
    tree->addNode(n1);
    tree->addNode(n2);
    tree->addNode(n3);
    tree->addNode(n4);
    tree->addNode(new Node<Complex>(Complex(5, 9), n2));
    std::cout << "Data:     " << *tree << "\n";
    std::cout << "Expected: " << "t[-1->(7, 4), 7->(), 4->(0, 4), 0->(5), 4->(12), 5->(), 12->()]" << "\n";
    auto _tree = tree->map<int>([](Complex value) {
        return (int) value.re;
    });
    std::cout << "Found:    " << *_tree;
    std::cout << "\n\n";
}

void treeReduce() {
    std::cout << "Tree reduce" << "\n";
    auto node = new Node<Complex>(Complex(-1, 23));
    auto tree = new Tree<Complex>(node);
    auto n = new Node<Complex>(Complex(7, 3), node);
    auto n1 = new Node<Complex>(Complex(0, -1), node);
    auto n2 = new Node<Complex>(Complex(0.5, 7), n1);
    auto n3 =  new Node<Complex>(Complex(4.5, 4), n1);
    auto n4 = new Node<Complex>(Complex(12, 3), n3);
    tree->addNode(n);
    tree->addNode(n1);
    tree->addNode(n2);
    tree->addNode(n3);
    tree->addNode(n4);
    tree->addNode(new Node<Complex>(Complex(5, 9), n2));
    std::cout << "Data:     " << *tree << "\n";
    std::cout << "Expected: " << "29 + 49i" << "\n";
    auto result = tree->reduce([](Complex v1, Complex v2) {
        return  v1 + v2;
    }, Complex(1, 1));
    std::cout << "Found:    " << result;
    std::cout << "\n\n";
}

void treeSubTree() {
    std::cout << "Tree sub tree" << "\n";
    auto node = new Node<Complex>(Complex(-1, 23));
    auto tree = new Tree<Complex>(node);
    auto n = new Node<Complex>(Complex(7, 3), node);
    auto n1 = new Node<Complex>(Complex(0, -1), node);
    auto n2 = new Node<Complex>(Complex(0.5, 7), n1);
    auto n3 =  new Node<Complex>(Complex(4.5, 4), n1);
    auto n4 = new Node<Complex>(Complex(12, 3), n3);
    tree->addNode(n);
    tree->addNode(n1);
    tree->addNode(n2);
    tree->addNode(n3);
    tree->addNode(n4);
    tree->addNode(new Node<Complex>(Complex(5, 9), n2));
    std::cout << "Data:     " << *tree << "\n";
    std::cout << "Expected: " << "t[0 - 1i->(0.5 + 7i, 4.5 + 4i), 0.5 + 7i->(5 + 9i), 4.5 + 4i->(12 + 3i), 5 + 9i->(), 12 + 3i->()]" << "\n";
    auto subtree = tree->subTree(n1);
    std::cout << "Found:    " << *subtree;
    std::cout << "\n\n";
}

void treeContain() {
    std::cout << "Tree contain" << "\n";
    auto node = new Node<Complex>(Complex(-1, 23));
    auto tree = new Tree<Complex>(node);
    auto n = new Node<Complex>(Complex(7, 3), node);
    auto n1 = new Node<Complex>(Complex(0, -1), node);
    auto n2 = new Node<Complex>(Complex(0.5, 7), n1);
    auto n3 =  new Node<Complex>(Complex(4.5, 4), n1);
    auto n4 = new Node<Complex>(Complex(12, 3), n3);
    tree->addNode(n);
    tree->addNode(n1);
    tree->addNode(n2);
    tree->addNode(n3);
    tree->addNode(n4);
    tree->addNode(new Node<Complex>(Complex(5, 9), n2));

    auto t1 = new Node<Complex>(Complex(0, -1));
    auto tree1 = new Tree<Complex>(t1);
    auto t2 = new Node<Complex>(Complex(0.5, 7), t1);
    auto t3 =  new Node<Complex>(Complex(4.5, 4), t1);
    auto t4 = new Node<Complex>(Complex(12, 3), t3);
    tree1->addNode(t1);
    tree1->addNode(t2);
    tree1->addNode(t3);
    tree1->addNode(t4);
    tree1->addNode(new Node<Complex>(Complex(5, 9), t2));
    std::cout << "Data:     " << *tree << "\n";
    std::cout << "Expected: " << "true" << "\n";
    auto subtree = tree->containTree(tree);
    std::cout << "Found:    ";
    if (subtree) std::cout << "true";
    else std::cout << "false";
    std::cout << "\n\n";
}

void treeTest() {
    std::cout << "|Test tree\n";
    treeInit();
    treeInit2();
    treeInit3();
    treeAddNode();
    treeDeleteNode();
    treeDeleteNodeException();
    treeMap();
    treeReduce();
    treeSubTree();
    treeContain();
}

#endif //LAB4_TREETEST_H
