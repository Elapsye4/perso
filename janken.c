#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	main(void)
{
	int	choix;
	int	ia;
	srand(time(NULL) + clock());

	printf("1-Pierre 2-Feuille 3-Ciseau\n");
	scanf("%d", &choix);
	ia = rand() % 3 + 1;
	printf("L'ia a choisit %d\n", ia);

	if (ia == 1)
	{
		if (choix == 1)
			printf("Egalité\n");
		if (choix == 2)
			printf("Perdu\n");
		if (choix == 3)
			printf("Gagné\n");
	}
	if (ia == 2)
	{
                if (choix == 1)
                        printf("Gagné\n");
                if (choix == 2)
                        printf("Egalité\n");
                if (choix == 3)
                        printf("Perdu\n");
	}
	if (ia == 3)
	{
                if (choix == 1)
                        printf("Perdu\n");
                if (choix == 2)
                        printf("Gagné\n");
                if (choix == 3)
                        printf("Egalité\n");
        }
	return EXIT_SUCCESS;
}
