#!/bin/sh
# r_dwssap.sh - Process /etc/passwd: strip comments, keep every other
#               line (from 2nd), reverse each login, sort reverse-alpha,
#               slice lines FT_LINE1..FT_LINE2, print ", "-joined + "."
#
# /*
#  * /etc/passwd: the system user database (man 5 passwd)
#  *   Each line: login:password:UID:GID:GECOS:home:shell
#  *   Lines starting with '#' are comments.
#  *
#  * Pipeline — each step feeds its stdout to the next command's stdin:
#  *
#  *  grep -v '^#'
#  *    Remove comment lines (-v inverts the match: keep non-matching).
#  *    '^#' is a regex: ^ anchors to start-of-line, # is literal.
#  *
#  *  awk 'NR%2==0'
#  *    Keep every other line starting from the 2nd (even-numbered lines).
#  *    NR is awk's current line counter; NR%2==0 selects lines 2,4,6,…
#  *
#  *  cut -d: -f1
#  *    Extract field 1 (the login name) using ':' as delimiter.
#  *    cut is faster than awk for simple field extraction.
#  *
#  *  rev
#  *    Reverse the characters of each line.
#  *    "root" → "toor", "_www" → "www_"
#  *
#  *  sort -r
#  *    Sort lines in reverse lexicographic (alphabetical) order.
#  *    Default sort is ascending; -r flips to descending.
#  *
#  *  sed -n "${FT_LINE1},${FT_LINE2}p"
#  *    Print only lines numbered FT_LINE1 through FT_LINE2 (inclusive).
#  *    -n suppresses automatic printing; p prints the addressed range.
#  *    Shell variables are expanded inside double-quoted sed expressions.
#  *
#  *  tr '\n' ','
#  *    Replace every newline with a comma, joining all logins on one line.
#  *
#  *  sed 's/,/, /g; s/, $//'
#  *    First substitution: expand each comma to ", " (comma + space).
#  *    Second substitution: remove the trailing ", " left by the last entry.
#  *
#  *  printf '\n.\n'
#  *    Print a newline (ending the logins line) then "." then a newline.
#  */
cat /etc/passwd \
    | grep -v '^#' \
    | awk 'NR%2==0' \
    | cut -d: -f1 \
    | rev \
    | sort -r \
    | sed -n "${FT_LINE1},${FT_LINE2}p" \
    | tr '\n' ',' \
    | sed 's/,/, /g; s/, $//'
printf '\n.\n'
