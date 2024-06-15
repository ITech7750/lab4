
#ifndef LAB4_HEAPDOCS_H
#define LAB4_HEAPDOCS_H

#include <iostream>

void heapdocs() {
    std::cout
            << "- heap init *name* *type* -p ... | name - name of heap; type - primitive(int, double, string...); -p - parameters";
    std::cout << "\n";
    std::cout << "- heap add *name* *value* | value - value to be added";
    std::cout << "\n";
    std::cout << "- heap pop-max *name*";
    std::cout << "\n";
    std::cout << "- heap get-position *name* *value*";
    std::cout << "\n";
    std::cout << "- heap sub-heap *name* *start*";
    std::cout << "\n";
    std::cout << "- heap contain *name* *sub heap*";
    std::cout << "\n";
    std::cout << "- heap print *name*";
    std::cout << "\n";
    std::cout << "- heap all";
    std::cout << "\n";

}

#endif //LAB4_HEAPDOCS_H
