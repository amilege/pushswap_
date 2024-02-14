/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:13:30 by amile-ge          #+#    #+#             */
/*   Updated: 2024/01/30 18:50:01 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
int ft_atoi(char *a)
{
    int i;
    int sign;
    int num;

    i = 0;
    sign = 1;
    num = 0;
    while (a[i] == '\t' || a[i] == '\n' || a[i] == '\v'
            || a[i] == '\f' || a[i] == '\f' || a[i] == ' ')
            i++;
    if (a[i] == '-' || a[i] =='+')
    {
        if (a[i] == '-')
            sign *= -1;
        i++;
    }

    while (a[i] >= '0' && a[i] <= '9')
    {
        num = (num * 10) + a[i] - '0';
        i++;

    }
    return (num * sign);
}
/*

int main(int argc, char **argv)
{
    int res;
    if (argc < 2)
        return 0;
    res=ft_atoi(argv[1]);
    printf("%i",res);
    return 0;
}
*/
