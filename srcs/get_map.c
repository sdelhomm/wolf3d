/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdelhomm <sdelhomm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:52:38 by sdelhomm          #+#    #+#             */
/*   Updated: 2018/03/12 18:32:34 by tgunzbur         ###   ########.fr       */
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

int		check_if_start_tag(t_map *map, t_player *j, char *line, t_param *p)
{
	free(line);
	if (map->map[map->y][map->x] == 9)
	{
		map->map[map->y][map->x] = 0;
		j->x = map->x + 0.5;
		j->y = map->y + 0.5;
		j->a--;
	}
	if (map->map[map->y][map->x] == 3)
		p->tags++;
	return (0);
}

int		get_map(char *file, t_map *map, t_player *j, t_param *p)
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
			check_if_start_tag(map, j, s_line[map->x], p);
		}
		free(s_line);
	}
	if (line && close(fd) == 0 && ++map->y)
		free(line);
	return (0);
}
