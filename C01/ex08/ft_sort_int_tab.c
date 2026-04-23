/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_sort_int_tab -- sort an array of ints in ascending order (bubble sort).
**
** KEY CONCEPT: Bubble sort algorithm
** ====================================
** Bubble sort is the simplest sorting algorithm.
** Each PASS through the array compares adjacent pairs and swaps them
** if they are in the wrong order.  After each pass, the largest
** unsorted element has "bubbled up" to its correct position.
**
** Pass 1 example: {5, 3, 1, 4, 2}
**   compare (5,3): swap -> {3, 5, 1, 4, 2}
**   compare (5,1): swap -> {3, 1, 5, 4, 2}
**   compare (5,4): swap -> {3, 1, 4, 5, 2}
**   compare (5,2): swap -> {3, 1, 4, 2, 5}  <- 5 is in place
**
** After pass k, the last k elements are sorted.
** We need at most size-1 passes.
**
** KEY CONCEPT: Nested while loops for sorting
** =============================================
** Outer loop: counts passes (we need up to size-1 of them).
** Inner loop: scans from index 0 to (size-2-pass), comparing tab[i]
**             with tab[i+1].
**
** Complexity: O(n^2) comparisons in the worst case.
** Efficient? No.  But it is easy to understand and implement correctly.
** Real-world code uses qsort() from <stdlib.h> for large arrays.
**
** KEY CONCEPT: Stable sort
** ==========================
** Bubble sort is STABLE -- equal elements keep their original order.
** Stability matters when sorting records by multiple keys.
**
** KEY CONCEPT: Swap without a helper function
** =============================================
** We use the same tmp trick from ft_swap (ex02):
**   tmp = tab[i]; tab[i] = tab[i+1]; tab[i+1] = tmp;
*/

void	ft_sort_int_tab(int *tab, int size)
{
	int	pass;
	int	i;
	int	tmp;

	pass = 0;
	while (pass < size - 1)
	{
		i = 0;
		while (i < size - 1 - pass)
		{
			if (tab[i] > tab[i + 1])
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		pass++;
	}
}
