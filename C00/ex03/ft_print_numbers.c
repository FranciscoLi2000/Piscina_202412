/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_print_numbers -- print all decimal digits '0' through '9' on one line.
**
** KEY CONCEPT: Digit characters vs digit values
** ===============================================
** The character '0' has ASCII value 48.
** '1' = 49, '2' = 50, ..., '9' = 57.
**
** Important distinction:
**   int  n = 5;        ← the integer value 5
**   char c = '5';      ← the character '5' = ASCII 53
**
** To turn a digit VALUE (0-9) into its printable CHARACTER,
** add '0':   char c = n + '0';   (5 + 48 = 53 = '5')
**
** This pattern is used constantly in ft_putnbr (ex07) and many
** other number-printing functions you will write in the Piscine.
**
** Here we simply iterate over the character range '0'..'9',
** which is equivalent to iterating over integers 48..57.
**
** KEY CONCEPT: Scope of variables
** =================================
** 'c' is a LOCAL variable — it lives on the STACK and exists only
** for the duration of the function call.  When ft_print_numbers
** returns, 'c' is automatically freed (the stack frame is popped).
** This is different from GLOBAL or STATIC variables.
*/

void	ft_print_numbers(void)
{
	char	c;

	c = '0';
	while (c <= '9')
	{
		write(1, &c, 1);
		c++;
	}
}
