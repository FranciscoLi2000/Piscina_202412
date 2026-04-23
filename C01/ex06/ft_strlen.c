/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strlen -- count and return the number of characters before '\0'.
**
** KEY CONCEPT: Returning a value from a function
** ================================================
** Unlike void functions, ft_strlen returns an int -- the length.
** 'return (len);' passes the value back to the caller.
**
** KEY CONCEPT: int vs size_t for lengths
** ========================================
** The standard library uses 'size_t' (an unsigned type) for lengths,
** because lengths are never negative.  The subject asks for int,
** which is fine for learning -- real-world code uses size_t.
**
** KEY CONCEPT: Counting characters with a loop counter
** =====================================================
** Strategy:
**   1. Start a counter len = 0.
**   2. Walk through each character with str++ until '\0'.
**   3. Increment len for each character seen.
**   4. Return len.
**
** Alternative -- pointer difference:
**   char *end = str;
**   while (*end) end++;
**   return (int)(end - str);   -- pointer subtraction gives element count
**
** Both approaches are O(n) -- they must visit every character once.
** The standard strlen() cannot know the length without scanning.
**
** KEY CONCEPT: Empty string
** ==========================
** If str points directly at '\0', the while loop body never runs
** and len stays 0 -- correctly returning 0 for the empty string "".
*/

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
