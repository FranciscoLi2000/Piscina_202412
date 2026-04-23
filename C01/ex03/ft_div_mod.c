/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_div_mod -- divide a by b, store quotient in *div and remainder in *mod.
**
** KEY CONCEPT: Output parameters
** ================================
** C functions can only return ONE value (via 'return').
** When a function needs to produce MULTIPLE results, the convention
** is to pass POINTERS to pre-allocated variables, and write results
** into them via dereferencing.
**
**   *div = a / b;   -- integer quotient (truncated toward zero)
**   *mod = a % b;   -- remainder (same sign as dividend in C99+)
**
** Examples:
**   a=7, b=2  ->  *div=3,   *mod=1    (7 = 3*2 + 1)
**   a=7, b=3  ->  *div=2,   *mod=1    (7 = 2*3 + 1)
**   a=-7, b=2 ->  *div=-3,  *mod=-1   (-7 = -3*2 + (-1))
**
** KEY CONCEPT: Integer division vs floating-point division
** ==========================================================
**   int  result = 7 / 2;   -- result = 3  (truncates, NOT rounds)
**   float result = 7.0 / 2; -- result = 3.5
**
** In C, dividing two ints always yields an int (truncated).
** The fractional part is discarded, not rounded.
**
** KEY CONCEPT: The % (modulo) operator
** =====================================
**   a % b  gives the remainder when a is divided by b.
**   Mathematical identity:  a == (a/b)*b + (a%b)
**   This identity always holds in C (for b != 0).
**
** Parameters 'a' and 'b' are passed BY VALUE (copies).
** Parameters 'div' and 'mod' are passed BY POINTER (output channels).
*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
