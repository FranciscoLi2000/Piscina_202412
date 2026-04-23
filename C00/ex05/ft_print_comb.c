/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_print_comb -- print all combinations of 3 different digits in
**                  ascending order, separated by ", ".
**                  Output: "012, 013, ..., 789"
**
** KEY CONCEPT: Combinations vs Permutations
** ===========================================
** A PERMUTATION counts order: {1,2,3} and {3,2,1} are different.
** A COMBINATION ignores order: {1,2,3} == {3,2,1}.
**
** To generate combinations (no repeats, ascending):
**   For every triple (a, b, c): a < b < c (strictly increasing).
**   This ensures each set appears exactly once.
**
** KEY CONCEPT: Nested while loops
** =================================
** Three nested loops over digits 0-9:
**   a: 0 to 7  (leaves room for two more digits above)
**   b: a+1 to 8
**   c: b+1 to 9
**
** KEY CONCEPT: Writing a digit character
** ========================================
** 'a' is an int (0-7). To write it as a character: a + '0'
**   int 0 + 48 = 48 = '0',  int 7 + 48 = 55 = '7'
** Store in a char variable, then pass its address to write().
**
** KEY CONCEPT: Separator logic (no trailing ", ")
** =================================================
** Print ", " after every triple EXCEPT the very last one (7,8,9).
** Condition: NOT (a==7 AND b==8 AND c==9).
*/

void	ft_print_comb(void)
{
	int		a;
	int		b;
	int		c;
	char	ch;

	a = 0;
	while (a <= 7)
	{
		b = a + 1;
		while (b <= 8)
		{
			c = b + 1;
			while (c <= 9)
			{
				ch = a + '0';
				write(1, &ch, 1);
				ch = b + '0';
				write(1, &ch, 1);
				ch = c + '0';
				write(1, &ch, 1);
				if (a != 7 || b != 8 || c != 9)
					write(1, ", ", 2);
				c++;
			}
			b++;
		}
		a++;
	}
}
