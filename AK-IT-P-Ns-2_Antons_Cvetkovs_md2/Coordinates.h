#ifndef AK_IT_P_NS_2_ANTONS_CVETKOVS_MD2_COORDINATES_H
#define AK_IT_P_NS_2_ANTONS_CVETKOVS_MD2_COORDINATES_H

#include <iostream>
using namespace std;

class Coordinates {
public:
    Coordinates(string, string);
    string getCoordinates();
    ~Coordinates();

    Coordinates * next;
    Coordinates * previous;

private:
    string x;
    string y;
};


#endif //AK_IT_P_NS_2_ANTONS_CVETKOVS_MD2_COORDINATES_H
