/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_ft.c                                   :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_ultimate_ft -- set the int at the end of a 9-level pointer chain to 42.
**
** KEY CONCEPT: Pointer to pointer (multi-level indirection)
** ==========================================================
** A pointer can point to another pointer.  Each extra * is one more level:
**
**   int    x   = 0;       -- an int
**   int   *p1  = &x;      -- pointer to int
**   int  **p2  = &p1;     -- pointer to pointer to int
**   int ***p3  = &p2;     -- pointer to pointer to pointer to int
**   ...
**   int *********p9 = ...; -- 9 levels deep (this exercise)
**
** Reading declarations (right-to-left rule):
**   int *********nbr
**   Start from nbr: "nbr is a pointer to a pointer to a pointer to a
**   pointer to a pointer to a pointer to a pointer to a pointer to a
**   pointer to int."
**
** To dereference all 9 levels and reach the actual int, apply * nine times:
**   *********nbr = 42;
**   Each * follows one level of indirection.
**
** KEY CONCEPT: Why does this compile?
** =====================================
** The type system tracks the number of levels:
**   *nbr       has type int ********  (8 stars -- still a pointer)
**   **nbr      has type int *******   (7 stars)
**   ...
**   *********nbr has type int         (0 stars -- the actual int)
** Assigning 42 to int is valid; assigning to any pointer level would warn.
*/

void	ft_ultimate_ft(int *********nbr)
{
	*********nbr = 42;
}
