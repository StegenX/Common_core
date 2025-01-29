#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void handler(int sig)
{
	if (sig == SIGUSR1)
		printf("HeHe");
	else
		printf("Pehehehe");
}

int	ft_atoi(const char *nptr)
{
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr++ == '-')
			sign = -1;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		nb = nb * 10 + (*nptr - 48);
		nptr++;
	}
	return (nb * sign);
}

void send_null(int PID)
{
	int i = 0;
	while (i < 8)
	{
		kill(PID, SIGUSR1);
		i++;
		usleep(100);
	}
}

void send_Signal(int PID, char *message)
{
	int i, j;
	char c;
	i = 0;
	while (message[i])
	{
		c = message[i];
		j = 0;
		while (j < 8)
		{
			if ((c >> j) & 1)
				kill(PID, SIGUSR2);
			else
				kill(PID, SIGUSR1);
			usleep(500);
			j++;
		}
		i++;
	}
	send_null(PID);
}

int main (int ac, char **av)
{
	int pid;
	if (ac != 3)
	{
		write(2, "Error\n", 6);
		return 0;
	}
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
    pid = ft_atoi(av[1]);
	if (pid <= 0)
	{
		write(2, "Invalid PID\n", 12);
		return 0;
	}
	send_Signal(pid, av[2]);
}