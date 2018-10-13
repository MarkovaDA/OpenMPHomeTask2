#include <ctime>
#include <list>
#include <chrono>

#include "helpers.h"

using namespace std;

int _main() {
    string file_content = read_file();

    srand(time(0));

    auto start = std::chrono::system_clock::now();

    vector<string> lines = split(file_content, '\n');

    vector<string> processed;
    vector<string> words;

    map<string, int> occurrences;

    string current_word;

    for(int i = 0; i < lines.size(); ++i) {
        remove_punc(lines[i]);
        words = split(lines[i], ' '); //all the words in line

        for(int j = 0; j < words.size(); j++) {
            current_word = words[j];

            to_lower(current_word);

            increase_word_count(occurrences, current_word);
        }
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;

    cout << "SEQUENCE RUNTIME = " << diff.count() * 1000 << "ms" << endl;


    map<string, int>::iterator it;

    for (it = occurrences.begin(); it != occurrences.end(); it++) {
        cout << it->first   //current_word
             << " : "
             << it->second
             << endl;
    }

    cout << "SIZE: " << occurrences.size();

    return 0;
}
