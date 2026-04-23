#!/bin/sh
# print_groups.sh - Display all groups the user $FT_USER belongs to,
#                   comma-separated with no spaces.
#
# /*
#  * id: print user identity information (man id)
#  *   -G  : print all group IDs the user belongs to
#  *   -n  : print names instead of numeric IDs
#  *   username: the login to look up (defaults to current user if omitted)
#  *
#  * Environment variables are key=value pairs stored in the process
#  * environment. $FT_USER holds the username set by the caller:
#  *   export FT_USER=daemon
#  *   ./print_groups.sh   →  daemon,bin
#  *
#  * tr: translate or delete characters (man tr)
#  *   ' ' ',': replace every space with a comma.
#  *   id -Gn outputs groups separated by spaces; tr converts that to
#  *   the comma-separated format required by the subject.
#  *
#  * The pipe '|' connects stdout of id directly to stdin of tr,
#  * avoiding any temporary file.
#  */
id -Gn "$FT_USER" | tr ' ' ','
