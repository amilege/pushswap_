/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:04:10 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/20 11:58:34 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_num(char *argv)
{
	int	i;
	int	last;

	last = 0;
	i = 0;
	if (argv[i == '"'])
	{
		i++;
		last = ft_strlen(argv);
		if (last > 11)
			return 1;
		last -= 1;
	}
	if (argv[i] == '-' || argv[i] == '+')
		i++;
	while (argv[last - i] != 0)
	{
		if (!(argv[i] >= '0' && argv[i] <= '9') && !(argv[i] == 32))
			return (1);
		i++;
	}
	return (0);
}

int	ft_dup(int argc, char **argv)
{
	int	num1;
	int	num2;
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '"')
			i++;
		num1 = ft_atoi(argv[i]);
		j = i + 1;
		while (j < argc)
		{
			num2 = ft_atoi(argv[j]);
			if (num1 == num2)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	int		i;
	int		o;
	char	**args;

	o = 0;
	i = 1;
	if (argc < 2)
			return (1);
	while (i < argc)
	{
		if (argc == 2)
			return 1;
		//	args = ft_split(argv[1], ' ');
	//	else
			args = argv;
		if (ft_num(args[i]) == 1)
			return (1);
		i++;
	}
	if (ft_dup(argc, args) == 1)
		return (1);
	return (0);
}
