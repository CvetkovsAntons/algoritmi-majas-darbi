#include "LinkedList.h"

#include <utility>

LinkedList::LinkedList(int size) {
    this->size = size; // pieskiram izmeru
    head = nullptr;
    end = nullptr;
}

void LinkedList::push(string x, string y) {
    auto * new_coordinates = new Coordinates(std::move(x), std::move(y)); // veidojam kooridnates objektu
    if (head == nullptr) { // pievienojam pirmo vertibu rindaa
        head = new_coordinates;
    } else { // pievienojam jaunu vertibu rindaa
        Coordinates * tmp = head;
        while (tmp->next != nullptr) tmp = tmp->next;
        tmp->next = new_coordinates;
        new_coordinates->previous = tmp;
    }
    end = new_coordinates;
}

int LinkedList::length() { // funkcija atgriez rindas garumu
    Coordinates * tmp = head;
    int length = 0;
    while (tmp->next != nullptr) {
        length++;
        tmp = tmp->next;
    }
    return ++length; // peivenoju 1, jo pec WHILE cikla, length ir mazaks par size uz 1
}

void LinkedList::pop() {
    string output;

    if (head == nullptr) { // ja rindaa nav vertibu, tad izvadam pazinojumu, ka rinda ir tuksa
        output = "underflow";
    } else {
        output = "Removed coordinates: " + end->getCoordinates();

        Coordinates * previous = end->previous; // dabujam pedeja vertibas iepreksejo vertibu
        end = previous; // jauna pedeja vertiba

        if (end) end->next = nullptr; // ja pedeja vertiba nav null, tad nodzesam next jaunai pedeja vertibai
        else head = nullptr; // ja end ir null, tad mes iznemam pedejo vertibu no rinda, tas nozime ka ta ir tuksa, tapec head == null
    }
    cout << output << endl;
    system("pause");
}

void LinkedList::show() {
    string output;
    if (head == nullptr) {
        output = "The queue is empty";
    } else {
        Coordinates * tmp = head;

        while(tmp != nullptr) {
            output += tmp->getCoordinates() + "; ";
            tmp = tmp->next;
        }
    }

    cout << "----List of coordinates----" << endl;
    cout << output << endl;
    cout << "---------------------------" << endl;

    system("pause");
}

bool LinkedList::isFull() {
    return head != nullptr && length() == size;
}


LinkedList::~LinkedList() = default;
