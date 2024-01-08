#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_replace(char *str, char *c, char *v)
{
	int	i = 0;
	FILE	*data;

	data = fopen("data.txt", "w");
	while (str[i])
	{
		if (str[i] == c[0])
			fprintf(data, "%s", v);
	       	else
			fprintf(data, "%c", str[i]);
		i++;
	}
	fclose(data);
	return 0;
}	

int	main(int argc, char **argv)
{
	int	i = 0;

	if (argc < 3 || argc > 4)
	{
		perror("Le nombre d'éléments n'est pas correct, assure toi d'avoir mis 1 - la phrase, 2 - le caractère à remplacer, 3 - Le nouveau charactere\n");
		return EXIT_FAILURE;
	}
	if (ft_strlen(argv[2]) > 1 || ft_strlen(argv[3]) > 1)
	{
		perror("Un charactere à la fois\n");
		return EXIT_FAILURE;
	}
	else
		ft_replace(argv[1], argv[2], argv[3]);
	return EXIT_SUCCESS;
}	
