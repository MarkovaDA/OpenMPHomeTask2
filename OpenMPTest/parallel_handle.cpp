#include <ctime>
#include <map>
#include <omp.h>
#include <chrono>

#include "helpers.h"

using namespace std;

int main() {
    string file_content = read_file();

    auto start = std::chrono::system_clock::now();

    vector<string> lines = split(file_content, '\n'); //shared
    vector<string> processed; //shared
    vector<string> words; //private

    map<string, int> occurrences; //shared

    string current_word; //private

    #pragma omp parallel private(words, current_word) shared(lines)
    {
        int num_threads = omp_get_num_threads();

        int i = omp_get_thread_num();

        int portion_size = lines.size() / num_threads;

        int left_boundary = i * portion_size;

        /*int right_boundary = (i == num_threads - 1) ? (i+1) * portion_size :
                left_boundary + lines.size() - i * portion_size;*/
        int right_boundary = (i + 1) * portion_size;

        // printf("(%d - %d)\n", left_boundary, right_boundary);

        for (int j = left_boundary; j < right_boundary; j++) {
            remove_punc(lines[j]);
            words = split(lines[j], ' ');

            for(int k = 0; k < words.size(); k++) {
                current_word = words[k];
                to_lower(current_word);
                increase_word_count(occurrences, current_word);
            }
        }
    }

    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> diff = end - start;

    cout << "PARALLEL_HANDLE RUNTIME = " << diff.count() * 1000 << "ms" << endl;

    /*map<string, int>::iterator it;

    for (it = occurrences.begin(); it != occurrences.end(); it++) {

        cout << it->first
             << " : "
             << it->second
             << endl;
    }*/

    return 0;
}



