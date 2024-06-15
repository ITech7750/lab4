

#ifndef LAB4_NODEISFULLEXCEPTION_H
#define LAB4_NODEISFULLEXCEPTION_H

#include "Exception.h"

class NodeIsFullException : public Exception {
public:
    NodeIsFullException() : Exception("Exception NodeIsFullException : node is full exception") {}
};

#endif //LAB4_NODEISFULLEXCEPTION_H
