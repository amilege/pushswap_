/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initstack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 16:45:35 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/09 18:11:05 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_initstack(t_stack *stack)

{
  stack->first = NULL;
  stack->last = NULL;
  stack->len = 0;
}

void  fill_index(t_stack *stack)
{
    t_piece *temp;
    t_piece *temp2;
    int     count;

    temp = stack->first;
  while (temp != NULL)
  {
    count = 0;
    temp2 = stack->first;
    while (temp2 != NULL)
    {
      if (temp2->value < temp->value)
        count++;
      temp2 = temp2->next;
    }
    temp->index = count;
    temp = temp->next;
  }
}

void  new_piece(t_stack *stack, int nb)
{
  t_piece  *new_element;

  new_element = (t_piece *)malloc(sizeof(t_piece));
  new_element->value = nb;
  new_element->index = 0;
  new_element->next = NULL;
  if (stack->first == NULL && stack->len == 0)
    {
      stack->first = new_element;
      stack->last = new_element;
    }
  else
  {
    stack->last->next = new_element;
    stack->last = new_element;
  }
   stack->len += 1;
}

void fill_stack_a(t_stack *stack, int argc, char **argv)
{
  int      i;
  char    **args;

  i = 1;
 // while (i < argc)
 //{
   
    if (argc == 2)
    {
      i = 0;
      args = ft_split(argv[1], ' ');
    }
    else
    {
      args = argv;
    }
    
    while(args[i])
    {

      new_piece(stack, ft_atoi(args[i]));
      i++;
    }

  //}
}

// int main(int argc, char **argv)
// {
//   t_stack stack;
//   t_stack *Lista;
//   t_stack *ptr;
//   int i;
//   i = 1;

//  // stack = malloc(sizeof(t_stack));
//   ft_initstack(&stack);
// //  printf("%p", Lista);
//   while (i < argc)
//   {
//     fill_stack(&stack, argv[i]);
//    // printf("we");
//     i++;
//   }
//   i = 0;
//   ptr = stack.first;
//   while(ptr != NULL)
//   {
//     printf("%s\n", ptr->value);
//     ptr = ptr->next;
//   }


// }



/*
{
    int i;
    int num;

    i = 0;
    char **param;
     while (i < argc)
    {
        **param = ft_atoi(argv[1]);
         i++;


     }
    printf("%s",*param);

}
*/
