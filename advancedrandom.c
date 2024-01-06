#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	ft_rand(int nbr)
{
	int	i = 0;
	srand(time(NULL));
	i = rand() % nbr + 1;
	return (i);
}
	
int	main(int argc, char **argv)
{
	int	choix = 0;

	if (argc == 1)
	{
		printf("Donne moi des éléments\n");
		return EXIT_FAILURE;
	}
	while (argc > 2)
	{
		choix = ft_rand(argc - 1);
		if (choix)
		{
			printf("Le choix sera : %s\n", argv[choix]);
			break;
		}
	}
	if (argc == 2)
		printf("Le choix sera : %s\n", argv[1]);
	return EXIT_SUCCESS;
}
