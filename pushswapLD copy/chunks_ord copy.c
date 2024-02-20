/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_ord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:46:50 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/15 10:36:54 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */            
#include "push_swap.h"
#include "push_swap.h"
//copia

int divlent(int lent,int *chunk)
{
    int particio;
    if(lent<= 500)// (lent!=0) //(lent<= 500)
    {
        particio = 2;
        while(particio!=lent)
        {
            if (lent == particio)
                particio +=1;
            else if(lent%particio==0)
            {
                //if(lent==particio)
                *chunk=lent/particio;
                return particio;
            }
            particio+=1;
        }
        particio =2;
        *chunk=lent/2;
        return particio;
        /*
        if(lent%7==0)
            *divl=lent/7;
        if (lent%6==0)
            *divl=lent/6;
        if (lent%5==0)
            *divl=lent/5;
        else if(lent%4==0)
            *divl=lent/4;
        else if(lent%3==0)
            *divl=lent/3;
        else if(lent%2==0)
            *divl=lent/2;
            */
    }
    return 1;
}
void chunks_ord(t_stack *stack_a,t_stack *stack_b,int lent)
{
    int t_chunks;
    t_chunks = 0;
    int t_particio;
    int chunks;
    int particio;
    int smalle;
    int bigge;
  //  int smalle_ind;
    int small_c;
    //int smalle;
//    t_piece *temp;
    t_particio=divlent(lent,&t_chunks);
   // printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\nn\el num di es:%d y el result div es:%i",div, divl);
    int num;
    num=1;
    chunks = t_chunks;
    particio= t_particio;
  //  while(check_if_ordered(stack_a)==1)
    //{
        while(num <= particio)
        {
            while(chunks !=0)
            {
                if (stack_a->first->index < t_chunks*num)
                {
                    pb(stack_a, stack_b);
                    chunks-=1;
                }
                else if (stack_a->first->index >=t_chunks*num)
                    ra(stack_a);
         //   print_stacks(stack_a,stack_b);
             
            }
            chunks = t_chunks;
            num+=1;
           // printf("finish");
      //     print_stacks(stack_a,stack_b);
        }
        if ((lent=len(stack_a)!= 0))
            {
                smalle =smaller(stack_a);
                if (lent <=5)
                    small_sort(stack_a, stack_b, lent, smalle);
            }
        num=1;
        chunks=t_chunks;
    //    print_stacks(stack_a, stack_b);
        //   while(num != -1)while(num <= t_particio) 
        lent = len(stack_b);
        while(lent!=0)
        {
            bigge = bigger(stack_b);
            if ((small_c = cost(stack_b, bigge, 'f'))== 1)
            {
              while(stack_b->first->index != bigge)
                ra(stack_b);
            }
            else if ((small_c =cost(stack_b,bigge,'f' ))==0)
            {
              while(stack_b->first->index != bigge)
                rra(stack_b);
            }
            pa(stack_a,stack_b);
  //          print_stacks(stack_a, stack_b);
            lent=len(stack_b);
        }
//        print_stacks(stack_a,stack_b);
}


