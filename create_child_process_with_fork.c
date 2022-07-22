#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

static int dataSegmentValue = 111;

int main(int argc, char *argv[]) {
    int stackSegmentValue = 222;

    pid_t childPid = fork();

    switch (childPid) {
        case -1:
            printf("fork failed\n");
        case 0:
            dataSegmentValue *= 3;
            stackSegmentValue *= 3;
            break;
        default:
            sleep(3);
            break;
    }

    printf(
        "PID=%ld %s dataSegmentValue=%d stackSegmentValue=%d\n",
        (long) getpid(),
        (childPid == 0) ? "(child)" : "(parent)",
        dataSegmentValue,
        stackSegmentValue
    );

    return 0;
}
