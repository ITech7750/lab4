

#ifndef LAB4_HEAPCONTROLLER_H
#define LAB4_HEAPCONTROLLER_H

#include "Controller.h"
#include "../../data/heap/Heap.h"

class HeapController : public Controller {
private:
    Map<String, Heap<int> *> *dataInt;
    Map<String, Heap<double> *> *dataDouble;
    Map<String, Heap<String> *> *dataString;

    void init(String name, String type) {
        if (type == "int") {
            (*dataInt)[name] = new Heap<int>();
        } else if (type == "double") {
            (*dataDouble)[name] = new Heap<double>();
        } else if (type == "String") {
            (*dataString)[name] = new Heap<String>();
        } else {
            throw WrongType();
        }
    }

    void add(String name, String value) {
        if ((*dataInt)[name] != nullptr) {
            (*dataInt)[name]->add(std::stoi(value));
        } else if ((*dataDouble)[name] != nullptr) {
            (*dataDouble)[name]->add(std::stod(value));
        } else if ((*dataString)[name] != nullptr) {
            (*dataString)[name]->add(value);
        } else {
            throw Exception("Heap with name = " + name + " does not exist");
        }
    }

    void popMax(String name) {
        if ((*dataInt)[name] != nullptr) {
            std::cout << (*dataInt)[name]->popMax();
        } else if ((*dataDouble)[name] != nullptr) {
            std::cout << (*dataDouble)[name]->popMax();
        } else if ((*dataString)[name] != nullptr) {
            std::cout << (*dataString)[name]->popMax();
        } else {
            throw Exception("Heap with name = " + name + " does not exist");
        }
        std::cout << "\n";
    }

    void getPosition(String name, String value) {
        if ((*dataInt)[name] != nullptr) {
            std::cout << (*dataInt)[name]->getPosition(std::stoi(value));
        } else if ((*dataDouble)[name] != nullptr) {
            std::cout << (*dataDouble)[name]->getPosition(std::stod(value));
        } else if ((*dataString)[name] != nullptr) {
            std::cout << (*dataString)[name]->getPosition(value);
        } else {
            throw Exception("Heap with name = " + name + " does not exist");
        }
    }

    void subHeap(String name, String subHeapName, String start) {
        if ((*dataInt)[name] != nullptr) {
            auto *buf = (*dataInt)[name]->subHeap(std::stoi(start));
            (*dataInt)[subHeapName] = buf;
        } else if ((*dataDouble)[name] != nullptr) {
            auto *buf = (*dataDouble)[name]->subHeap(std::stoi(start));
            (*dataDouble)[subHeapName] = buf;
        } else if ((*dataString)[name] != nullptr) {
            auto *buf = (*dataString)[name]->subHeap(std::stoi(start));
            (*dataString)[subHeapName] = buf;
        } else {
            throw Exception("Heap with name = " + name + " does not exist");
        }
    }

    void getSize(String name) {
        if ((*dataInt)[name] != nullptr) {
            std::cout << (*dataInt)[name]->getSize();
        } else if ((*dataDouble)[name] != nullptr) {
            std::cout << (*dataDouble)[name]->getSize();
        } else if ((*dataString)[name] != nullptr) {
            std::cout << (*dataString)[name]->getSize();
        } else {
            throw Exception("Heap with name = " + name + " does not exist");
        }
        std::cout << "\n";
    }

    void print(String name) {
        if ((*dataInt)[name] != nullptr) {
            std::cout << (*(*dataInt)[name]);
        } else if ((*dataDouble)[name] != nullptr) {
            std::cout << (*(*dataDouble)[name]);
        } else if ((*dataString)[name] != nullptr) {
            std::cout << (*(*dataString)[name]);
        } else {
            throw Exception("Heap with name = " + name + " does not exist");
        }
        std::cout << "\n";
    }

    void all() {
        for (auto iter{dataInt->begin()}; iter != dataInt->end(); iter++) {
            if (iter->second != nullptr) {
                std::cout << "  (int) " << iter->first << "\n";
            }
        }
        for (auto iter{dataDouble->begin()}; iter != dataDouble->end(); iter++) {
            if (iter->second != nullptr) {
                std::cout << "  (double) " << iter->first << "\n";
            }
        }
        for (auto iter{dataString->begin()}; iter != dataString->end(); iter++) {
            if (iter->second != nullptr) {
                std::cout << "  (string) " << iter->first << "\n";
            }
        }
    }

    void contain(String name, String heap1) {
        bool result;
        if ((*dataInt)[name] != nullptr) {
            result = (*(*dataInt)[name]).contain(*(*dataInt)[heap1]);
        } else if ((*dataDouble)[name] != nullptr) {
            result = (*(*dataDouble)[name]).contain(*(*dataDouble)[heap1]);;
        } else if ((*dataString)[name] != nullptr) {
            result = (*(*dataString)[name]).contain(*(*dataString)[heap1]);;
        } else {
            throw Exception("Heap with name = " + name + " does not exist");
        }
        if (result) {
            std::cout << "true";
        } else {
            std::cout << "false";
        }
        std::cout << "\n";
    }

public:
    String title = "heap";


    HeapController() {
        dataString = new Map<String, Heap<String> *>();
        dataInt = new Map<String, Heap<int> *>();
        dataDouble = new Map<String, Heap<double> *>();
    }

    State process(std::vector<String> command) override {
        try {
            String cmd = command[1];
            String name = command[2];
            if (cmd == "init") {
                String type = command[3];
                init(name, type);
                for (int i = 5; i < command.size(); i++) {
                    add(name, command[i]);
                }
            } else if (cmd == "add") {
                String value = command[3];
                add(name, value);
            } else if (cmd == "pop-max") {
                popMax(name);
            } else if (cmd == "get-position") {
                String value = command[3];
                getPosition(name, value);
            } else if (cmd == "sub-heap") {
                String subHeapName = command[3];
                String start = command[4];
                subHeap(name, subHeapName, start);
            } else if (cmd == "get-size") {
                getSize(name);
            } else if (cmd == "print") {
                print(name);
            } else if (cmd == "all") {
                all();
            } else if (cmd == "contain") {
                String subHeapName = command[3];
                contain(name, subHeapName);
            } else {
                throw Exception("command not exist");
            }
            return Success;
        } catch (Exception &e) {
            std::cout << e._message << "\n";
            return Error;
        }
    }
};

#endif //LAB4_HEAPCONTROLLER_H
