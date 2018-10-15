#include <ctime>
#include <map>
#include <omp.h>
#include <chrono>

#include <fstream>
#include <iostream>
#include <vector>

#include "helpers.h"

using namespace std;

int main () {
    vector<string> text;
    vector<string> words;

    map<string, int> occurrences;

    string line, current_word;
    bool status = true;

    auto start = std::chrono::system_clock::now();

    ifstream source_file("source100000.txt"); //исходный файл
    //потоки параллельно читают файл

    while(status) {
        #pragma omp parallel shared(status, source_file, occurrences) private(line, words, current_word)
        {
            #pragma omp critical
            {
                status = getline(source_file, line);
                #pragma omp flush(status)
            }

            remove_punc(line);
            words = split(line, ' ');

            for(int i = 0; i < words.size(); i++) {
                current_word = words[i];
                to_lower(current_word);

                #pragma omp critical
                increase_word_count(occurrences, current_word);
                #pragma omp flush(occurrences)
            }
        }
    }

    map<string, int>::iterator it;

    for (it = occurrences.begin(); it != occurrences.end(); it++) {
        cout << it->first
             << " : "
             << it->second
             << endl;
    }

    cout << "DICTIONARY SIZE = " << occurrences.size();

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;
    cout << "\nPARALLEL V3 RUNTIME = " << diff.count() * 1000 << "ms" << endl;

    return 0;
}


