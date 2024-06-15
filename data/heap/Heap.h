
#ifndef LAB4_HEAP_H
#define LAB4_HEAP_H

#include "../dynamicarray/DynamicArray.h"
#include "../../linkedlist/LinkedList.h"
#include "../../util/exception/HeapIsEmpty.h"

template<class T>
class Heap {
private:
    DynamicArray<T> *elem;
    int size;

    void siftUp(int i) {
        if (size == 1) return;
        while ((*elem)[i] > (*elem)[(i - 1) / 2]) {
            elem->swap(i, (i - 1) / 2);
            i = (i - 1) / 2;
            if (!i) break;
        }
    }

    void siftDown(int i) {
        int left, right, j;
        while (2 * i + 1 < size) {
            left = 2 * i + 1;
            right = 2 * i + 2;
            j = left;
            if (right < size && (*elem)[right] > (*elem)[left]) j = right;
            if ((*elem)[i] >= (*elem)[j]) break;
            elem->swap(i, j);
            i = j;
        }
    }

public:
    Heap() {
        elem = new DynamicArray<T>();
        size = 0;
    }

    Heap(const Heap &h, int offset) : Heap() {
        int i = offset;
        auto nodes = new LinkedList<int>();
        nodes->append(i);
        while (!nodes->isEmpty()) {
            int k = nodes->get(0);
            add(h[k]);
            if (2 * k + 1 < h.size) {
                nodes->append(2 * k + 1);
            }
            if (2 * k + 2 < h.size) {
                nodes->append(2 * k + 2);
            }
            nodes->remove(0);
        }
    }

    Heap(T* values): Heap() {
        int i = 0;
        while(values[i]) {
            add(values[i]);
            i++;
        }
    }

    void add(T value) {
        size++;
        elem->add(value);
        siftUp(size - 1);
    }

    T popMax() {
        if (!size) throw HeapIsEmpty();
        T value = (*elem)[0];
        (*elem).swap(0, size - 1);
        size--;
        siftDown(0);
        elem->remove(size - 1);
        return value;
    }

    int getPosition(T value) {
        for (int i = 0; i < size; i++) {
            if (value == (*elem)[i]) {
                return i;
            }
        }
        return -1;
    }

    bool contain(Heap<T> heap) {
        T root = heap[0];
        auto ind = new LinkedList<int>();
        for (int j = 0;j<size;j++) {
            if ((*elem)[j] == root) {
                ind->append(j);
            }
        }
        if (ind->isEmpty()) return false;

        while (!ind->isEmpty()) {
            int i = ind->get(0);
            auto buf = new LinkedList<int>();
            auto buf1 = new LinkedList<int>();
            buf->append(i);
            buf1->append(0);
            int flag = 0;
            while (!buf->isEmpty()) {
                int k = buf->get(0);
                int k1 = buf1->get(0);
                if (heap.size <= 2 * k1 + 1 || heap.size <= 2 * k1 + 2) {
                    flag = 1;
                    break;
                } else if (size <= 2 * k + 1 || size <= 2 * k + 2) {
                    flag = -1;
                    break;
                }
                T rh = heap[2 * k1 + 1];
                T re = (*elem)[2 * k + 1];
                T lh = heap[2 * k1 + 2];
                T le = (*elem)[2 * k + 2];
                if (rh == re && lh == le) {
                    buf->append(2 * k + 1);
                    buf->append(2 * k + 2);
                    buf1->append(2 * k1 + 1);
                    buf1->append(2 * k1 + 2);
                } else {
                    flag = -1;
                    break;
                }
                buf->remove(0);
                buf1->remove(0);
            }
            if (flag == -1) {
                ind->remove(0);
            } else {
                return true;
            }
        }
        return false;
    }

    Heap<T> *subHeap(int i) {
        if (i >= size) throw IndexOutOfRange();
        auto buf = new Heap<T>();
        auto nodes = new LinkedList<int>();
        nodes->append(i);
        while (!nodes->isEmpty()) {
            int k = nodes->get(0);
            buf->add((*elem)[k]);
            if (2 * k + 1 < size) {
                nodes->append(2 * k + 1);
            }
            if (2 * k + 2 < size) {
                nodes->append(2 * k + 2);
            }
            nodes->remove(0);
        }
        return buf;
    }

    T operator[](int index) const {
        return (*elem)[index];
    }

    int getSize() {
        return size;
    }

    bool operator>(const Heap &c) const {
        return size > c.size;
    }

    bool operator<(const Heap &c) const {
        return size < c.size;
    }

    bool operator>=(const Heap &c) const {
        return size >= c.size;
    }

    bool operator<=(const Heap &c) const {
        return size <= c.size;
    }

    bool operator==(const Heap &c) const {
        return size == c.size;
    }

    friend std::ostream &operator<<(std::ostream &os, const Heap &c) {
        os << "h[";
        for (int i = 0; i < c.size; i++) {
            if (i != 0) os << ", ";
            os << i << ":" << c[i] << "->(";
            if (2 * i + 1 < c.size) {
                os << 2 * i + 1 << ":" << c[2 * i + 1];
            }
            if (2 * i + 2 < c.size) {
                os << ", " << 2 * i + 2 << ":" << c[2 * i + 2];
            }
            os << ")";
        }
        os << "]";
        return os;
    }

};

#endif //LAB4_HEAP_H
