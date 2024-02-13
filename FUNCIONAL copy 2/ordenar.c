/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordenar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:02:27 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/11 19:13:07 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//copia
int bigger(t_stack *stackx)
{
    int i;
    int bigge;
    i = 0;
    t_piece *temp;
    temp = stackx->first;
    bigge = temp->index;
    while(temp != NULL)
    {
        if(bigge < temp->index)
            bigge = temp->index;
        i++;
        temp=temp->next;
    }
    return bigge;
}
int smaller(t_stack *stackx)
{
    int i;
    int smalle;
    i = 0;
    t_piece *temp;
    temp = stackx->first;
    smalle = temp->index;
    while(temp != NULL)
    {
        if(smalle > temp->index)
            smalle = temp->index;
        i++;
        temp=temp->next;
    }
    return smalle;
}

int len(t_stack *stackx)
{
    int i;
    i = 0;
    t_piece *temp;
    temp = stackx->first;
    while(temp != NULL)
    {
        i++;
        temp=temp->next;
    }
    return i;
}
int check_if_ordered(t_stack *stacka)
{
    t_piece *temp;
    t_piece *temp2;
    temp = stacka->first;

    while (temp != NULL)
    {
        temp2 = temp->next;
        while(temp2 !=NULL)
        {
          //  while(temp->index < temp2->index)
          //  {
                if(temp->index > temp2->index)
                    return 1;
                temp2 = temp2->next;
            //}
        }
        temp = temp->next;
    }
    return 0;
}


void ordtres(t_stack *stack_a, int lent)
{

    if (lent == 3)
    {
  /*    if (stack_a->first->index == lent-1)
        {
            ra(stack_a);
            if (check_if_ordered(stack_a)==1)
                sa(stack_a);
        }
        else if(stack_a->first->next->index == lent-1)
        {
            rra(stack_a);//es rra
            if (check_if_ordered(stack_a)==1)
                sa(stack_a);
        }
        else if (stack_a->last->index == lent-1)
        {
            if (check_if_ordered(stack_a)==1)
                sa(stack_a);
        }
        else*/
        {
            int bigge;
            bigge=bigger(stack_a);
            if (stack_a->first->index == bigge)
            {
                ra(stack_a);
                if (check_if_ordered(stack_a)==1)
                    sa(stack_a);
            }
            else if (stack_a->first->next->index == bigge)
            {
                rra(stack_a);//es rra
                if (check_if_ordered(stack_a)==1)
                    sa(stack_a);
            }
            else if (stack_a->last->index == bigge)
            {
                if (check_if_ordered(stack_a)==1)
                    sa(stack_a);
                
            }   


        }
    }

}

void small_sort(t_stack *stack_a,t_stack *stack_b,int lent,int smalle)
{
    if(lent == 3) //argc==4
        ordtres(stack_a,lent);
    if (lent >= 4 && lent <= 5) //argc==5 && argc==6
    {
        if (stack_a->first->index == smalle)
        {
//            printf("Antes del push\n");
  //          print_stacks(stack_a, stack_b);
            pb(stack_a, stack_b);//
 //           printf("Despues de enviar el primero del a al b\n");
   //         print_stacks(stack_a, stack_b);
            lent=len(stack_a);
            ordtres(stack_a, lent);//
     //       printf("Despues de ordenar el stack a con los 3\n");
       //     print_stacks(stack_a, stack_b);
            pa(stack_b ,stack_a);//
  //          printf("Depsues del volver el primero al a del b, el resultado:\n");
    //        print_stacks(stack_a, stack_b);
     //       printf("ignora%i",bigge);
        }
        else
            while(check_if_ordered(stack_a)==1)
            {
                chunks_ord(stack_a,stack_b,lent);
               // big_sort(stack_a,lent,smalle);
            }


   //     if (stack_b ->first->index == bigge || stack_b ->first->index >smalle)
     //       return ;//pc
    }
} 

void ordenar(t_stack *stack_a,t_stack *stack_b, int argc)
{
    int lent;
    int bigge;
    int smalle;
    lent = len(stack_a);
    bigge = bigger(stack_a);
    smalle = smaller(stack_a);
    if (lent == 2 && argc)//(argc==3)
        sa(stack_a);
    if (lent <=5)//(argc <= 6)
        small_sort(stack_a, stack_b,lent,smalle);
    else if(lent > 5)
        chunks_ord(stack_a, stack_b, lent);
}
/*int big_sort(t_stack *stackx,int smalle)
{
    t_piece *temp;
    int divl;
    int div;
    t_piece *temp;
    div=divlent(lent,&divl);
    printf("el num di es:%d y el result div es:%i",div, divl);
    while(divl>0)
    {
        if (stackx->first->index == smalle)
            return 0;

        while(stackx->first->index != smalle)
        {
            smalle=smaller(stackx);
            if (cost(stackx,smalle)==1)
                {
                    if (stackx->first->index == smalle)
                    {
                       // sa(stackx);
                        rra(stackx);
                        return 0;
                    }
                    else
                    {
                        if (stackx->first->next->index == smalle)
                        {
                            sa(stackx);

                        }
                        while(stackx->first->index != smalle)  // temp = stack_a->first;
                        {
                           // sa(stackx);
                            ra(stackx);
                        }
                    }
    
                }
            
                else
                {
                    temp = stackx->first;
                    if (stackx->last->index == smalle)
                    {
                        rra(stackx);
                        return 0;
                    }
                    else
                    {

                        while(stackx->last->index != smalle)
                        {
                            rra(stackx);

                        }

                    }
                }
        }
   // printf("En la div:%d de %d ", divl,div); 
    return 0;
}*/
/*
void ordenar(t_stack *stack_a,t_stack *stack_b, int argc)
{
  if (argc==3)
  {
    swap(stack_a);
  }
  if (argc == 4)
  {
    if (stack_a->first->index == 0)
    {
      pb(stack_a, stack_b);
      sa(stack_a);
      pa(stack_a, stack_b);
    }
    else
    {
      while (stack_a->first->index != 0)
      {
        pb(stack_a, stack_b);
        sa(stack_a);
        pa(stack_a, stack_b);

      }

    
    }
  }
  if (argc==5)
    swap(stack_b);
}
-------------------------------------------------------------------------------------


 * you have to hardcode the order in the case of :
 * 2
 * 3
 * 4
 * 5
 *
 * then use an algorithm to order in the case of :
 * 100
 * 500
 * */

/* void ordenar(t_stack *stack_a, t_stack *stack_b, int argc)
 * {
 *  if (argc == 3)
 *  {
 *     swap
 *  }
else if (argc == 4)
 {
	hardcode all movements in all 5 possible cases
 }
 else if(argc <= 6)
 {
	push the smallest ones to b, do the code for ordering the 3, push them back to a
 }
 else if(argc >= 6)
 {
	big_sort
 }
 * }


8 9 7 2 3 1 0
*/
