/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_is_negative -- print 'N' if n < 0, else print 'P'.
**
** KEY CONCEPT: int type and signed integers
** ==========================================
** An 'int' on modern systems is a 32-bit signed integer.
** Range: -2,147,483,648  to  +2,147,483,647
**           (INT_MIN)           (INT_MAX)
**
** In two's-complement (used by every modern CPU), bit 31 is the SIGN BIT:
**   0 -> positive or zero
**   1 -> negative
**
** KEY CONCEPT: if / else conditional
** ====================================
**   if (condition)    -- executed when condition is true (non-zero)
**   else              -- executed when condition is false (zero)
**
**   n < 0  evaluates to 1 (true) when n is negative, 0 otherwise.
**
** KEY CONCEPT: Special case -- zero
** ==================================
**   0 is neither negative nor positive in mathematics, but the
**   subject says: "If n is positive OR NULL, display 'P'".
**   So 0 -> 'P'.  Our condition n < 0 naturally handles this:
**   (0 < 0) is false, so we fall through to the else branch. OK.
**
** KEY CONCEPT: Passing by VALUE
** ==============================
**   The parameter 'int n' is a COPY of the caller's value.
**   Modifying n inside this function does NOT affect the caller.
**   C always passes primitive types (int, char, float, etc.) by value.
*/

void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}
