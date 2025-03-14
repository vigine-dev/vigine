#include "vigine/component/rendercomponent.h"
#include <iostream>

RenderComponent::RenderComponent() {
    // Конструктор
}

void RenderComponent::render() {
    std::cout << "Rendering component" << std::endl;
}
