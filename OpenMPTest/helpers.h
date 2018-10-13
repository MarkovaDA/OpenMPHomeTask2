#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

#ifndef OPENMPTEST_HELPERS_H
#define OPENMPTEST_HELPERS_H
    string read_file();

    vector<string> split(string str, char delimiter);

    int count(string s, string ss);

    void remove_punc(string &str);

    void to_lower(string &str);
#endif
