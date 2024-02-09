#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	main(void)
{
	int	i = 0;
	int	j = 0;
	char	letter;
	char	ouioui;
	char	*str;
	char	*out;

	str = "hello world";
	out = malloc(sizeof(char) * ft_strlen(str));
	while (str[i])
	{
		ouioui = 'a';
		letter  = str[i];
		while (ouioui != letter && str[i] != ' ')
		{
			out[j] = ouioui;
			printf("%s\n", out);
			ouioui++;
			usleep(50000);
		}
		out[j] = str[i];
                printf("%s\n", out);
		usleep(50000);
		i++;
		j++;
	}
	free(out);
	return 0;
}
