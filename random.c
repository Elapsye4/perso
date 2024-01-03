#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(void)
{
	int	choix;

	srand(time(NULL) + clock());
	choix = rand() % 2 + 1;
	printf("%d\n", choix);
	return EXIT_SUCCESS;
}
