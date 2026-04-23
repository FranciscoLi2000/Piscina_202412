/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_print_alphabet -- print 'a' through 'z' on one line.
**
** KEY CONCEPT: Characters are integers + the ASCII table
** =======================================================
** In C, a char variable holds a small integer.  The ASCII encoding
** assigns 'a' = 97, 'b' = 98, ..., 'z' = 122.
**
** Because these are consecutive integers we can use a loop counter
** that starts at 'a' and increments up to (and including) 'z'.
**
**   char c = 'a';    ← same as:  char c = 97;
**   c <= 'z'         ← same as:  c <= 122;
**   c++              ← moves to the next ASCII character each iteration
**
** KEY CONCEPT: while loop
** ========================
**   while (condition)
**       statement;
**
**   1. Evaluate condition.
**   2. If true (non-zero), execute statement, then go back to 1.
**   3. If false (zero), exit the loop.
**
**   The 42 Norm forbids 'for' loops in function bodies — use while.
**
** KEY CONCEPT: void parameter
** ============================
**   void ft_print_alphabet(void) — the 'void' in the parameter list
**   is C's way of saying "this function takes NO arguments".
**   It is different from ft_print_alphabet() which (in old C89) means
**   "unspecified" — the explicit void is required by the Norm.
*/

void	ft_print_alphabet(void)
{
	char	c;

	c = 'a';
	while (c <= 'z')
	{
		write(1, &c, 1);
		c++;
	}
}
