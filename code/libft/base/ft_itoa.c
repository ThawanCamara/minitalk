/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-souz <tde-souz@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 19:49:44 by tde-souz          #+#    #+#             */
/*   Updated: 2022/05/31 19:49:44 by tde-souz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_dozens(size_t num)
{
	size_t	dozens;

	dozens = 1;
	while (num >= 10)
	{
		num /= 10;
		dozens++;
	}
	return (dozens);
}

static void	setnbr(size_t num, const char *s, size_t sign, size_t dozens)
{	
	if (sign == 1)
		*(char *) s = '-';
	*(char *)(s + sign + dozens) = 0;
	while (dozens--)
	{
		*(char *)(s + sign + dozens) = num % 10 + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	size_t	num;
	size_t	sign;
	size_t	dozens;
	char	*ret;

	sign = 0;
	if (n >= 0)
		num = (size_t) n;
	else
	{
		num = (size_t) n * -1;
		sign = 1;
	}
	dozens = count_dozens(num);
	ret = (char *)malloc((sign + dozens + 1) * sizeof(char));
	if (ret == 0)
		return (0);
	setnbr(num, ret, sign, dozens);
	return (ret);
}
