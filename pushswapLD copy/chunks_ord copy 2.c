/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_ord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:46:50 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/20 10:53:35 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	divlent(int lent, int *chunk)
{
	int	particio;

	particio = 4;
	if (lent <= 100)
	{
		*chunk = lent / particio;
		return (particio);
		if (lent == particio)
			particio += 1;
		else if (lent % particio == 0)
		{
			*chunk = lent / particio;
			return (particio);
		}
		*chunk = lent / particio;
		return (particio);
	}
	
	else if (lent <= 500)
	{
		particio = 9;
		if (lent <= 500)
		{
			if (lent == particio)
				particio += 1;
			else if (lent % particio == 0)
			{
				*chunk = lent / particio;
				return (particio);
			}
		}
		*chunk = lent / particio;
		return (particio);
	}
	*chunk = lent / particio;
	return (particio);
}

void	chunks_ord(t_stack *stack_a, t_stack *stack_b, int lent)
{
	int	t_chunks;
	int	chunks;
	int	particio;
	int	smalle;
	int	bigge;
	int	small_c;
	int	num;

	t_chunks = 0;
	particio = divlent(lent, &t_chunks);
	num = 1;
	chunks = t_chunks;
	while (num <= particio)
	{
		while (chunks != 0)
		{
			if (stack_a->first->index < t_chunks * num)
			{
				pb(stack_a, stack_b);
				chunks -= 1;
			}
			else if (stack_a->first->index >= t_chunks * num)
				ra(stack_a);
		}
		chunks = t_chunks;
		num += 1;
	}
	lent = len(stack_a); 
	if (lent != 0)
	{
		smalle = smaller(stack_a);
		if (lent <= 5)
			small_sort(stack_a, stack_b, lent, smalle);
	}
	num = 1;
	chunks = t_chunks;
	if (stack_a!=NULL)
	{
		while (check_if_ordered(stack_a) == 1)
			small_sort(stack_a, stack_b, lent, smalle);
	}
	lent = len(stack_b);
	while (lent != 0)
	{
		bigge = bigger(stack_b);
		if ((small_c = cost(stack_b, bigge, 'f')) == 1)
		{
			while (stack_b->first->index != bigge)
				rb(stack_b);
		}
		else if ((small_c = cost(stack_b, bigge, 'f')) == 0)
		{
			while (stack_b->first->index != bigge)
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		lent = len(stack_b);
	}
}
