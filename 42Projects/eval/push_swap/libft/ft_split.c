/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lglauch <lglauch@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:11:42 by lglauch           #+#    #+#             */
/*   Updated: 2024/02/05 15:55:50 by lglauch          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_count_of_substr(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s != c && *s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static	char	*ft_strcpy(const char *s, int n)
{
	char	*copy;
	int		i;

	i = 0;
	while (s[i] && i < n)
	{
		i++;
	}
	copy = (char *)malloc(sizeof(char) *(i + 1));
	if (!copy)
		return (0);
	i = 0;
	while (s[i] && i < n)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	*ft_free_substrings(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (0);
}

char	**ft_split(const char *s, char c)
{
	char			**split;
	const char		*start;
	int				i;

	i = 0;
	split = (char **)malloc(sizeof(char *) * (ft_count_of_substr(s, c) + 1));
	if (!split)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s != c && *s)
				s++;
			split[i] = ft_strcpy(start, s - start);
			if (!split[i])
				return (ft_free_substrings(split));
			i++;
		}
		else
			s++;
	}
	split[i] = NULL;
	return (split);
}

// int main()
// {
//     int i = 0;
//     const char *input = "hello!zzzzzzzz";
//     char **result = ft_split(input, ' ');
//     while (result && result [i] != 0)
//     {
//         printf("%s\n", result[i]);
//         i++;
//     }
// }
