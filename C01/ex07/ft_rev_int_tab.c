/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_rev_int_tab -- reverse an array of ints in place.
**
** KEY CONCEPT: Arrays and pointers
** ==================================
** When you pass 'int *tab' to a function, the function receives
** the address of the first element.  Changes made through tab[]
** ARE visible to the caller -- arrays are always "passed by reference"
** in C (unlike scalars, which are copied).
**
**   tab[0]  == *(tab + 0)  == *tab
**   tab[i]  == *(tab + i)
**
** KEY CONCEPT: In-place reversal with two indices
** =================================================
** Use a LEFT index (i) starting at 0 and a RIGHT index (j) starting
** at size-1.  Swap tab[i] and tab[j], then move both indices inward.
** Stop when they meet or cross (i >= j).
**
** Example: {1, 2, 3, 4, 5}, size=5
**   swap(0,4): {5, 2, 3, 4, 1}
**   swap(1,3): {5, 4, 3, 2, 1}
**   i==j at 2: done
**
** KEY CONCEPT: Why size/2 iterations?
** =====================================
** Reversing N elements requires exactly N/2 swaps (integer division).
** For N=5: 2 swaps.  For N=4: 2 swaps.
** If we continued past the midpoint we would swap back and undo work.
**
** KEY CONCEPT: Edge cases
** ========================
** size == 0 or size == 1: i starts at 0, j starts at -1 or 0.
** In both cases i >= j immediately, so the loop never runs. Safe.
*/

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = size - 1;
	while (i < j)
	{
		tmp = tab[i];
		tab[i] = tab[j];
		tab[j] = tmp;
		i++;
		j--;
	}
}
