#ifndef AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_TREE_H
#define AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_TREE_H

#include <iostream>
#include "Helpers.h"
#include "Node.h"
#include "vector"
#include "Constants.h"

using namespace std;

class Tree {
public:
    Tree();
    void newNode(vector<string>);
    void deleteNode(int);
    void print(int);
    void addChild(Node *, int);
    Node * search(int, Node *);
    Node * getRoot() const;
    ~Tree() = default;
private:
    Node * root = nullptr;
};

Tree::Tree() {
    // kad koks tiek izveidots, tad ari veidojas root, ar tipu Disk un diska, kura ir saglabats projekts, nosaukumu
    this->root = new Node(0, 0, getDriveName(), T_DISK);
}

void Tree::newNode(vector<string> data) {
    Node * node = this->search(stoi(data[0]), this->root);
    if (node) { // ja zars, ar noradito id eskiste, tad mainam tam nosaukumu
        node->update(data[2]);
    } else { // ja ne, tad veidojam jaunu zaru
        node = new Node(stoi(data[0]), stoi(data[1]), data[2], data[3]);
        if (this->root == nullptr) this->root = node; // ja nav noradits root, tad jauns zars bus root
        else this->addChild(node, stoi(data[1])); // pievienojam bernus parent zaraa
    }
}

void Tree::deleteNode(int id) {
    Node * node = this->search(id, this->root); // meklejam zaru
    if (node->getType() == T_DISK) { // nevar nodzest disku
        cout << ERR_DELETE_DISK << endl;
        system("pause");
        return;
    }
    if (node->getType() == T_DIRECTORY) { // ja tas ir katalogs
        // meklejam visus ta bernus
        for (auto & child : node->getChildren()) {
            // ja bernam ir berni, tad atkartoti izaucam so funkciju
            if (child->hasChild()) {
                this->deleteNode(child->getId());
            } else {
                // ja bernu nav, tad
                // izdesam so bernu parentam
                node->removeChild(child->getId());
                // izdesam objektu
                delete child;
            }
        }
    }
    // atrodam si zara parentu, un nonemam so zaru no tad bernu masiva
    this->search(node->getParent(), this->root)->removeChild(id);
    delete node; // izdesam objektu
}
// funkcija, kas izprinte koku
void Tree::print(int id = -1) {
    // ja id ir -1, tad izvadam vis zaru, sakot no root, ja id ir > -1, tad izvadam sakot no noradita id
    Node::print(id == -1 ? this->root : this->search(id, this->root));
    system("pause");
}
// funkcija, kas peiveno bernu masivaa parent zaraa
void Tree::addChild(Node * child, int parent) {
    if (child->getId() == parent) return;
    this->search(parent, this->root)->addChild(child);
}
// funkcija, kas mekle zaru pec id
Node * Tree::search(int id, Node * node) {
    if (node == nullptr) { // ja node ir null, tad atgriezam null
        return nullptr;
    } else if (node->getId() == id) { // ja ir atrasts node ar noradito id, tad atriezam to
        return node;
    } else if (node->hasChild()) { // ja zaram ir berni, tad ejam caur visam ta berniem, kamer neatradisim nepieciesamo
        for (auto &child : node->getChildren()) {
            Node * result = Tree::search(id, child);
            if (result != nullptr) return result; // ja zars ar noradito id ir atrasts, tad izvadam to
        }
    }
    return nullptr; // ja zars nav atrasts un tam nav bernu, tad atgriezam null
}

Node *Tree::getRoot() const { return this->root; }

#endif //AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_TREE_H
