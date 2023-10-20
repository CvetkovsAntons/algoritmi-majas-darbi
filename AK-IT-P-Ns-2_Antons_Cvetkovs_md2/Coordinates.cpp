#include "Coordinates.h"

#include <utility>

Coordinates::Coordinates(string x, string y) {
    this->x = x;
    this->y = y;
    next = nullptr;
    previous = nullptr;
}

string Coordinates::getCoordinates() { // funkcija izvada koordinates
    return "{ " + this->x + ", " + this->y + " }";
}

Coordinates::~Coordinates() = default;
