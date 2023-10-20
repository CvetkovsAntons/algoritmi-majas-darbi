#include "Menu.h"

Menu::Menu() {
    linked_list = new LinkedList(10); // veidojam LinkedList objektu ar garumu == 10
}

bool Menu::getMenu() {
    printMenu(); // izvadam izvelni
    string input = menuInputValidation(); // ievadam darbibu, kuru jaizpilda programmai
    return menuAction(input); // dabjam ievadito darbibu
}

bool Menu::menuAction(const string & input) {
    if (input == I_HELP) menu = M_HELP; // ja tiek ievadits h, tad paradam help lapu
    else if (input == I_COORDINATES) pushCoordinates(); // ja tiek ievadits +x,y, tad pieskiram koordinates rindaa
    else if (input == I_REMOVE) linked_list->pop(); // ja tiek ievadits -, tad iznemam koordinates no rindas
    else if (input == I_QUEUE) linked_list->print(); // ja tiek ievadits *, tad izvadam visu rindu
    else if (input == I_EXIT) return false; // ja tiek ievadits $, tad atgriezam FALSE, partraucot programma darbu
    return true; // atgriezam TRUE, programma turpina darbu
}

void Menu::pushCoordinates() {
    if (!linked_list->isFull()) { // parbaudam vai rinda ir pilna, ja ne, tad pieskiram koordinates
        string x = coordinatesInputValidation(C_X); // ievadam X
        string y = coordinatesInputValidation(C_Y); // ievadam Y
        linked_list->push(x, y); // pieskiram koordinates rindaa
    } else { // ja rinda ir pilna, tad izvadam pazinojumu
        cout << "overflow" << endl;
        system("pause");
    }
}
// funkcija, kas parbauda ievadi izvelenee un turpina darbu, kamer ta ir nepareiza
string Menu::menuInputValidation() {
    string input = menuInput();
    while (!menuInputIsValid(input)) {
        system("pause");
        input = menuInput();
    }
    menu = M_MAIN;
    return input;
}
// funkcija, kas parbauda vai ievads ir pareizs
bool Menu::menuInputIsValid(const string &input) {
    // lai dabut masiva garumu ir jasadala baita summu ar data tipa izmeru
    for (int i = 0; i < (sizeof(allowedInputs) / sizeof(string)); i++) {
        if (input == allowedInputs[i]) return true;
    }
    cout << "\n" << ERR_INCORRECT_INPUT << endl;
    return false;
}
// funkcija, kas parbauda vai koordinates ir ievaditi pareizi
string Menu::coordinatesInputValidation(const string & point) {
    string input = coordinatesInput(point);
    while (!coordinatesInputIsValid(input)) {
        system("pause");
        input = coordinatesInput(point);
    }
    menu = M_MAIN;
    return input;
}
// funkcija, kas parbauda vai koordinates ievads ir pareizs
bool Menu::coordinatesInputIsValid(const string & input) {
    string first_char = input.substr(0, (input.length() - 1) - (input.length() - 2));
    // ja piramis simbols ir +, - vai cipars, tad parbaudam vai ievads ir skaistlis
    if (isdigit(input.at(0)) || first_char == "+" || first_char == "-") {
        int point_count = 0;
        for (int i = 1; i < input.length(); i++) {
            if (input.at(i) == '.') point_count++;
            if ((!isdigit(input[i]) && input.at(i) != '.') || point_count > 1) {
                cout << "\n" << ERR_NOT_A_NUMBER << endl;
                return false;
            }
        }
    } else { // ja, pirmais simbols nav +,- vai cipars, tad izvadam kludu
        cout << "\n" << ERR_INCORRECT_INPUT << endl;
        return false;
    }

    return true;
}

string Menu::menuInput() {
    string value;
    cout << "Input:";
    cin >> value;
    return value;
}

string Menu::coordinatesInput(const string & point) {
    string input;
    cout << point << ": ";
    cin >> input;
    return input;
}

void Menu::printMenu() {
    system("cls");
    if (menu == M_MAIN) {
        printMainMenu();
    } else {
        printHelpMenu();
    }
}

void Menu::printMainMenu() {
    cout << "---------------------------" << endl;
    cout << "Input 'h' to open help page" << endl;
    cout << "---------------------------" << endl;
}

void Menu::printHelpMenu() {
    cout << "------------Help-----------" << endl;
    cout << "h - help page" << endl;
    cout << "+x,y - add coordinates (x and y represents a N)" << endl;
    cout << "- - remove coordinates" << endl;
    cout << "* - output queue" << endl;
    cout << "$ - exit" << endl;
    cout << "---------------------------" << endl;
}

Menu::~Menu() = default;
