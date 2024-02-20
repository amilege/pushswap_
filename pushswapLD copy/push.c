/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:26:17 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/10 20:21:16 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **stackfrom, t_stack **stackto)
{
	t_piece	*temp;

	temp = (*stackfrom)->first;
	if (temp != NULL && (*stackfrom)->first != (*stackfrom)->last)
	{
		(*stackfrom)->first = temp->next;
		temp->next = (*stackto)->first;
		(*stackto)->first = temp;
	}
	else if ((*stackfrom)->last != NULL)
	{
		(*stackfrom)->first = temp->next;
		temp->next = (*stackto)->first;
		(*stackto)->first = temp;
	}
}

void	pa(t_stack *stacka, t_stack *stackb)
{
	int	a;

	push(&stackb, &stacka);
	a = len(stackb);
	stackb->len = a;
	write(1, "pa\n", 3);
}

void	pb(t_stack *stacka, t_stack *stackb)
{
	int	a;

	push(&stacka, &stackb);
	a = len(stackb);
	stackb->len = a;
	write(1, "pb\n", 3);
}
