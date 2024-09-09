/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrasolof <hrasolof@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 21:45:44 by hrasolof          #+#    #+#             */
/*   Updated: 2024/09/09 14:18:46 by hrasolof         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*clean_line(char *line)
{
	char	*ptr;

	ptr = line;
	while (*ptr)
	{
		if (*ptr == '\r')
			ft_memmove(ptr, ptr + 1, ft_strlen(ptr));
		else
			ptr++;
	}
	return (line);
}

void	*ft_free_to(char *line, char *map_content)
{
	free(line);
	free(map_content);
	return (NULL);
}

int	check_n(char *map_content)
{
	int	i;

	i = 0;
	while (map_content[i])
	{
		if (map_content[0] == '\n' || (map_content[i] == '\n' && map_content[i
					+ 1] == '\n'))
		{
			free(map_content);
			return (0);
		}
		i++;
	}
	return (1);
}

char	**parse_map(int fd, t_game *data)
{
	char	*line;
	char	*map_content;
	char	*temp;

	map_content = NULL;
	while ((line = get_next_line(fd)) != NULL) // need to modify this part
	{
		if (*line == '\0')
			ft_free_to(line, map_content);
		line = clean_line(line);
		temp = map_content;
		map_content = ft_strjoin(map_content, line);
		free(temp);
		free(line);
	}
	if (map_content == NULL)
		return (NULL);
	if (check_n(map_content) == 0)
		return (NULL);
	data->map = ft_split(map_content, '\n');
	free(map_content);
	if (!data->map)
		return (NULL);
	return (data->map);
}
