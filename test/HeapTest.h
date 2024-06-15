

#ifndef LAB4_HEAPTEST_H
#define LAB4_HEAPTEST_H

#include <iostream>
#include "../data/heap/Heap.h"
#include "../data/type/Student.h"
#include "../data/type/Complex.h"

void heapInit() {
    std::cout << "Heap init" << "\n";
    auto heap = new Heap<int>();
    std::cout << "Data:     " << *heap;
    std::cout << "\n";
    std::cout << "Expected: " << "h[]" << "\n";
    std::cout << "Found:    " << *heap;
    std::cout << "\n\n";
}


void heapInit2() {
    std::cout << "Heap init 2" << "\n";
    auto heap = new Heap<double>();
    heap->add(1.5);
    heap->add(3.4);
    heap->add(-4.1);
    heap->add(5);
    heap->add(7);
    heap->add(2425);
    heap->add(-112);
    auto heap1 = new Heap<double>(*heap, 2);
    std::cout << "Data:     " << *heap << "\n";
    std::cout << "Expected: " << "h[0:7->(1:-4.1, 2:-112), 1:-4.1->(), 2:-112->()]" << "\n";
    std::cout << "Found:    " << *heap1;
    std::cout << "\n\n";
}

void heapInit3() {
    std::cout << "Heap init 3" << "\n";
    auto values = new double[]{1.5, 12, -1, 9.7, 25.67, 1, -5, 1234.5, 120};
    auto heap = new Heap<double>(values);
    std::cout << "Data:     " << "" << "\n";
    std::cout << "Expected: " << "h[0:1234.5->(1:120, 2:1), 1:120->(3:25.67, 4:9.7), 2:1->(5:-1, 6:-5), 3:25.67->(7:1.5, 8:12), 4:9.7->(), 5:-1->(), 6:-5->(), 7:1.5->(), 8:12->()]" << "\n";
    std::cout << "Found:    " << *heap;
    std::cout << "\n\n";
}

void heapAdd() {
    std::cout << "Heap add" << "\n";
    auto data = new Student[]{
            Student(5, "Ivan", "Ivanov", "Mephi", "12.03.2000", "Moscow, Lenina 24", "+79901324051", 5),
            Student(4, "Ivan", "Kotov", "Mephi", "12.09.2002", "Moscow, Lenina 1", "+79909990151", 3),
            Student(2, "Kirill", "Tunaev", "UGNTU", "12.01.2001", "Moscow, Oktyabrskaya 46", "+79050100051", 4),
            Student(1, "Ivan", "Yusupov", "KFU", "12.03.2005", "Kazan, Tukaya 1", "+79933635131", 1),
            Student(3, "Anton", "Ivanov", "MEI", "12.12.1999", "Ryazan, Dostoevskaya 52", "+79870456051", 7)
    };
    auto heap = new Heap<Student>();
    for (int i = 0;i<5;i++) {
        heap->add(data[i]);
    }
    std::cout << "Data:     [Student(5), Student(4), Student(2), Student(1), Student(3)]";
    std::cout << "\n";
    std::cout << "Expected: " << "h[0:Student(5)->(1:Student(4), 2:Student(2)), 1:Student(4)->(3:Student(1), 4:Student(3)), 2:Student(2)->(), 3:Student(1)->(), 4:Student(3)->()]" << "\n";
    std::cout << "Found:    " << *heap;
    std::cout << "\n\n";
}

void heapPopMax() {
    std::cout << "Heap pop max" << "\n";
    auto data = new Complex[]{Complex(2, 3), Complex(1, 1), Complex(4, 0), Complex(9, -1), Complex(-5, -10), Complex(1.3, -0.5)};
    auto heap = new Heap<Complex>();
    for (int i = 0;i<6;i++) {
        heap->add(data[i]);
    }
    std::cout << "Data:     [2 + 3i, 1 + i, 4 + 0i, 9 - 1i, -5 - 10i, 1.3 -0.5i]";
    std::cout << "\n";
    std::cout << "Expected: " << "-5 - 10i" << "\n";
    std::cout << "Found:    " << heap->popMax();
    std::cout << "\n\n";
}

void heapContain() {
    std::cout << "Heap contain" << "\n";
    auto data = new int[]{3, 4, 5, 2, 76, 4, -1, 34, 12, 35, 65, -5, -3, 1, 0, 4532, 244, 524, 55, 7};
    auto heap = new Heap<int>();
    for (int i = 0;i<20;i++) {
        heap->add(data[i]);
    }
    auto heap1 = new Heap<int>();
    heap1->add(4);
    heap1->add(-5);
    heap1->add(-3);
    std::cout << *heap1;
    std::cout << "Data:     " << *heap << "\n";
    std::cout << "Expected: " << "true" << "\n";
    std::cout << "Found:    ";
    if (heap->contain(*heap1)) std::cout << "true";
    else std::cout << "false";
    std::cout << "\n\n";
}

void heapNotContain() {
    std::cout << "Heap not contain" << "\n";
    auto data = new int[]{3, 4, 5, 2, 76, 4, -1, 34, 12, 35, 65, -5, -3, 1, 0, 4532, 244, 524, 55, 7};
    auto heap = new Heap<int>();
    for (int i = 0;i<20;i++) {
        heap->add(data[i]);
    }
    auto heap1 = new Heap<int>();
    heap1->add(4);
    heap1->add(-9);
    heap1->add(-3);
    std::cout << "Data:     " << *heap << "\n";
    std::cout << "Expected: " << "true" << "\n";
    std::cout << "Found:    " << heap->contain(*heap1);
    std::cout << "\n\n";
}

void heapSubHeap() {
    std::cout << "Heap sub heap" << "\n";
    auto data = new int[]{3, 4, 5, 2, 76, 4, -1, 34, 12, 35, 65, -5, -3, 1, 0, 4532, 244, 524, 55, 7};
    auto heap = new Heap<int>();
    for (int i = 0;i<20;i++) {
        heap->add(data[i]);
    }
    auto heap1 = heap->subHeap(3);
    std::cout << "Data:      " << *heap << "\n";
    std::cout << "Expected:  " << "h[0:244->(1:65, 2:76), 1:65->(3:2, 4:12), 2:76->(5:5, 6:55), 3:2->(), 4:12->(), 5:5->(), 6:55->()]" << "\n";
    std::cout << "Found:     " << *heap1;
    std::cout << "\n\n";
}


void heapTest() {
    std::cout << "|Test heap\n";
    heapInit();
    heapInit2();
    heapInit3();
    heapAdd();
    heapPopMax();
    heapContain();
    heapNotContain();
    heapSubHeap();
}

#endif //LAB4_HEAPTEST_H
