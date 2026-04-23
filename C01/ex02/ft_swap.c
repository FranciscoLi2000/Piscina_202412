/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_swap -- swap the values of two integers via their addresses.
**
** KEY CONCEPT: Swap idiom requires a temporary variable
** ======================================================
** To exchange values *a and *b without losing data:
**
**   Step 1: tmp = *a       -- save a copy of the first value
**   Step 2: *a  = *b       -- overwrite first with second
**   Step 3: *b  = tmp      -- overwrite second with saved first
**
** Why not just:  *a = *b; *b = *a;  ?
**   After *a = *b, the original value of *a is gone.
**   *b = *a would just copy *b back to itself -- nothing swaps.
**
** KEY CONCEPT: Passing by pointer vs passing by value
** =====================================================
** void ft_swap(int a, int b)  -- WRONG for swapping
**   'a' and 'b' are COPIES; swapping them has no effect outside.
**
** void ft_swap(int *a, int *b) -- CORRECT
**   'a' and 'b' hold ADDRESSES of the caller's variables.
**   Dereferencing and assigning modifies the originals.
**
** Memory model:
**   caller:  x=3 at 0x1000,  y=7 at 0x1004
**   ft_swap receives a=0x1000, b=0x1004
**   tmp = *a        -> tmp = 3
**   *a  = *b        -> 0x1000 now holds 7
**   *b  = tmp       -> 0x1004 now holds 3
**   back in caller: x==7, y==3  (swapped!)
*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
