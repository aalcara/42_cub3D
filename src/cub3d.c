/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalcara- <aalcara-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:56:42 by aalcara-          #+#    #+#             */
/*   Updated: 2021/05/26 13:20:59 by aalcara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_cub(char *str, t_cub *cub)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != '.')
	{
		i--;
		if (i == 0)
		{
			ft_error(cub, "Invalid map name\n");
			return (0);
		}
	}
	if (str[i + 1] == 'c' && str[i + 2] == 'u' && str[i + 3] == 'b')
		ft_parsing(str, cub);
	else
		ft_error(cub, "Invalid map name\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub		cub;

	cub.save = 0;
	ft_init_geral(&cub);
	if (argc == 2 || (argc == 3 && ft_check_save(argv[2]) == 1))
	{
		if (argc == 3)
			cub.save = 1;
		ft_cub(argv[1], &cub);
	}
	else
		ft_error(&cub, "Invalid Arguments\n");
}
