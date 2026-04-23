/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.c                                            :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_ft -- set the integer pointed to by 'nbr' to 42.
**
** KEY CONCEPT: What is a pointer?
** =================================
** A pointer is a variable whose VALUE is a MEMORY ADDRESS.
**
**   int  x = 0;   -- x lives at some address, say 0x7fff1234, value = 0
**   int *p = &x;  -- p holds the address 0x7fff1234
**
**   *p = 42;      -- DEREFERENCE: follow the address and write 42 there
**                 -- now x == 42
**
** Pointer declaration syntax:
**   int *nbr   -- "nbr is a pointer to int"
**              -- the * is part of the TYPE, not the variable name
**
** Why use pointers?
**   C passes ALL arguments BY VALUE (a copy).
**   Without a pointer, any change to the copy is lost when the function returns.
**   With a pointer the function receives the ADDRESS of the original variable
**   and can modify it directly.
**
** Operators:
**   &  (address-of)  -- gives the address of a variable
**   *  (dereference) -- accesses the value AT an address
**
** Memory model (simplified):
**   address  | value
**   ---------+------
**   0x1000   |  42    <- *nbr = 42 writes here
**   ...
**   stack    | 0x1000 <- nbr (the pointer itself, holds address 0x1000)
*/

void	ft_ft(int *nbr)
{
	*nbr = 42;
}
