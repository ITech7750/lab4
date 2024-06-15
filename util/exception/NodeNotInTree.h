#ifndef LAB4_NODENOTINTREE_H
#define LAB4_NODENOTINTREE_H

#include "Exception.h"

class NodeNotInTree : public Exception {
public:
    NodeNotInTree() : Exception("Exception NodeNotInTree: tree does not contain node") {}
};

#endif //LAB4_NODENOTINTREE_H
