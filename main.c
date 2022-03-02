/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yanab <yanab@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 09:15:40 by yanab             #+#    #+#             */
/*   Updated: 2022/03/02 01:01:13 by yanab            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Print error and exit
void	print_err(char const *error_msg)
{
	while (*error_msg)
		write(1, error_msg++, 1);
	exit(0);
}

// Close window & exit program
int	close_window(void)
{
	exit(0);
	return (0);
}

// Program main function
/**
 * TODO: move enemy
 * TODO: sprite animation
 */
int	main(int argc, char const **argv)
{
	int		map_fd;
	t_data	game_data;

	if (argc != 2)
		print_err("Usage: ./solong <map_file>\n");
	if (ft_strncmp(".ber", argv[1] + (ft_strlen(argv[1]) - 4), 4) != 0)
		print_err("Error: Your map must be of type .ber\n");
	init_data(argv[1], &game_data);
	render_map(&game_data);
	mlx_hook(game_data.window.element, 2, 1L << 0, handle_keyevent, &game_data);
	mlx_hook(game_data.window.element, 17, 0, close_window, NULL);
	mlx_loop(game_data.mlx);
	return (0);
}
