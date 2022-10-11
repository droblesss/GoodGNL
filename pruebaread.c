
#include "get_next_line.h"

char	*getstatic(int fd, char *box)
{
	int nr_bytes;
	char *buffer;
	
	if (!box)
		box = ft_calloc(sizeof(char), 1);
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	nr_bytes = 1;
	while (!ft_strchr(buffer, '\n') && nr_bytes != 0)
	{
		nr_bytes = read(fd, buffer, BUFFER_SIZE);
		if (nr_bytes == -1)
		{
			free(buffer);
			free(box);
			return (NULL);
		}
		buffer[nr_bytes] = '\0';
		box = ft_strjoin(box, buffer);
	}
	free(buffer);
	return(box);

}

char	*ft_getline(char *box)
{
	char	*linea;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	if (!box[i])
		return (NULL);
	if (ft_strchr(box,'\n'))
	{
		while (box[i] != '\n')
			i++;
		linea = ft_substr(box, 0, i +1);
		return(linea);
	}
	else if (!ft_strchr(box,'\n'))
	while (box[i] != '\0')
	{
		i++;
	}
	linea = ft_substr(box, 0, i);
	return (linea);
}

char	*cleaner(char 	*box)
{
	size_t i;
	size_t j;
	char	*copy;

	i = 0;
	j = 0;
	while (box[i] != '\n' && box[i]!= '\0')
	{
		i++;
	}
	if(!box)
	{
		free (box);
		return (NULL);
	}
	copy = ft_calloc(sizeof(char), (ft_strlen(box) - i + 1));
	if (!copy)
		return(NULL);
	i++;
	while (box[i])
	{
		copy[j] = box[i];
		j++;
		i++;
	}
	free(box);
	return(copy);
}

char *get_next_line(int fd)
{
	char 		*linea;
	static char *box;
	
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	box = getstatic(fd, box);
	if (!box)
		return(NULL);
	linea = ft_getline(box);
	box = cleaner(box);
	return (linea);
}

// int main()
// {
// 	int fd;
// 	/*char buffer [50];
// 	int szbytes;*/
// 	char *ptr;

// 	fd = open("/Users/drobles/getnextline42/mifichero", O_RDONLY);
// 	ptr = get_next_line(fd);
// 	printf("Output -->%s\n", ptr);
// 	free(ptr);
// 	ptr = get_next_line(fd);
// 	printf("Output -->%s\n", ptr);
// 	free(ptr);
// 	ptr = get_next_line(fd);
// 	printf("Output -->%s\n", ptr);
// 	ptr = get_next_line(fd);
// 	printf("Output -->%s\n", ptr);
// 	free(ptr);
// 	close(fd);
// 	return(0);
// }