#ifndef AK_IT_P_NS_2_ANTONS_CVETKOVS_MD2_MENU_H
#define AK_IT_P_NS_2_ANTONS_CVETKOVS_MD2_MENU_H

#include <iostream>
#include "Constants.h"
#include "LinkedList.h"
using namespace std;

class Menu {
public:
    explicit Menu();
    bool getMenu();
    ~Menu();

private:
    string menu = M_MAIN;
    string allowedInputs[5] = {I_HELP, I_COORDINATES, I_REMOVE, I_QUEUE, I_EXIT};
    LinkedList * linked_list;

    void printMenu();
    void printMainMenu();
    void printHelpMenu();
    string coordinatesInput(const string &);
    string menuInput();
    string menuInputValidation();
    string coordinatesInputValidation(const string &);
    bool menuInputIsValid(const string &);
    bool coordinatesInputIsValid(const string &);

    void pushCoordinates();

    bool menuAction(const string &input);
};

#endif //AK_IT_P_NS_2_ANTONS_CVETKOVS_MD2_MENU_H