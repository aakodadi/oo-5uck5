#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void niceDelegate(const char* task)
{
    printf("Please %s\n", task);
}

void harshDelegate(const char* task)
{
    printf("%s or else...!\n", task);
}

void
startManager(void (*delegate)(const char*), const char** tasks, int tasksCount)
{
    int i;
    for (i = 0; i < tasksCount / 2; i++) {
        printf("%s\n", tasks[i]);
    }
    for (; i < tasksCount; i++) {
        delegate(tasks[i]);
    }
}


int
main(int argc, char** argv)
{
    const char* tasks[] = {
        "do the presentation",
        "write the report",
        "fill the timesheet",
        "fix the bug"
    };

    void (*delegateFuncs[])(const char*) = {niceDelegate, harshDelegate};

    srand((unsigned)time(0));

    startManager(delegateFuncs[rand() % 2], tasks, 4);
    return 0;
}