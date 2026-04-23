/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_putstr -- write every character of str to stdout until '\0'.
**
** KEY CONCEPT: C strings and the null terminator
** ================================================
** In C, a "string" is simply an ARRAY OF CHARS that ends with the
** special character '\0' (ASCII value 0, also written as NUL).
** There is no dedicated string type -- just a convention.
**
**   char str[] = "Hi";
**   Memory:  'H' | 'i' | '\0'
**   Indices:  0     1     2
**
** KEY CONCEPT: char pointer as a string iterator
** =================================================
** 'char *str' is a pointer to the first character.
** Incrementing the pointer (str++) advances to the next character:
**   str    -> 'H'
**   str+1  -> 'i'
**   str+2  -> '\0'
**
** The loop condition *str != '\0' (or simply *str) stops when the
** null terminator is reached.
**
** KEY CONCEPT: Pointer arithmetic
** ==================================
** For a pointer p of type T*, the expression p+n gives the address
** of the element n positions ahead: address(p) + n * sizeof(T).
** For char*, sizeof(char)==1, so p+1 is simply the next byte.
**
** KEY CONCEPT: Equivalence of array indexing and pointer arithmetic
** ==================================================================
**   str[i]   is EXACTLY equivalent to *(str + i)
**   This means arrays and pointers are deeply related in C.
**   The compiler translates array subscripts into pointer arithmetic.
*/

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
