/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_print_comb2 -- print all combinations of two 2-digit numbers
**                   (00-99), listed in ascending order.
**                   Output: "00 01, 00 02, ..., 00 99, 01 02, ..., 98 99"
**
** KEY CONCEPT: Two-digit numbers from two separate digits
** ========================================================
** Each "number" printed is two characters: tens digit then units digit.
** For the number N (0 to 99):
**   tens  = N / 10   -- integer division gives the tens digit (0-9)
**   units = N % 10   -- modulo gives the units digit (0-9)
** Convert each to a printable character by adding '0'.
**
** KEY CONCEPT: Integer division and modulo
** ==========================================
**   42 / 10 = 4   (integer division truncates toward zero)
**   42 % 10 = 2   (remainder after division)
**   These two operators together let you split any number into its
**   individual digits -- a core technique used in ft_putnbr (ex07).
**
** KEY CONCEPT: Combination condition for two numbers
** ====================================================
** We need pairs (a, b) where a < b, a in [0,98] and b in [a+1,99].
** Total: C(100,2) = 4950 pairs.
**
** KEY CONCEPT: static helper function
** =====================================
** ft_print_two_digits is declared 'static' -- it is only visible in
** this translation unit (.c file). This keeps the global namespace
** clean and tells the compiler the function is local.
*/

static void	ft_print_two_digits(int n)
{
	char	c;

	c = (n / 10) + '0';
	write(1, &c, 1);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_print_two_digits(a);
			write(1, " ", 1);
			ft_print_two_digits(b);
			if (a != 98 || b != 99)
				write(1, ", ", 2);
			b++;
		}
		a++;
	}
}
