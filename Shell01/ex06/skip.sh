#!/bin/sh
# skip.sh - Display every other line of 'ls -l', starting from line 1
#           (i.e. lines 1, 3, 5, …).
#
# /*
#  * ls -l: list directory contents in long format (man ls)
#  *   Shows permissions, link count, owner, group, size, date, name.
#  *   The first output line is "total <n>" (disk usage summary).
#  *
#  * awk: pattern scanning and text processing language (man awk)
#  *   NR  : built-in variable holding the current record (line) number,
#  *         starting at 1.
#  *   NR%2 : modulo-2 of the line number.
#  *         NR%2 == 1  →  odd lines (1, 3, 5, …)
#  *         NR%2 == 0  →  even lines (2, 4, 6, …)
#  *
#  *   The pattern 'NR%2==1' acts as a filter: awk prints the line
#  *   automatically when its pattern evaluates to true (non-zero).
#  *   No explicit {print} action is needed.
#  *
#  * "Starting from the first line" means we keep odd-numbered lines,
#  *  skipping even ones.
#  */
ls -l | awk 'NR%2==1'
