#include <ctime>
#include <list>

#include "helpers.h"

using namespace std;

int main() {
    string file_content = read_file();

    srand(time(0));

    vector<string> lines = split(file_content, '\n');

    vector<string> processed;
    vector<string> words;

    list<pair<string, int>> occurrences;

    string current_word;
    int current_count;

    for(int i = 0; i < lines.size(); ++i) {
        remove_punc(lines[i]);
        words = split(lines[i], ' '); //all the words in line

        for(int j = 0; j < words.size(); j++) {
            current_word = words[j];

            to_lower(current_word);

            if (find(processed.begin(), processed.end(), current_word) != processed.end()) {
                continue;
            }

            current_count = count(file_content, current_word);

            occurrences.push_back(pair<string, int>(current_word, current_count));

            processed.push_back(current_word);
        }
    }

    cout << "SEQUENCE RUNTIME = " << clock() / 1000.0 << endl;

    list<pair<string, int>>::iterator it;

    for (it = occurrences.begin(); it != occurrences.end(); it++) {
        std::cout << it->first  //key
                  << " : "
                  << it->second   //value
                  << std::endl;
    }

    cout << "SIZE: " << processed.size();

    return 0;
}
