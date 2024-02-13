/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 12:36:01 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/08 17:40:27 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"
 
void swap(t_stack *stackx)

{
    t_piece *temp;
    t_piece *temp2;
    t_piece *temp3;
    temp = stackx->first;
    temp2 = stackx->first->next;
    temp3 = stackx->first->next->next;
    stackx->first = stackx->first->next;
    stackx->first->next = temp;
    stackx->first->next->next = temp3;
}

void sa(t_stack *stacka)
{
    swap(stacka);
    write(1,"sa\n",3);
}

void sb(t_stack *stackb)
{
    swap(stackb);
    write(1,"sb\n",3);
}

void ss(t_stack *stacka, t_stack *stackb)
{
    sa(stacka);
    sb(stackb);
    write(1,"ss\n",3);
}
/*

sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si
hay uno o menos elementos.
sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si
hay uno o menos elementos.
ss swap a y swap b a la vez.
pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack
a. No hace nada si b está vacío.
pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack
b. No hace nada si a está vacío.
ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición,
de forma que el primer elemento se convierte en el último.
rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición,
de forma que el primer elemento se convierte en el último.
rr ra y rb al mismo tiempo.
rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una
posición, de forma que el último elemento se convierte en el primero.
rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una
posición, de forma que el último elemento se convierte en el primero.
rrr rra y rrb al mismo tiempo.
*/
