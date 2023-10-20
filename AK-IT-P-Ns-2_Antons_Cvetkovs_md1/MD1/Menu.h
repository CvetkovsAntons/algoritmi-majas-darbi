#ifndef MD1_MENU_H
#define MD1_MENU_H

#include <iostream>

// izvelnes kalse

using namespace std;

class Menu {
public:
    Menu();
    ~Menu();
private:
    static bool getMenu(const string&);
    static void printMainMenu();
    static void printExitMenu();
    static string menuInput(int);
    static int inputValidation(const string&, int, const string&);
    static bool inputIsDigit(string);
};

#endif //MD1_MENU_H
