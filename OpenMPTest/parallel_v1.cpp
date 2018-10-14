#include <ctime>
#include <map>
#include <omp.h>
#include <chrono>

#include <fstream>
#include <iostream>
#include <vector>

#include "helpers.h"

using namespace std;

int main() {
    vector<string> words;
    map<string, int> occurrences; //map для подсчета числа вхождений для заданного слова

    string line, current_word;
    bool status;

    ifstream source_file("source100000.txt");

    auto start = std::chrono::system_clock::now();
    //потоки совместно читают файл, и каждый обрабатывает
    #pragma omp parallel shared(source_file, occurrences) private(line, status, current_word, words)
    {
        while(true) {
            #pragma omp critical
            status = getline(source_file, line);

            //не достигли конца файла
            if (status) {
                //разбиваем строку на слова
                remove_punc(line);
                words = split(line, ' ');

                for(int i = 0; i < words.size(); i++) {
                    current_word = words[i];
                    to_lower(current_word); //приводим слово к нижнему регистру

                    #pragma omp critical
                    increase_word_count(occurrences, current_word);
                }

            } else {
                break;
            }
        }

    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end-start;

    map<string, int>::iterator it;
    for (it = occurrences.begin(); it != occurrences.end(); it++) {
        cout << it->first
             << " : "
             << it->second
             << endl;
    }

    cout << occurrences.size() << endl;

    cout << "PARALLEL RUNTIME = " << diff.count() * 1000 << "ms" << endl;

    return 0;
}

