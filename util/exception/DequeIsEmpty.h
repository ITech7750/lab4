
#ifndef LAB3_DEQUEISEMPTY_H
#define LAB3_DEQUEISEMPTY_H

#include "Exception.h"

class DequeIsEmpty : public Exception {
public:
    DequeIsEmpty() : Exception("Exception DequeIsEmpty : deque is empty") {}
};


#endif //LAB3_DEQUEISEMPTY_H
