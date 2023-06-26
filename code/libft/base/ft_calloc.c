/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 10:45:54 by tde-souz          #+#    #+#             */
/*   Updated: 2022/06/02 20:23:29 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;
	size_t	i;

	ret = malloc(count * size);
	if (ret == 0)
		return (0);
	i = 0;
	while (i < count * size)
	{
		*(char *)(ret + i) = '\0';
		i++;
	}
	return (ret);
}
