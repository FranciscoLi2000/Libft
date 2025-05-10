#include "libft.h"

/**
 *  * ft_strrev - Reverses a string in-place
 *  * @str: The string to be reversed
 *  *
 *  * This function reverses the characters in a string by swapping
 *  * characters from both ends and moving toward the middle. The function
 *  * modifies the original string directly and works with the null-terminated
 *  * string convention in C.
 *  *
 *  * Return: A pointer to the reversed string (same as input pointer)
 *  */

char	*ft_strrev(char *str)
{
	char	*start;
	char	*end;
	char	temp;

	start = str;	/* Points to the beginning of the string */
	end = str;	/* Will be moved to the end of the string */
			/* Temporary storage for character swapping */
	/* Handle NULL or empty string */
	if (str == NULL || *str == '\0')
		return (str);
	/* Find the end of the string (pointing to the null terminator) */
	while (*end)
		end++;
	/* Move end to the last character (not the null terminator) */
	end--;
	/* Swap characters from both ends until we reach the middle */
	while (start < end)
	{
		/* Swap characters at start and end positions */
		temp = *start;
		*start = *end;
		*end = temp;
		/* Move pointers toward the middle */
		start++;
		end--;
	}
	return (str);
}
