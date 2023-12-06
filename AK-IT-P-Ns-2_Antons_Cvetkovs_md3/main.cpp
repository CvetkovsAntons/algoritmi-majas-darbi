#include <iostream>
#include "Menu.h"

using namespace std;

int main() {
    Menu * menu = new Menu();
    while (menu->getMenu());
    return 0;
}
