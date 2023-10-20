#include "GenerateCsv.h"

GenerateCsv::GenerateCsv(int number_of_values)
{
    GenerateCsv::generate(number_of_values);
}

void GenerateCsv::generate(int number_of_values)
{
    ofstream file ("../../values.csv");
    for (int i = 0; i < number_of_values; i++) file << GenerateCsv::randomString() << ",";
    file.close();
}

string GenerateCsv::randomString() {
    static const char charset[] =
            "abcdefghijklmnopqrstuvwxyz"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "0123456789"; // char no kuram bus veidots string

    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<int> lengthDistribution(10, 20);

    int length = lengthDistribution(rng); // izvelas string garumu no 10 lidz 20
    string randomString;
    randomString.reserve(length);

    for (int i = 0; i < length; ++i) {
        int index = rng() % (sizeof(charset) - 1);
        randomString += charset[index];
    }

    return randomString;
}

GenerateCsv::~GenerateCsv() = default;
