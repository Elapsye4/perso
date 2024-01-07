#include <stdio.h>
#include <stdlib.h>

int	ft_count(char *str, char c)
{
	int	i = 0;
	int	j = 0;

	while (str[i])
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

char	*ft_printable(char c, char *str)
{
	static int	i;
	int	j = 0;
	char	*tmp;

	tmp = (char *)malloc(ft_strlen(str) + 1);
	while (str[i] && str[i] != c)
	{
		tmp[j] = str[i];
		i++;
		j++;
	}
	i++;
	tmp[j] = '\0';
	return (tmp);
}

int	main(int argc, char **argv)
{
	int	count = 0;
	int	count2 = 0;
	char	*diary;
	char	*tmp;
	char	rall = '/';
	FILE	*data;

	count = ft_count(argv[1], rall);
	data = fopen("diary.txt", "a");
	if (!data)
	{
		perror("Le fichier marche pas trou du cul\n");
		return EXIT_FAILURE;
	}
	while (count != (count2 - 1))
	{
		tmp = ft_printable(rall, argv[1]);
		fprintf (data, "%s\n", tmp);
		free (tmp);
		count2++;
	}
	return EXIT_SUCCESS;
}	
