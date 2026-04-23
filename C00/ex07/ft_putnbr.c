/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_putnbr -- display the integer nb using only write().
**              Must handle ALL int values: -2147483648 to 2147483647.
**
** KEY CONCEPT: Recursion
** =======================
** Recursion = a function that calls itself.
** Base case:     nb < 10 -- just write the single digit.
** Recursive case: recurse with nb/10 (all but last digit),
**                 then write nb%10 (the last digit).
**
** Example: ft_putnbr(423)
**   -> ft_putnbr(42)  then write '3'
**      -> ft_putnbr(4) then write '2'
**         -> write '4'  (base case: 4 < 10)
** Output: "423"
**
** KEY CONCEPT: The INT_MIN edge case (-2147483648)
** =================================================
** The int range is [-2147483648, +2147483647].
** |INT_MIN| = 2147483648 does NOT fit in a positive int!
**   if (nb < 0) nb = -nb;  WRONG: -(-2147483648) overflows.
** Safe fix: cast to 'unsigned long' (64 bits) before negating,
** via -(long)nb which won't overflow in a long, then cast to
** unsigned long to work with positive values only.
**
** KEY CONCEPT: Signed vs unsigned integers
** ==========================================
**   signed int:   uses 1 bit for sign, 31 for magnitude.
**   unsigned long: 64-bit unsigned -- large enough for |INT_MIN|.
**
** KEY CONCEPT: Writing a single digit
** =====================================
**   digit = n % 10   in range [0,9]
**   char c = digit + '0'   converts to ASCII character
**   write(1, &c, 1)  outputs exactly one byte
*/

void	ft_putnbr(int nb)
{
	unsigned long	n;
	char			c;

	if (nb < 0)
	{
		write(1, "-", 1);
		n = (unsigned long)(-(long)nb);
	}
	else
		n = (unsigned long)nb;
	if (n >= 10)
		ft_putnbr((int)(n / 10));
	c = (char)(n % 10) + '0';
	write(1, &c, 1);
}
