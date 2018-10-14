#include <ctime>
#include <map>
#include <omp.h>
#include <chrono>

#include <fstream>
#include <iostream>
#include <vector>

//#include "helpers.h"

using namespace std;

//этот вариант предполагает сначала чтение файла, а потом совместную работу потоков над строками
int main() {

    vector<string> text;
    string line;

    #pragma omp parallel sections shared(text) private(line)
    {
        #pragma omp section
        {
            ifstream source_file("source200.txt");

            while (getline(source_file, line))
            {
                #pragma omp critical
                {
                    text.push_back(line);
                };

            }
            printf("THREAD %d\n - %d\n", omp_get_thread_num(), text.size());
        }
    }

    #pragma omp parallel shared(text)
    {
        //printf("thread %d\n", omp_get_thread_num());

        while(!text.empty())
        {
            #pragma omp critical
            {
                line = text.back();
                cout << line << endl;
                text.pop_back();
            }
        }

    }
    return 0;
}

