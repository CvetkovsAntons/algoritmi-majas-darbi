#include "QuickSort.h"

QuickSort::QuickSort(const vector<string>& data, int iterations, const string& sort_type)
{
    QuickSort::data = data;
    QuickSort::size = iterations;
    QuickSort::sort_type = sort_type; // nepiciesams izvadei algoritma beigas
    QuickSort::start_time = chrono::high_resolution_clock::now(); // saglabajam laiku, kad sakas algoritma izpilde
    QuickSort::sort(QuickSort::data, 0, QuickSort::size - 1);
}

void QuickSort::swap(string *a, string *b)
{
    string t = *a;
    *a = *b;
    *b = t;
}

int QuickSort::partition(vector<string> arr, int start, int end)
{
    string pivot = arr[end]; // pedeja masiva vartiba

    int i = (start - 1);
    for (int j = start; j <= end; j++) {
        if (arr[j] < pivot) { // ja start veriba ir mazaka par end veritbu, tad samainam tos vietam
            i++;
            QuickSort::swap(&arr[i], &arr[j]);
        }
    }

    QuickSort::swap(&arr[i + 1], &arr[end]);
    return (i + 1);
}
// rekursiva funkcija, kas tiek pildita, kamer partition nav pedeja vertiba
// ja partition ir pedeja masiva vertiba, tas nozime, ka masivs ir sorted
void QuickSort::sort(const vector<string>& arr, int start, int end)
{
    if (start < end) {
        int p = QuickSort::partition(arr, start, end); // dabujam partition
        QuickSort::sort(arr, start, p - 1);
        QuickSort::sort(arr, p + 1, end);
    }
}

QuickSort::~QuickSort() {
    auto duration = chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - QuickSort::start_time);
    cout << "Time taken by the algorithm with " << QuickSort::size << " " << QuickSort::sort_type << " values: " << duration.count() << " milliseconds" << endl;
}
