
#ifndef LAB2_LINKEDLIST_H
#define LAB2_LINKEDLIST_H

#include <iostream>
#include "Element.h"
#include "../util/exception/IndexOutOfRange.h"

template<class T>
class LinkedList {
private:
    Element<T> *_first;
    Element<T> *_last;
    int _length{};

public:
    LinkedList() {
        _length = 0;
        _first = nullptr;
        _last = nullptr;
    }

    LinkedList(int count, T *items) : LinkedList() {
        for (int i = 0; i < count; i++) {
            append(items[i]);
        }
    }

    LinkedList(LinkedList<T> &list) : LinkedList() {
        for (int i = 0; i < list.getLength(); i++) {
            append(list.get(i));
        }
    }

    T getFirst() {
        if (_first != nullptr) {
            return (*_first)();
        } else {
            throw IndexOutOfRange();
        }

    }

    T getLast() {
        if (_last != nullptr) {
            return (*_last)();
        } else {
            throw IndexOutOfRange();
        }

    }

    T get(int index) const {
        int i = 0;
        if (index < 0 || index >= _length) {
            throw IndexOutOfRange();
        }
        Element<T> *buf = _first;
        while (i < index) {
            i++;
            buf = (*buf).getNext();
        }
        return (*buf)();
    }

    T operator[](int index) const {
        return get(index);
    }

    LinkedList<T> *getSublist(int start, int end) {
        if (start >= _length || end >= _length || start < 0 || end < 0 || start >= end) {
            throw IndexOutOfRange();
        }
        auto *buf = new LinkedList<T>();
        for (int i = 0; i < _length; i++) {
            if (i >= start && i < end) {
                buf->append(get(i));
            }
        }
        return buf;
    }

    int getLength() {
        return _length;
    }

    void append(T value) {
        if (_first == nullptr) {
            _first = new Element<T>(value);
        } else if (_last == nullptr) {
            _last = new Element<T>(value, _first, nullptr);
            (*_first).setNext(_last);
        } else {
            auto *buf = new Element<T>(value, _last, nullptr);
            (*_last).setNext(buf);
            _last = buf;
        }
        _length++;
    }

    void prepend(T value) {
        if (_first == nullptr) {
            _first = new Element<T>(value, nullptr, nullptr);
        } else if (_last == nullptr) {
            _last = new Element<T>((*_first).get(), _first, nullptr);
            _first = new Element<T>(value, nullptr, _last);
        } else {
            auto *buf = new Element<T>(value, nullptr, _first);
            (*_first).setPrevious(buf);
            _first = buf;
        }
        _length++;

    }

    void insertAt(int index, T value) {
        if (index >= _length || index < 0) {
            throw IndexOutOfRange();
        }
        Element<T> *buf = _first;
        for (int i = 0; i < index; i++) {
            buf = buf->getNext();
        }
        buf->set(value);
    }

    LinkedList<T> *concat(LinkedList<T> *list) {
        auto *buf = new LinkedList<T>(this);
        for (int i = 0; i < (*list).getLength(); i++) {
            (*buf).append((*list).get(i));
        }
        return buf;
    }

    void remove(int index) {
        if (index > _length || index < 0) {
            return;
        }
        if (index == 0) {
            Element<T> *nxt = (*_first).getNext();
            delete _first;
            _first = nxt;
            if (_first != nullptr) {
                (*_first).setPrevious(nullptr);
            }
            if (_length == 2) {
                _last = nullptr;
            }
        } else if (index == _length - 1) {
            Element<T> *prv = (*_last).getPrevious();
            delete _last;
            _last = prv;
            if (_last != nullptr) {
                (*_last).setNext(nullptr);
            }
            if (_length == 2) {
                (*_first) = (*_last);
                _last = nullptr;
            }
        } else {
            Element<T> *buf = (*_first).getNext();
            for (int i = 0; i < index; i++) {
                buf = (*buf).getNext();
            }
            Element<T> *nxt = (*buf).getNext();
            Element<T> *prv = (*buf).getPrevious();
            delete buf;
            (*prv).setNext(nxt);
            (*nxt).setPrevious(prv);
        }
        _length--;
    }

    bool isEmpty() {
        return _length == 0;
    }

    void println() {
        Element<T> *buf = _first;
        std::cout << "[";
        if (buf != nullptr) {
            std::cout << buf->get();
            while (buf->getNext() != nullptr) {
                buf = buf->getNext();
                std::cout << ", ";
                std::cout << buf->get();
            }
            std::cout << "]" << "\n";
        }
    }

    void print() {
        Element<T> *buf = _first;
        std::cout << "[";
        if (buf != nullptr) {
            std::cout << buf->get();
            while (buf->getNext() != nullptr) {
                buf = buf->getNext();
                std::cout << ", ";
                std::cout << buf->get();
            }
            std::cout << "]";
        }
    }

};

#endif //LAB2_LINKEDLIST_H
