#include <ctime>
#include <list>
#include <omp.h>

#include "helpers.h"

using namespace std;

int _main() {
    string file_content = read_file();

    srand(time(0));

    vector<string> lines = split(file_content, '\n'); //shared

    vector<string> processed; //shared
    vector<string> words; //private

    list<pair<string, int>> occurrences; //shared

    string current_word; //private
    int current_count; //private

    #pragma omp parallel shared(occurrences, file_content)
    {
        #pragma omp for schedule (dynamic, 2) private(current_word, words, current_count)
        for(int i = 0; i < lines.size(); ++i) {

            remove_punc(lines[i]);
            words = split(lines[i], ' ');

            for(int j = 0; j < words.size(); j++) {
                current_word = words[j];
                // printf("PROCESS: %d\n", omp_get_thread_num());
                to_lower(current_word);

                current_count = count(file_content, current_word); //кол-во вхождений слова

                #pragma omp critical
                occurrences.push_back(pair<string, int>(current_word, current_count));
            }
        }
    }

    cout << "PARALLEL FOR RUNTIME = " << clock() / 1000.0 << endl;

    list<pair<string, int>>::iterator it;

    for (it = occurrences.begin(); it != occurrences.end(); it++) {
        current_word = it->first;

        if (find(processed.begin(), processed.end(), current_word) != processed.end()) {
            continue;
        }

        processed.push_back(current_word);

        cout << current_word
                << " : "
                << it->second
                << endl;
    }

    cout << "SIZE: " << processed.size();

    return 0;
}

