#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void handle_signal(int signum, siginfo_t *info, void *context) {
    static char c;
    static int bit_count;
    context = NULL;

    if (signum == SIGUSR1)
        c |= (0 << bit_count);
    else if (signum == SIGUSR2)
        c |= (1 << bit_count);
    bit_count++;
    if (bit_count == 8)
    {
        write(1, &c, 1);
        c = 0;
        bit_count = 0;
    }
    kill(info->si_pid, SIGUSR1);
}

int main() 
{
    struct sigaction sa;
    sa.sa_sigaction = handle_signal;
    sa.sa_flags = SA_SIGINFO;

    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    printf("Server PID: %d\n", getpid());
    while (1)
        pause();
    return 0;
}
