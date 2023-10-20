#ifndef MD1_QUICKSORT_H
#define MD1_QUICKSORT_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <chrono>

using namespace std;
using algorithm_time = chrono::time_point<chrono::high_resolution_clock>;

class QuickSort {
public:
    explicit QuickSort(const vector<string>&, int, const string&);
    ~QuickSort();
private:
    int size;
    string sort_type;
    vector<string> data;
    algorithm_time start_time;
    static void swap(string *, string *);
    static int partition(vector<string>, int, int);
    static void sort(const vector<string>&, int, int);
};

#endif //MD1_QUICKSORT_H
