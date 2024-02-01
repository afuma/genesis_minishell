/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 21:08:24 by wnguyen           #+#    #+#             */
/*   Updated: 2024/02/01 01:54:42 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

char	*ft_strdup(const char *str)
{
	size_t	slen;
	char	*result;

	if (!str)
		return (NULL);
	slen = ft_strlen(str);
	result = (char *)malloc(sizeof(char) * (slen + 1));
	if (!result)
		return (0);
	slen = 0;
	while (str[slen])
	{
		result[slen] = str[slen];
		slen++;
	}
	result[slen] = '\0';
	return (result);
}
