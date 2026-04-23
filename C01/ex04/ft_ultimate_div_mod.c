/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_ultimate_div_mod -- divide *a by *b in-place:
**   *a receives the quotient, *b receives the remainder.
**
** KEY CONCEPT: In/out parameters (read-modify-write via pointer)
** ===============================================================
** Unlike ex03 where a and b were read-only copies, here both
** parameters are pointers -- they serve as BOTH inputs AND outputs.
**
** Order of operations matters:
**   We need both *a and *b to compute the results, so we must
**   compute the remainder BEFORE overwriting *a.
**
**   WRONG order:
**     *a = *a / *b;    <- *a is now the quotient
**     *b = *a % *b;    <- uses NEW *a (quotient), not original *a!
**
**   CORRECT approach -- use a temporary:
**     int tmp = *a;
**     *a = tmp / *b;   <- quotient from ORIGINAL *a
**     *b = tmp % *b;   <- remainder from ORIGINAL *a
**
** KEY CONCEPT: Aliasing danger
** ==============================
** What if the caller passes the same address for both a and b?
**   ft_ultimate_div_mod(&x, &x);
** In that case *a and *b refer to the SAME memory location.
** The temporary variable technique handles this safely.
**
** This pattern of "save, compute, store" is fundamental whenever
** you must read from and write to the same memory in one operation.
*/

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = tmp / *b;
	*b = tmp % *b;
}
