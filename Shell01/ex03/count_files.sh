#!/bin/sh
# count_files.sh - Count regular files AND directories starting from
#                  the current directory, including all sub-directories.
#
# /*
#  * find: recursively walks the directory tree (man find)
#  *   .         : starting point — the current directory (".")
#  *   -type f   : match regular files
#  *   -type d   : match directories (includes "." itself, which is
#  *               why the count includes the starting directory)
#  *   \( ... \) : group expressions — parentheses must be escaped
#  *               with \ so the shell passes them literally to find
#  *   -o        : logical OR; matches items of type f OR type d
#  *
#  * wc -l: count lines in its input (man wc)
#  *   Each file path printed by find occupies one line, so wc -l
#  *   gives the total count of matched items.
#  *
#  * Why does "." count?
#  *   find lists the starting directory itself when -type d is used,
#  *   because "." is itself a directory. The subject explicitly says
#  *   'It should include ".", the starting directory.'
#  */
find . \( -type f -o -type d \) | wc -l
