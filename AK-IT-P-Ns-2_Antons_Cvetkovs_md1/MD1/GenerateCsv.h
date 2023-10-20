#ifndef MD1_GENERATECSV_H
#define MD1_GENERATECSV_H

#include <iostream>
#include <fstream>
#include <random>

using namespace std;
// si klase genere CSV failu
// ta tika veidota, jo ne maku lietot excel
class GenerateCsv {
public:
    explicit GenerateCsv(int);
    ~GenerateCsv();
private:
    static void generate(int);
    static string randomString();
};


#endif //MD1_GENERATECSV_H
