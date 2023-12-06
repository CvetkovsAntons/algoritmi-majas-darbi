#ifndef AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_MENU_H
#define AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_MENU_H

#include <iostream>
#include <algorithm>
#include <string>
#include "Tree.h"
#include "Constants.h"

using namespace std;

class Menu {
public:
    explicit Menu();
    bool getMenu();
    ~Menu();

private:
    Tree * tree;
    string menu = M_MAIN;
    string error;
    vector<char> allowedInputs = { I_HELP, I_NEW, I_DELETE, I_SHOW, I_EXIT };

    void printMenu();
    void printMainMenu();
    void printHelpMenu();
    string menuInput();
    string menuInputValidation();
    vector<string> inputNewNode(const string &);
    int inputId(const string &, bool);
    bool menuAction(const string &input);
    bool validateCommand(const string &input);
    bool validateIdInput(const string &input);
    bool validateNewNodeInput(const string &input);
    bool validateParent(const string &input);

    bool validateDuplicates(const string &id, const string &type);
};

Menu::Menu() {
    this->tree = new Tree(); // veidojam tree objektu
}

bool Menu::getMenu() {
    printMenu(); // izvadam izvelni
    string input = menuInputValidation(); // ievadam darbibu, kuru jaizpilda programmai
    return this->menuAction(input); // dabjam ievadito darbibu
}

bool Menu::menuAction(const string & input) {
    if (input[0] == I_HELP) menu = M_HELP; // ja tiek ievadits h, tad paradam help lapu
    else if (input[0] == I_NEW) tree->newNode(this->inputNewNode(input)); // ja tiek ievadits +, tad pievienojam jaunu zaru kokaa
    else if (input[0] == I_DELETE) tree->deleteNode(this->inputId(input, false)); // ja tiek ievadits -, tad idzesam koka zaru
    else if (input[0] == I_SHOW) tree->print(this->inputId(input, true)); // ja tiek ievadits *, tad izvadam koku
    else if (input[0] == I_EXIT) return false; // ja tiek ievadits $, tad atgriezam FALSE, partraucot programma darbu
    return true; // atgriezam TRUE, programma turpina darbu
}


vector<string> Menu::inputNewNode(const string & input) {
    string s = input.substr(1, input.size() - 1); // nonem pirmo simbolu no ievaditas virknes
    return split(s, ","); // dabunam masivu no ievades
}

int Menu::inputId(const string & input, bool is_show) {
    // dabujam id no * vai - ievadei
    // ja * tiek ievadita bez id, tad atgriezam -1
    return is_show && input.length() == 1 ? -1 : stoi(input.substr(1, input.size() - 1));
}

// funkcija, kas parbauda ievadi izvelenee un turpina darbu, kamer ta ir nepareiza
string Menu::menuInputValidation() {
    string input = menuInput();
    while (!validateCommand(input)) {
        cout << this->error << '\n' << endl;
        system("pause");
        input = menuInput();
    }
    menu = M_MAIN;
    return input;
}

bool Menu::validateCommand(const string & input) {
    // ja tiek ievadits simbols, kas nav atlauts, tad izvadam kludu par to
    if (find(allowedInputs.begin(), allowedInputs.end(), input[0]) == allowedInputs.end()) {
        this->error = ERR_INCORRECT_INPUT;
        return false;
    }
    if (input[0] == I_NEW) { // ja ir ievadits +, tad parbaudam vai komanda ir ievadita pareizi
        return this->validateNewNodeInput(input);
    } else if (input[0] == I_DELETE || (input[0] == I_SHOW && input.length() > 1)) {
        // tas pats, ja tiek ievadits - vai * ar id
        return this->validateIdInput(input);
    } else {
        // viss parejais ir true
        return true;
    }
}
// funkcija parbuda + komandas ievadi
bool Menu::validateNewNodeInput(const string & input) {
    // dabunam masivu no string
    vector<string> array = split(input.substr(1, input.size() - 1), ",");
    // masiva nav 4 ieraksti, tad pazinojam, par kludu
    if (array.size() != 4) {
        this->error = ERR_INCORRECT_INPUT;
        return false;
    }
    // ja id vai parent nav cipars, tad izvadam kludu
    if (!isDigit(array[0]) || !isDigit(array[1]) ) {
        this->error = ERR_NOT_A_NUMBER;
        return false;
    }
    // ja faila nosaukums ir tuks, tad izvadam kludu
    if (array[2].length() == 0) {
        this->error = ERR_NEW_NODE_EMPTY_NAME;
        return false;
    }
    // ja tips nav ne fails, ne katalogs, tad izvadam kludu
    if (array[3] != T_FILE && array[3]  != T_DIRECTORY) {
        this->error = ERR_INCORRECT_TYPE;
        return false;
    }
    // ja ir duplikats ar citu tipu, tad iavdam kludu
    if (!this->validateDuplicates(array[0], array[3])) return false;
    // parbaudam vai noradits parent eksiste un ta tips ir katalogs
    return this->validateParent(array[1]);
}

bool Menu::validateParent(const string & input) {
    // atrodam noradito parent
    Node * parent = this->tree->search(stoi(input), tree->getRoot());
    if (!parent) { // ja tas nav atrasts, izvadam kludu
        this->error = ERR_PARENT_NODE_NOT_FOUND;
        return false;
    }
    // ja tas nav katalogs vai disks (root), tad izvadam kludu
    if (parent->getType() != T_DIRECTORY && parent->getType() != T_DISK) {
        this->error = ERR_PARENT_IN_NOT_A_FOLDER;
        return false;
    }
    return true;
}

bool Menu::validateDuplicates(const string & id, const string & type) {
    // atrodam zaru ar noradito id
    Node * duplicate = this->tree->search(stoi(id), tree->getRoot());
    // ja dublikatam ir cits tips, tad izvadam kludu
    if (duplicate && duplicate->getType() != type) {
        this->error = ERR_DUPLICATE_WITH_DIFFERENT_TYPE;
        return false;
    }
    return true;
}
// funkcija parbauda - un * ar id komandu ievadi
bool Menu::validateIdInput(const string & input) {
    string substring = input.substr(1, input.size() - 1);
    // ja nav ievadits cipars, tad iavadam kludu
    if (!isDigit(substring)) {
        this->error = ERR_NOT_A_NUMBER;
        return false;
    }
    // ja zars ar noradito id nav atrasts, izvadam kludu
    Node * node = this->tree->search(stoi(substring), tree->getRoot());
    if (!node) {
        this->error = ERR_NODE_NOT_FOUND;
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
    cout << "+id,parent,name,type - add node" << endl;
    cout << "-id - remove node" << endl;
    cout << "* - output tree" << endl;
    cout << "*id - output tree from specific node" << endl;
    cout << "$ - exit" << endl;
    cout << "---------------------------" << endl;
}

Menu::~Menu() = default;

#endif //AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_MENU_H