#include "minitalk.h"

int	received;

void	confirm (int signal)
{
	if (signal == SIGUSR1)
		received = 1;
}

void	send_bits(int pid, char c)
{
	int	bit;
	int result;

	bit = 7;
	result = 0;
	while (bit >= 0)
	{
		received = 0;
		if ((c >> bit & 1) == 1)
			result = kill(pid, SIGUSR1);
		else
			result = kill(pid, SIGUSR2);
		if (result == -1)
			break ;
		if (!received)
			pause();
		bit--;
	}
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid < 0)
			ft_printf("Wrong PID.");
		signal(SIGUSR1, confirm);
		while (av[2][i] != '\0')
		{
			send_bits(pid, av[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("Wrong argument number.");
		return (0);
	}
}