#ifndef LAB2_CONTROLLER_H
#define LAB2_CONTROLLER_H

#include <map>
#include "../../util/Definition.h"
#include "../util/State.h"

class Controller {
public:
    virtual State process(std::vector<String> command) = 0;
};

#endif //LAB2_CONTROLLER_H
