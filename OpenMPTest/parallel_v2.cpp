#include <ctime>
#include <map>
#include <omp.h>
#include <chrono>

#include <fstream>
#include <iostream>
#include <vector>

#include "helpers.h"

using namespace std;

/*
 * Время запуска для данных различных размерностей
 * ~100 - 18мс
 * ~1000 - 70mc
 * ~10 000 - 590mc
 * ~100 000 - 2.5c
 * */
//секционное распараллеливание
int main() {
    vector<string> text;
    vector<string> words;

    map<string, int> occurrences;

    string line, current_word;

    auto start = std::chrono::system_clock::now();

    #pragma omp parallel sections shared(text) private(line)
    {
        #pragma omp section
        {
            ifstream source_file("source100000.txt");

            while (getline(source_file, line))
            {
                #pragma omp critical
                {
                    text.push_back(line);
                    #pragma omp flush(text)
                };
            }
        }
    }

    #pragma omp parallel shared(text, occurrences) private(line, words, current_word)
    {
        //printf("thread %d\n", omp_get_thread_num());

        while(!text.empty())
        {
            #pragma omp critical
            {
                line = text.back();
                //cout << line << endl;
                text.pop_back();
                #pragma omp flush(text)
            }

            remove_punc(line);
            words = split(line, ' ');

            for(int i = 0; i < words.size(); i++) {
                current_word = words[i];
                to_lower(current_word); //приводим слово к нижнему регистру

                #pragma omp critical
                increase_word_count(occurrences, current_word);
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

    cout << "PARALLEL V1 RUNTIME = " << diff.count() * 1000 << "ms" << endl;
    return 0;
}


