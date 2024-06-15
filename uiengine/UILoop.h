#ifndef LAB2_UILOOP_H
#define LAB2_UILOOP_H

#include <sstream>
#include <iostream>
#include "../util/Definition.h"
#include "../data/tree/Tree.h" // включаем заголовочный файл Tree.h

int uiLoop() {
    auto* tree = new Tree<int>(); // создаем экземпляр дерева, например, для целых чисел
    String command;
    
    std::cout << "UI for lab4\n";
    std::cout << "...............................................\n";
    std::cout << "- docs *type* | view documentation, type(tree)" << "\n";
    std::cout << "- add *value* | add a node to the tree with the specified value\n";
    std::cout << "- delete *value* | delete a node from the tree with the specified value\n";
    std::cout << "- map *function* | map a function over the tree\n";
    std::cout << "- reduce *function* *initial_value* | reduce the tree with a function and initial value\n";
    std::cout << "- subtree *value* | create a subtree with the specified value\n";
    std::cout << "- view | view the current state of the tree\n";
    std::cout << "...............................................\n";
    std::cout << "- ";
    
    getline(std::cin, command);
    
    while (command != "exit") {
        try {
            String tmp;
            std::stringstream stream(command);
            std::vector<String> words;

            while (std::getline(stream, tmp, ' ')) {
                words.push_back(tmp);
            }

            if (words[0] == "docs") {
                if (words[1] == "tree") {
                    std::cout << "Documentation for Tree operations\n\n";
                    
                } else {
                    std::cout << "Invalid documentation type\n\n";
                }
            } else if (words[0] == "add") {
                int value = std::stoi(words[1]);
                tree->addNode(new Node<int>(value));
                std::cout << "Node added\n\n";
            } else if (words[0] == "delete") {
                int value = std::stoi(words[1]);
                tree->deleteNode(new Node<int>(value));
                std::cout << "Node deleted\n\n";
            } else if (words[0] == "map") {
                // Реализация функционала map (применение функции к каждому элементу дерева)
                // Пример: tree = tree->map(...);
                std::cout << "Map operation completed\n\n";
            } else if (words[0] == "reduce") {
                // Реализация функционала reduce (свертка дерева)
                // Пример: int result = tree->reduce(...);
                std::cout << "Reduce operation completed\n\n";
            } else if (words[0] == "subtree") {
                int value = std::stoi(words[1]);
                Tree<int>* subTree = tree->subTree(new Node<int>(value));
                std::cout << "Subtree created: " << *subTree << "\n\n";
                delete subTree; // освобождаем выделенную память для поддерева
            } else if (words[0] == "view") {
                std::cout << "Current state of the tree:\n";
                std::cout << *tree << "\n\n";
            } else {
                std::cout << "Invalid command\n\n";
            }
        } catch (Exception &e) {
            std::cout << e._message << "\n\n";
        }

        std::cout << "- ";
        getline(std::cin, command);
    }

    delete tree; // освобождаем выделенную память для дерева
    return 0;
}

#endif // LAB2_UILOOP_H
