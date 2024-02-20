/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amile-ge <amile-ge@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 17:40:38 by amile-ge          #+#    #+#             */
/*   Updated: 2024/02/20 12:08:38 by amile-ge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *a)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (a[i] == '\t' || a[i] == '\n' || a[i] == '\v' || a[i] == '\f'
		|| a[i] == '\f' || a[i] == ' ')
		i++;
	if (a[i] == '-' || a[i] == '+')
	{
		if (a[i] == '-')
			sign *= -1;
		i++;
	} 
	if (a[i] == '-' || a[i] == '+')
	{
		write(2,"Error\n", 6);
		exit(1);
	}
	while (a[i] >= '0' && a[i] <= '9')
	{
		num = (num * 10) + a[i++] - '0';
	//	i++;
	}
	if ((int)num * sign < 0 != sign < 0)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	return (num * sign);
}

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 && str1[i] == 0 && str2[i] == 0)
		return (0);
	while ((unsigned char)(str1[i] != '\0' || (unsigned char)str2[i] != '\0')
		&& i < n)
	{
		if (str1[i] == str2[i])
			i++;
		else
			return ((unsigned char)(str1[i]) - (unsigned char)(str2[i]));
	}
	return (0);
}

int	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}
void	*ft_bzero(void *str, size_t size)
{
	unsigned char	*str_str;
	size_t			i;

	str_str = (unsigned char *)str;
	i = 0;
	while (i < size)
	{
		*str_str = '\0';
		str_str++;
		i++;
	}
	return (str);
}
void	*ft_calloc(size_t count, size_t size)
{
	void	*memory;

	memory = malloc(size * count);
	if (memory == 0)
		return (0);
	ft_bzero(memory, (size * count));
	return (memory);
}
static int	ft_count_words(char const *s, char c);
static int	ft_len_words(char const *s, char c, int *end);
static void	ft_fill_up(char *super_array, int init, int end, char const *s);
static void	ft_free(char **super_array, int i);

char	**ft_split(char const *s, char c)
{
	int		i;
	char	**super_array;
	int		end;
	int		init;

	end = 0;
	i = 0;
	super_array = (char **)ft_calloc((ft_count_words(s, c) + 1),
			sizeof(char *));
	if (!super_array)
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		init = ft_len_words(s, c, &end);
		super_array[i] = (char *)ft_calloc((end - init + 1), sizeof(char));
		if (super_array[i] == NULL)
		{
			ft_free(super_array, i);
			return (NULL);
		}
		ft_fill_up(super_array[i], init, (end - init), s);
		i++;
	}
	super_array[i] = NULL;
	return (super_array);
}

static void	ft_fill_up(char *super_array, int init, int end, char const *s)
{
	int	fill;

	fill = 0;
	while (fill < end)
	{
		super_array[fill] = s[init];
		fill++;
		init++;
	}
	super_array[fill] = '\0';
}

static void	ft_free(char **super_array, int i)
{
	while (i > 0)
	{
		free(super_array[i - 1]);
		i--;
	}
	free(super_array);
}

static int	ft_count_words(char const *s, char c)
{
	int	i;
	int	whut;
	int	count;

	count = 0;
	whut = 1;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			if (whut)
			{
				count++;
				whut = 0;
			}
		}
		else
			whut = 1;
		i++;
	}
	return (count);
}

static int	ft_len_words(char const *s, char c, int *end)
{
	int	start;
	int	whut;

	start = *end;
	whut = 1;
	while ((s[*end] != c || whut) && (*end < (int)ft_strlen(s)) && s[*end])
	{
		if (s[*end] != c)
			whut = 0;
		else if (s[*end] == c)
			start++;
		(*end)++;
	}
	return (start);
}
