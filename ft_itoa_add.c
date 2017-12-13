/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:32:08 by fdikilu           #+#    #+#             */
/*   Updated: 2017/12/13 05:21:53 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_char(unsigned long n, int base)
{
	int		len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

char		*ft_itoa_add(unsigned long n, int base)
{
	int		len;
	char	*str;

	str = NULL;
	len = ft_nb_char(n, base);
	if (!(str = (char *)malloc(sizeof(*str) * (len + 1))))
		return (NULL);
	str[len + 1] = '\0';
	while (len--)
	{
		str[len] = BASE[(n % base)];
		n /= base;
	}
	return (str);
}
