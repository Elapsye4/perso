#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	ft_strlen(char *str)
{
	int	i = 0;

	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *seed, char *line)
{
	int	i = 0;
	int	result = 1;

	if (!seed || !line)
		return 1;

	while (seed[i] && line[i] && seed[i] == line[i])
		i++;
	if (i == ft_strlen(seed))
		result = 0;
	return (result);
}

int	ft_parkour(char *seed)
{
	int	checker = 0;
	size_t	size = 0;
	char	*line;
	FILE	*data = fopen("data.txt", "r");

	while (getline(&line, &size, data) != -1)
	{
		int	i = ft_strlen(line) - 1;
		int	j = ft_strlen(seed);
		if (i < j || i > j)
			checker = 1;
		if (i == j)
		{
			checker = ft_strcmp(seed, line);
			if (checker == 0)
				break;
		}
	}
	fclose(data);
	free(line);
	return (checker);
}

int	main(int argc, char **argv)
{
	int	i = 1;
	size_t	size = 0;
	char	*line;
	FILE	*data = fopen("data.txt", "a+");

	if (data == NULL)
	{
		perror("Erreur lors de l'ouverture du fichier demandé.");
		return EXIT_FAILURE;
	}
	if (argc == 1)
	{
		printf("Il s'agirait de me donner quelque chose à traitez...\n");
		return EXIT_FAILURE;
	}
	if (getline(&line, &size, data) == -1)
	{
		fprintf(data, "%s\n", argv[1]);
		printf("la seed %d à bien été ajoutée\n", i);
		fflush(data);
		i++;
	}
	while (i < argc)
	{
		if (ft_parkour(argv[i]) == 0)
			printf("la seed %d est déjà existante\n", i);
		else
		{
			fprintf(data, "%s\n", argv[i]);
			printf("la seed %d à bien été ajoutée\n", i);
		}
		i++;
	}
	fclose(data);
	free(line);
	return EXIT_SUCCESS;
}
