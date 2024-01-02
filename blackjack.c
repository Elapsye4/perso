#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int     ft_rand(int carte)
{
	int	i = 0;
        srand(time(NULL) + clock());
        i = rand() % 10 + 1;
	carte = i;
	return (i);
}

int	ft_algo(int ia)
{
	int	i = 0;
	int	tmp = 0;
	int	choix = 0;
	srand(time(NULL));

	ia = rand() % 10 + 1;
	tmp = ia;
	printf("La première carte de l'ia est %d\n", ia);

	while (tmp < 21)
	{
		if (tmp <= 15)
		{
			ia = ft_rand(ia);
			tmp += ia;
		}
		if (tmp > 15 && tmp < 21)
		{
			choix = rand() % 4 + 1;
			if (choix == 1)
			{
				ia = ft_rand(ia);
				tmp = tmp + ia;
			}
			if (choix > 1)
				break;
		}
	}
	return (tmp);
}
				
int	main(void)
{
	int	choix = 0;
	int	tmp = 0;
	int	carte = 0;
	int	ia = 0;

	carte = ft_rand(carte);
	printf("Bienvenue dans une partie de BlackJack ! Voici votre première carte : %d\n", carte);
	tmp = carte;

	while (choix != 2)	
	{
		printf("1 - Piochez, 2 - Fin\n");
		scanf("%d", &choix);
		if (choix == 1)
		{
			carte = ft_rand(carte);
			tmp += carte;
			printf("La somme total de vos cartes est désormais de : %d\n", tmp);
			if (tmp == 21)
			{
				printf("BlackJack ! Vous avez gagné !\n");
				return EXIT_SUCCESS;
			}
			if (tmp > 21)
	                {
                        	printf("Malheureusement la somme de vos cartes dépasse 21 vous avez donc perdu !\n");
                	        return EXIT_SUCCESS;
        	        }
		}
	}
	ia = ft_algo(ia);
	if (ia > 21)
	{
		printf("L'ia à dépassé la somme de 21 elle a donc perdu.\n");
		return EXIT_SUCCESS;
	}
	else if (ia == 21)
	{
		printf("L'ia BlackJack, elle remporte cette manche !\n");
		return EXIT_SUCCESS;
	}
	else
	{
		if (ia > tmp)
			printf("La valeurs des cartes de l'ia est de %d et la votre de %d L'ia remporte donc cette manche !\n", ia, tmp);
		if (tmp > ia)
			printf("La valeurs des cartes de l'ia est de %d et la votre de %d vous remportez donc cette manche !\n", ia, tmp);
		if (tmp == ia)
			printf("La valeurs des cartes de l'ia est de %d et la votre de %d Il y a donc une égalité sur cette manche !\n", ia, tmp);
	}
	return EXIT_SUCCESS;
}



