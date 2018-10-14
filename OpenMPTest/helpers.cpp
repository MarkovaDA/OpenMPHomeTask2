#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <string>
#include <algorithm>
#include "omp.h"

using namespace std;

string read_file() {
    ifstream source_file("source100000.txt");
    string content((istreambuf_iterator<char>(source_file)), std::istreambuf_iterator<char>());
    return content;
}

vector<string> split(string str, char delimiter) {
    vector<string> internal;
    stringstream ss(str); // Turn the string into a stream.
    string tok;

    while(getline(ss, tok, delimiter)) {
        internal.push_back(tok);
    }

    return internal;
}

void remove_punc(string &str) {
    char signs[8] = {'.', ',', '!', '?', ':', ';', '\"', '\''};

    for(int i=0; i < sizeof(signs) / sizeof(char); i++) {
        str.erase(remove(str.begin(), str.end(), signs[i]), str.end());
    }
}

void to_lower(string &str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
}

void increase_word_count(map<string, int> &occurrences, string word) {
    map<string, int>::const_iterator found = occurrences.find(word);

    if (found == occurrences.end()) {
        occurrences.insert(pair<string, int>(word, 1));
    } else {
        occurrences[word] += 1;
    }
}