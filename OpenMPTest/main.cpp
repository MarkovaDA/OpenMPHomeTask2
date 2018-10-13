#include <iostream>
#include <stdio.h>
#include <omp.h>

int _main()
{
    int id;
    #pragma omp parallel private(id) num_threads(10)
    {
        id = omp_get_thread_num();
        printf("%d: Hello World!\n", id);
    }
    return 0;
}