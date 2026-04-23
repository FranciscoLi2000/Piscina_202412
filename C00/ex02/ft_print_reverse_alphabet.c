/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_print_reverse_alphabet -- print 'z' down to 'a' on one line.
**
** KEY CONCEPT: Counting downwards with while
** ===========================================
** Instead of incrementing (c++) we decrement (c--).
**
**   char c = 'z';   → start at ASCII 122
**   c >= 'a'        → stop condition: run while c is at least 'a' (97)
**   c--             → move to the previous character each iteration
**
** KEY CONCEPT: Post-decrement vs pre-decrement
** =============================================
**   c--  (post-decrement): uses c's current value in the expression,
**        then subtracts 1 from c.
**   --c  (pre-decrement):  subtracts 1 first, then uses the new value.
**
**   When c-- appears alone on its own line (as required by the Norm),
**   both forms have the same effect — but the Norm requires the
**   increment/decrement to be its own statement, not embedded inside
**   another expression (e.g. write(1, c--, 1) is NOT allowed by Norm).
**
** KEY CONCEPT: Variable declaration at top of scope
** ==================================================
**   The 42 Norm requires that ALL local variables be declared at the
**   very beginning of the function, before any instructions.
**   This mirrors ANSI C89 rules and makes variable lifetimes explicit.
*/

void	ft_print_reverse_alphabet(void)
{
	char	c;

	c = 'z';
	while (c >= 'a')
	{
		write(1, &c, 1);
		c--;
	}
}
