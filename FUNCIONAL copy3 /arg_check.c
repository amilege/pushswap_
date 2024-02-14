/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:53:17 by amile-ge          #+#    #+#             */
/*   Updated: 2024/01/12 11:46:34 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "swap.h"

int arg_check(int argc, char **argv)
{
	int i;
	int a;
	a = argc;
	printf("entra");
	i = 0;
	printf("el argv es:: %s\n ", argv[1]);
	printf("el argv es:: %c\n ", argv[1][0]);
	printf("la i es::::: %i\n", i);
	while (argv[1][i])
 	{
		if ( i+1 > 13 || *argv[1] > 9876) //mira el max de xifres/caracters,aquest es una referencia
			return 1;
//		if (!(argv[1][i] >='0' && argv[1][i] <= '9'))
//
		if (!(argv[1][i] >='0' && argv[1][i] <= '9'))
	 	{
			printf("el aargv en el check es::::::: %c\n", argv[1][i]);
		 	printf("el bargv en el check es::::::::::::: %c\n", *argv[1]);
			return 1;
		}
		i += 1;

//	i	*argv[1]++;
		}
	printf("resultado %s\n", argv[1]);
	return 0;

}

