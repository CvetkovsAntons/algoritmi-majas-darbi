#ifndef AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_HELPERS_H
#define AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_HELPERS_H

#include <iostream>
#include <filesystem>
#include "vector"

using namespace std;
// funckija, kas atgriez diska nosaukumu
string getDriveName() {
    return filesystem::current_path().root_path().string();
}
// funckija, kas no string veido masivu, tika panemta no interneta
// https://www.geeksforgeeks.org/cpp-string-to-vector-using-delimiter/
vector<string> split(const string& str, const string& delimiter) {
    vector<string> v;
    if (!str.empty()) {
        int start = 0;

        do {
            int idx = str.find(delimiter, start);
            if (idx == string::npos) break;
            int length = idx - start;
            v.push_back(str.substr(start, length));
            start += (length + delimiter.size());
        } while (true);

        v.push_back(str.substr(start));
    }
    return v;
}
// funkcija, kas parbauda vai strings ir cipars
bool isDigit(const string& input) {
    for (char c: input) {
        if (!isdigit(c)) return false;
    }
    return true;
}

#endif //AK_IT_P_NS_2_ANTONS_CVETKOVS_MD3_HELPERS_H
