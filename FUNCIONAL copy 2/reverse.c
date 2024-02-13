/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:49:12 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/10 19:32:36 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse(t_stack *stack_a)
{
    t_piece *temp1;
    t_piece *temp2;
    t_piece *ante;
    ante = stack_a->first;
    t_piece *laste;
    laste = stack_a->last;
    t_piece *oldfirst;
    if (laste->next == NULL && stack_a->len ==2)
        ante = stack_a->last;
    
    else
    {
        while(ante->next->next!=NULL)
            ante=ante->next;
    }
    oldfirst=stack_a->first;
    temp1 = stack_a->first;
    temp2 = stack_a->first->next;
    stack_a->first = stack_a->last;
    stack_a->first->next= oldfirst;
    stack_a->last = ante;
    stack_a->last->next=NULL;


}

void rra(t_stack *stack_a)
{
    reverse(stack_a);
    write(1,"rra\n",4 );
}

void rrb(t_stack *stack_b)
{
    reverse(stack_b);
    write(1 ,"rrb\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    write(3,"rrr\n",4);
}
