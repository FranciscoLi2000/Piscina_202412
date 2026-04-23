/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_print_combn -- print all combinations of n different digits
**                   (0 < n < 10) in ascending order.
**
** KEY CONCEPT: Generalising ft_print_comb with recursion
** ========================================================
** ft_print_comb (ex05) used 3 hardcoded nested while loops for n=3.
** For a variable n we cannot write n nested loops at compile time.
** Solution: RECURSION -- each call handles one digit position.
**
** Algorithm:
**   Keep an array tab[] of n digits (one slot per position).
**   At each recursion depth 'pos' (0 to n-1), try all valid digits
**   starting from 'start' (strictly greater than the previous digit).
**   When pos == n, we have a complete combination -- print it.
**
** KEY CONCEPT: Arrays in C
** =========================
**   int tab[9];       -- array of 9 ints on the stack
**   tab[pos] = start; -- set element at runtime index
**
**   Arrays passed to a function decay to a pointer to the first
**   element. Changes to tab[pos] inside ft_recurse are visible to
**   the caller -- "passed by reference" via pointer.
**
** KEY CONCEPT: Upper bound for each position
** ============================================
** At depth 'pos', there are (n - 1 - pos) positions still to fill.
** Each needs a digit strictly higher, so the maximum digit at
** position 'pos' is: 9 - (n - 1 - pos).
** Example n=3: pos=0 -> max=7, pos=1 -> max=8, pos=2 -> max=9.
**
** KEY CONCEPT: is_last helper -- detect the final combination
** =============================================================
** The last combination has tab[i] == 9 - (n - 1 - i) for all i.
** If true, we skip printing ", " after it.
*/

static int	is_last(int *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (tab[i] != 9 - (n - 1 - i))
			return (0);
		i++;
	}
	return (1);
}

static void	ft_recurse(int *tab, int pos, int n, int start)
{
	int		d;
	char	c;

	if (pos == n)
	{
		d = 0;
		while (d < n)
		{
			c = tab[d] + '0';
			write(1, &c, 1);
			d++;
		}
		if (!is_last(tab, n))
			write(1, ", ", 2);
		return ;
	}
	while (start <= 9 - (n - 1 - pos))
	{
		tab[pos] = start;
		ft_recurse(tab, pos + 1, n, start + 1);
		start++;
	}
}

void	ft_print_combn(int n)
{
	int	tab[9];

	ft_recurse(tab, 0, n, 0);
}
