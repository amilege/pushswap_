/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 10:39:31 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/14 11:48:59 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error_ind(t_stack *stackx)
{
	t_piece	*temp;

	temp = stackx->first;
	while (temp != NULL)
	{
		if (temp->index < temp->next->index)
			return (temp->index);
		temp = temp->next;
	}
	return (-1);
}
int	ord_stka(t_stack *stack_a)
{
	t_piece	*temp1;
	int		lent;

	temp1 = stack_a->first;
	lent = len(stack_a);
	while (lent != 0)
	{
		while (temp1->index + 1 == temp1->next->index)
			temp1 = temp1->next;
		lent -= 1;
	}
	return (0);
}

int	find_ind(t_stack *stack_a, t_stack *stack_b, int chunks)
{
	int		lent_a;
	int		smallerest;
	int		temp_small;
	int		lent_b;
	int		lent_at;
	t_piece	*temp_a;
	t_piece	*temp_b;

	smallerest = 0;
	temp_a = stack_a->first;
	temp_b = stack_b->first;
	lent_a = len(stack_a);
	lent_b = len(stack_b);
	lent_at = lent_a;
	while (temp_b != NULL)
	{
		while (temp_a != NULL)
		{
			if (temp_a->next == NULL)
				return (temp_b->index);
			if (temp_b->index + 1 == temp_a->next->index)
			{
				printf("econtrao");
				temp_small = smallerbig_cost(stack_a, temp_b->index, chunks);
				if (smallerest == 0)
					smallerest = temp_small;
				else if (smallerest > temp_small)
					smallerest = temp_small;
			}
			//  smaller_cost(stack_a, temp_b,
			temp_a = temp_a->next;
			//   lent_a -=1;
		}
		temp_b = temp_b->next;
		temp_a = stack_a->first;
		// lent_b-=1;
	}
	return (smallerest);
}

int	smallerbig_cost(t_stack *stackx, int num, int chunks)
{
	t_piece	*temp;
	int		smaller_c;
	int		temp_smaller;
	int		indext;

	temp = stackx->first;
	smaller_c = -1;
	while (temp != NULL)
	{
		if (temp->index && num)
		{
			temp_smaller = cost(stackx, temp->index, 'c');
			printf("temp_smaller es: %d", temp_smaller);
			if (smaller_c == -1)
			{
				smaller_c = temp_smaller;
				indext = temp->index;
			}
			else if (temp_smaller < smaller_c)
			{
				smaller_c = temp_smaller;
				indext = temp->index;
			}
		}
		temp = temp->next;
		chunks -= 1;
	}
	printf("El temp smaller es: %d", temp_smaller);
	printf("\n\n\n\n\n\nn\n\n\n\n\n\nEl smaller dins la funcio es: %d", indext);
	return (indext);
}

int	smaller_cost(t_stack *stackx, int num, int chunks)
{
	t_piece	*temp;
	int		smaller_c;
	int		temp_smaller;
	int		indext;

	temp = stackx->first;
	smaller_c = -1;
	while (temp != NULL)
	{
		if (temp->index <= chunks * num)
		{
			temp_smaller = cost(stackx, temp->index, 'c');
			if (smaller_c == -1)
			{
				smaller_c = temp_smaller;
				indext = temp->index;
			}
			else if (temp_smaller < smaller_c)
			{
				smaller_c = temp_smaller;
				indext = temp->index;
			}
		}
		temp = temp->next;
	}
	printf("\n\n\n\n\n\nn\n\n\n\n\n\nEl smaller dins la funcio es: %d", indext);
	return (indext);
}

int	cost(t_stack *stackx, int smalle, char type)
{
	t_piece	*tempf;
	t_piece	*templ;
	int		f;
	int		l;

	f = 0;
	l = 0;
	tempf = stackx->first;
	templ = stackx->last;
	while (tempf->index != smalle) // (tempf->next->index != smalle)
	{
		tempf = tempf->next;
		f++;
	}
	templ = tempf;
	while (templ->next != NULL)
	{
		templ = templ->next;
		l++;
	}
	if (type == 'c')
	{
		if (f < l)
			return (f);
		return (l);
	}
	else if (f < l)
		return (1); // 1 es que esta mas cerca de arriba,
			//es mas barato llevarlo al primer por arriba
	else
		return (0); // 0 es que esta mas cerca del final,
			//es mas barato llevarlo al primero por abajo
}
