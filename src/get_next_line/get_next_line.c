/* get_next_line.c - Get next line from a file descriptor */
/* Author: your_login */
/* Description: Read a line from a file descriptor, handling newlines and EOF */

#include "get_next_line.h"
#include <string.h>

char	*get_next_line(int fd)
{
	static char	*remainder = NULL;
	ssize_t		bytes_read;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);

	// Allocate a minimal buffer using standard malloc
	char *buffer = malloc(BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
	 free(buffer);
	 if (bytes_read == 0 && remainder != NULL)
	 {
		 char *line = remainder;
		 remainder = NULL;
		 return (line);
	 }
	 return (NULL);
	}

	buffer[bytes_read] = '\0';

	// Use standard C functions for simplicity
	if (remainder != NULL)
	{
		// Concatenate remainder and buffer
		char *temp = malloc(strlen(remainder) + strlen(buffer) + 1);
		if (temp == NULL)
		{
		 free(buffer);
		 free(remainder);
		 remainder = NULL;
		 return (NULL);
		}
		strcpy(temp, remainder);
		strcat(temp, buffer);
	 free(remainder);
	 remainder = temp;
	}
	else
	{
	 remainder = strdup(buffer);
	}
	
 free(buffer);

	// Find newline in remainder
 char *newline_pos = strchr(remainder, '\n');
	if (newline_pos != NULL)
	{
	 char *line = malloc(newline_pos - remainder + 2); // +2 for newline and null
	 if (line == NULL)
		 return (NULL);
	 strncpy(line, remainder, newline_pos - remainder + 1);
	 line[newline_pos - remainder + 1] = '\0';
	 
	 // Update remainder
	 char *new_remainder = strdup(newline_pos + 1);
	 free(remainder);
	 remainder = new_remainder;
	 
	 return (line);
	}
	else
	{
	 char *line = strdup(remainder);
	 free(remainder);
	 remainder = NULL;
	 return (line);
	}
}