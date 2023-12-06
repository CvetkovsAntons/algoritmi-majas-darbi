#ifndef AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_NODE_H
#define AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_NODE_H

#include <iostream>
#include "vector"
#include "Tree.h"
#include "Constants.h"

using namespace std;

class Node {
public:
    Node(int, int, string, string);
    int getId() const;
    int getParent() const;
    string getName() const;
    string getType() const;
    vector<Node *> getChildren() const;
    bool hasChild() const;
    void addChild(Node *);
    void removeChild(int id);
    void static print(Node *, int = 0);
    void update(string);
    ~Node();
private:
    int id;
    int parent;
    string name;
    string type;
    vector<Node *> children; // si masiva glabas zara berni
};

Node::Node(int id, int parent, string name, string type) {
    this->id = id;
    this->parent = parent;
    this->name = name;
    this->type = type;
}

int Node::getId() const { return this->id; }

int Node::getParent() const { return this->parent; }

string Node::getName() const { return this->name; }

string Node::getType() const { return this->type; }

vector<Node *> Node::getChildren() const { return this->children; }

void Node::addChild(Node * child) { this->children.push_back(child); }

void Node::removeChild(int id) {
    // kad tiek atrasts child ar noradito id, tad iznemam to no masiva, kura glabajas visi zara berni
    for (int i = 0; i < this->children.size(); i++) {
        if (this->children[i]->getId() == id) {
            this->children.erase(this->children.begin() + i);
        }
    }
}
// funkcija parbauda, vai zaram ir berni
bool Node::hasChild() const { return !this->children.empty(); }
// funckija, kas izprinte zaru
void Node::print(Node * node, int tabs) {
    // pievinojam tabus
    for (int i = 0; i < tabs; i++) cout << " ";
    // parbaudam tipu
    string type = node->getType();
    if (type != "Disk") type = type == T_FILE ? "File" : "Folder";
    // izvadam zaru
    cout << type << " (" << node->getId() << ") - " << node->getName() << endl;
    // ja tam ir berni, tad atkatojam sis funkcijas izpildi
    if (node->hasChild()) {
        for (auto &child : node->getChildren()) Node::print(child, tabs + 3);
    }
}
// pievienojam jaunu nosaukumu zaram
void Node::update(string n) { this->name = n; }

Node::~Node() = default;


#endif //AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_NODE_H
