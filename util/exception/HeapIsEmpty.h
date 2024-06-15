

#ifndef LAB4_HEAPISEMPTY_H
#define LAB4_HEAPISEMPTY_H


#include "Exception.h"

class HeapIsEmpty : public Exception {
public:
    HeapIsEmpty() : Exception("Exception DequeIsEmpty : deque is empty") {}
};

#endif //LAB4_HEAPISEMPTY_H
