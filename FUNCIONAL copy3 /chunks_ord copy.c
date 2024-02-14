/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks_ord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:46:50 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/14 11:05:55 by amile-ge         ###   ########.fr       */
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
    int smalle_ind;
  //  int small_c;
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
     //   while(num != -1)while(num <= t_particio)
        while(num <= t_particio) 
        {
            while(chunks !=0)
            {
                
                if(stack_a->first ==NULL)
                {
                    pa(stack_a, stack_b);
                    chunks -=1;
                    print_stacks(stack_a,stack_b);

                }
                if (stack_b->first == NULL)
                {
                    t_chunks = 0;
                    chunks = 0;
                    num = t_particio + 5;
              //     last_ord(stack_a);
                }
                else if (stack_b->first->index >= t_chunks*num)

            //    if (stack_b->first->index >= t_chunks*num)
                {
                    if((smalle_ind=find_ind(stack_a, stack_b,chunks)!=-1))
                    {
                  //      if (cost(stack_a)==1)
                    //        ra(stack_a);
//
  //                      while(stack_b->first!= smalle_ind)

                        printf("El Smalle index: %d", smalle_ind);
                        pa(stack_a, stack_b);
                        chunks-=1;
                        if (((len(stack_a) > 2 )&& (check_if_ordered(stack_a)== 1)))
                        {
                            if(stack_a->first->index > stack_a->first->next->index && 
                            stack_a->first->index < stack_a->first->next->next->index)
                                sa(stack_a);
                        }
                    }
                     print_stacks(stack_a,stack_b);

                }
                else if (stack_a->first->index >t_chunks*num)
                    ra(stack_a);
               // while(check_if_ordered(stack_a)==1)
               // {
                // }
                lent = len(stack_a);
              print_stacks(stack_a,stack_b);
                  if (check_if_ordered(stack_a)==1)
                  {

                      if (lent==3)
                          ordtres(stack_a,lent);
                      else
                          printf("falta");
                  }
             
            }
            chunks = t_chunks;
            num-=1;
            printf("finish");
            print_stacks(stack_a,stack_b);
        }
        if (check_if_ordered(stack_a)==1)

            
        printf("ordenao");
        return ;



}    
        
  //  }

            /*
                
                



                //small_c = smaller_cost(stack_a,num, chunks);
               //  if (cost(stack_a,small_c,'f')==1)

                while(stack_a->first->index != small_c)
                {
                    //smalle=smaller(stack_a);
                    if (cost(stack_a,small_c,'f')==1)
                    {  
                        while(stack_a->first->index != small_c)  // temp = stack_a->first;
                        {
                           // sa(stackx);
                            ra(stack_a);
                        }

                        if (stack_a->first->next->index == small_c)
                            sa(stack_a);
                    }

                    else
                    {
                        while(stack_a->last->index != small_c)
                            rra(stack_a);   
                  //      temp = stack_a->first;
                        if (stack_a->last->index == small_c)
                            rra(stack_a);
                    }
                }

                if (stack_a->first->index == small_c)
                {
                    pb(stack_a,stack_b);
                    print_stacks(stack_a,stack_b);
                }
                chunks-=1;
            }
            num+=1;
           // particio -=1;
            chunks = t_chunks;
            if ((lent=len(stack_a)!= 0))
            {
                smalle =smaller(stack_a);
                if (lent <=5)
                    small_sort(stack_a, stack_b, lent, smalle);
            }
        
        }
        printf("2a parte");
        //while (num!=t_particio)
            
    }






}

*/

           /* lent=len(stack_a); 
            while(lent>3 )//while(divl>0)
            {
                
                stack_a->len = lent;
                smalle=smaller(stack_a);
                //if (stack_a->first->index == smalle)
               // {
                  //  pb(stack_a,stack_b);
                  //  
                    //divl-=1;
//                }

                while(stack_a->first->index != smalle)
                {
                    smalle=smaller(stack_a);
                    if (cost(stack_a,smalle)==1)
                    {                    
                        if (stack_a->first->next->index == smalle)
                        {
                            sa(stack_a);

                        }
                        while(stack_a->first->index != smalle)  // temp = stack_a->first;
                        {
                           // sa(stackx);
                            ra(stack_a);
                        }
                    }

                    else
                    {
                        temp = stack_a->first;
                        if (stack_a->last->index == smalle)
                        {
                            rra(stack_a);
                        }
                        else
                        {
                            while(stack_a->last->index != smalle)
                            {      
                                rra(stack_a);

                            }   

                        }
                    }
                :wq

                }

                if (stack_a->first->index == smalle)
                {
                    pb(stack_a,stack_b);
                    lent=len(stack_a);
                    //divl-=1;
                }
     //           printf("baja\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
            //    pb(stack_a,stack_b);
         //     print_stacks(stack_a,stack_b);
            }
       //     printf("HA SALIOOOO\n\n\\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\\n\n\n");

            // if(stack_a->first->index==smalle)
           // print_stacks(stack_a, stack_b);
            while(check_if_ordered(stack_a)==1)
            {
             //   printf("2o sort:");
                big_sort(stack_a,smalle);
                print_stacks(stack_a, stack_b);
                pb(stack_a,stack_b);
                printf("2op push to b");
                print_stacks(stack_a, stack_b);


            }
            if (check_if_ordered(stack_a)==1)
                ordtres(stack_a, lent);
      //      while(stack_b->first !=NULL && stack_b->last !=NULL)
            
            while(stack_b->first !=NULL)
            {
                pa(stack_a,stack_b);

            }
         //   printf("\n~~Vuelta~~\n");
    // }
        div -=1;

    }
    return ;

}*/
/*
int divlent(int lent,int *divl)
{
    int div;
    if(lent<= 500)// (lent!=0) //(lent<= 500)
    {
        div = 10;
        while(div!=1)
        {
            if (lent == div)
                div -=1;
            else if(lent%div==0)
            {
                if(lent==div)
                *divl=lent/div;
                return div;
            }
            div-=1;
        }
    
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
            

    return 1;
}
void chunks_ord(t_stack *stack_a,t_stack *stack_b,int lent,int smalle)
{

    int divl;
    int div;
  //  t_piece *temp;
    div=divlent(lent,&divl);
    printf("el num di es:%d y el result div es:%i",div, divl);

    while(check_if_ordered(stack_a)==1)
    {
        while(div >0)
        {
            while(divl>0)
            {
                if (big_sort(stack_a,smalle)==0)
                {
                    pb(stack_a,stack_b);
                    divl-=1;
                }       

            }   

            // if(stack_a->first->index==smalle)
            pb(stack_a,stack_b);
            print_stacks(stack_a, stack_b);
            while(check_if_ordered(stack_a)==1)
            {
                printf("2o sort:");
                big_sort(stack_a,smalle);
                print_stacks(stack_a, stack_b);
                pb(stack_a,stack_b);
                printf("2op push to b");
                print_stacks(stack_a, stack_b);
                

            }

            while(stack_b->first !=NULL)
            {
                pa(stack_a,stack_b);

            }
            printf("\n~~Vuelta~~\n");
        }
        div -=1;


    }
        

    return ;
    
}

*/
