/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+    */
/*   By: student <student@student.42.fr>            +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+          */
/*   Created: 2024/01/01 00:00:00 by student           #+#    #+#            */
/*   Updated: 2024/01/01 00:00:00 by student          ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** ft_putchar -- display a single character to standard output.
**
** KEY CONCEPT: The write() system call
** =====================================
** write(int fd, const void *buf, size_t count)
**
**   fd    : file descriptor.
**             0 = stdin  (keyboard input)
**             1 = stdout (terminal screen)   ← we use this one
**             2 = stderr (error output)
**   buf   : pointer to the data to write.
**             &c takes the ADDRESS of the local variable c,
**             giving write() a pointer to exactly 1 byte.
**   count : number of bytes to write — just 1 for a single char.
**
** Why not printf?
**   printf is a C-library function that internally calls write after
**   formatting. The subject restricts us to write directly, which is
**   a "syscall" — a direct request to the operating-system kernel.
**   This teaches that ALL I/O ultimately goes through the kernel.
**
** char type:
**   In C, a char is a 1-byte (8-bit) integer.  ASCII maps the
**   printable characters to values 0–127 (e.g. 'A'=65, 'z'=122).
**   Passing it as a parameter copies its value onto the stack.
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
