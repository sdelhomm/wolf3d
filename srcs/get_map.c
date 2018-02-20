/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgunzbur <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 14:34:13 by tgunzbur          #+#    #+#             */
/*   Updated: 2018/02/20 12:31:43 by tgunzbur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_map	*map_len(char *file, t_map *map)
{
	int		fd;
	char	*line;

	if ((fd = open(file, O_RDONLY)) < 0)
		return (NULL);
	if (get_next_line(fd, &line) < 0)
		return (NULL);
	free(line);
	map->y = 1;
	while (get_next_line(fd, &line) > 0)
	{
		map->y++;
		free(line);
	}
	if (line)
		free(line);
	close(fd);
	return (map);
}

int		ft_tabline(char **tab)
{
	int	count;

	count = 0;
	while (tab[count])
		count++;
	return (count);
}

int		check_if_start(t_map *map, t_player *j, char *line)
{
	free(line);
	if (map->map[map->y][map->x] == 9)
	{
		map->map[map->y][map->x] = 0;
		j->x = map->x;
		j->y = map->y;
		j->a--;
	}
	return (0);
}

int		get_map(char *file, t_map *map, t_player *j)
{
	int		fd;
	char	*line;
	char	**s_line;

	if (!map || (fd = open(file, O_RDONLY)) < 0 ||
		!(map->map = malloc(sizeof(int **) * map->y)))
		return (-1);
	map->y = -1;
	while (get_next_line(fd, &line) > 0)
	{
		s_line = ft_strsplit(line, ' ');
		free(line);
		if (!(map->map[++map->y] = malloc(sizeof(int *) * ft_tabline(s_line))))
			return (-2);
		map->x = -1;
		while (s_line[++map->x])
		{
			map->map[map->y][map->x] = ft_atoi(s_line[map->x]);
			check_if_start(map, j, s_line[map->x]);
		}
		free(s_line);
	}
	if (line && close(fd) == 0 && ++map->y)
		free(line);
	return (0);
}
