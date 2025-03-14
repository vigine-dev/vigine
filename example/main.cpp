#include <iostream>
#include "vigine.h"
#include <glm/glm.hpp>

int main() {
    std::cout << "Example project running..." << std::endl;
    // Call a function from the library
 

    // Use glm
    glm::vec3 v(1.0f, 0.0f, 0.0f);
    std::cout << "glm vector: (" << v.x << ", " << v.y << ", " << v.z << ")" << std::endl;

    return 0;
}
