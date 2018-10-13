#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

string read_file() {
    ifstream source_file("source.txt");
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

int count(string s, string ss) {
    int n = 0, p = 0;

    while ( (p = s.find(ss, p)) != s.npos ) {
        ++n;
        ++p;
    }

    return n;
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