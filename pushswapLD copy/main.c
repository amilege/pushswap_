/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 11:58:49 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/20 11:53:20 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void  print_stacks(t_stack *stack_a, t_stack *stack_b)
{
   int i;
   t_piece *ptr;

   printf("\n🦋STACK A\n");
   printf("_____________\n");
   i = 0;
   ptr = stack_a->first;
   while (i <= stack_a->len && ptr != NULL)
   
//   while (i <= 3 && ptr != NULL)
   {
      printf("🐯Piece nr %d:\n", i);
      printf("VALUE: %d\n", ptr->value);
      printf("INDEX: %d\n", ptr->index);
      printf("_____________\n");
      ptr = ptr->next;
      i++;
   }
/*
   while (i < stack_a->len && ptr != NULL)
   {
      printf("VALUE: %d\n", ptr->value);
      printf("_____________\n");
      ptr = ptr->next;
      i++;
   }
   
   while (i < stack_a->len && ptr != NULL)
   {
      printf("🐯Piece nr %d:\n", i);
      printf("VALUE: %d\n", ptr->value);
      printf("INDEX: %d\n", ptr->index);
      printf("_____________\n");
      ptr = ptr->next;
      i++;
   }
   */
  printf("\n🐻STACK B\n");
   printf("_____________\n");
   i = 0;
   ptr = stack_b->first;
   while (i < stack_b->len && ptr != NULL)
   {
      printf("🌹Piece nr %d:\n", i);
      printf("VALUE: %d\n", ptr->value);
      printf("INDEX: %d\n", ptr->index);
      printf("_____________\n");
      ptr = ptr->next; 
      i++;
   }
   
}


int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	// int i = 0;
//	if (argc)
//	{
		if (ft_check_args(argc, argv) == 1)
			return (write(2, "Error\n", 6));
		ft_initstack(&stack_a);
		ft_initstack(&stack_b);
		fill_stack_a(&stack_a, argc, argv);
		fill_index(&stack_a);
		if (check_if_ordered(&stack_a) == 0)
		{
			// printf("Ordenao");
			//   print_stacks(&stack_a, &stack_b);
			free_stacks(&stack_a, &stack_b);
			return (0);
		}
		ordenar(&stack_a, &stack_b, argc);
  // 	print_stacks(&stack_a, &stack_b);
		//  if (check_if_ordered(&stack_a) ==1)
		//   printf("NOOO ORDENAO");
		free_stacks(&stack_a, &stack_b);
		return (0);
//	}
//	return (0);
}
