

#include <stdio.h>
#include <stdarg.h>

int	average(int num, ...)	//	
{
	int		total;
	int		i;
	va_list	ap;	//	creation de la "structure" ap qui va reconnaitre les ...

	total = 0;
	i = 0;
	va_start(ap, num);	//	donne le nombre d'entree a mettre dans la struct, les valeurs seront assignees directement, a partir de la valeur suivant num

	while (i < num)
	{
		i++;
		total += va_arg(ap, int);	//	ajoute l'argument suivant de ap a chaque iteration, precise que c'est des int
	}
	va_end(ap);	//	free la "struct" quand on en a plus besoin
	return (total / num);
}

int	main(void)
{
	int moyenne = average(3, 10, 20, 30);

	printf("moyenne: %i", moyenne);

	return 0;
}
