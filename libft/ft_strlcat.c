/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hohnuki <hohnuki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:08:12 by hohnuki           #+#    #+#             */
/*   Updated: 2021/11/09 21:02:48 by hohnuki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	ans;
	size_t	dest_len;
	size_t	src_len;
	size_t	first_dest_len;

	i = 0;
	ans = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	first_dest_len = dest_len;
	if (!destsize)
		return (src_len + destsize);
	else if (dest_len >= destsize)
		ans = src_len + destsize;
	else
		ans = dest_len + src_len;
	while (src[i] != '\0' && i + first_dest_len < destsize - 1)
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	return (ans);
}
