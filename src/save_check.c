/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 10:57:01 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/26 13:27:07 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_check_save(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] == 'e' && str[i - 2] == 'v' && str[i - 3] == 'a' && \
		str[i - 4] == 's' && str[i - 5] == '-' && str[i - 6] == '-' \
		&& ft_strlen(str) < 7)
		return (1);
	else
		return (0);
}
