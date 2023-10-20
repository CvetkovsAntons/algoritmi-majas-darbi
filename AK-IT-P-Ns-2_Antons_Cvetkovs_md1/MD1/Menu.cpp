#include "Menu.h"
#include "GenerateCsv.h"
#include "QuickSort.h"

Menu::Menu()
{
    while (Menu::getMenu("main")); // programma stradas, kamer return nebus false
}

bool Menu::getMenu(const string& menu_name) // funkcija izvada izvelnes
{
    if (menu_name == "main") {
        Menu::printMainMenu();
        int input = Menu::inputValidation(Menu::menuInput(3), 3, menu_name);
        return true;
    } else {
        Menu::printExitMenu();
        if (Menu::inputValidation(Menu::menuInput(2), 2, menu_name) == 1) return false;
        else return true;
    }
}

void Menu::printMainMenu()
{
    system("cls");
    cout << "---------Main Menu---------" << endl;
    cout << "1. Generate/regenerate CSV" << endl;
    cout << "2. Run the algorithm" << endl;
    cout << "3. Exit" << endl;
    cout << "---------------------------"<< endl;
}

string Menu::menuInput(int max)
{
    string value;
    cout << "Choose number from 1-" << max << ": ";
    cin >> value;
    return value;
}

void Menu::printExitMenu()
{
    system("cls");
    cout << "---------Exit menu---------" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "---------------------------"<< endl;
}

int Menu::inputValidation(const string& input, int max, const string& menu_name)
{
    if (!Menu::inputIsDigit(input) || stoi(input) < 1 || stoi(input) > max) {
        cout << "\nERR! The input should be in between 1 to 3 and be an integer" << endl;
        system("pause");
        if (menu_name == "main") Menu::printMainMenu();
        else Menu::printExitMenu();

        Menu::inputValidation(Menu::menuInput(max), max, menu_name);
    }
    return stoi(input);
}

bool Menu::inputIsDigit(string input)
{
    for (char& c : input) if (!isdigit(c)) return false;
    return true;
}

Menu::~Menu() = default;
