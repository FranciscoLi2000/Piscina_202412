#!/bin/sh
# find_sh.sh - Find all .sh files recursively and print their names
#              without the .sh extension.
#
# /*
#  * find: search for files in a directory hierarchy (man find)
#  *   .            : start from the current directory
#  *   -name "*.sh" : match any file whose name ends with ".sh"
#  *                  The * is a glob wildcard matching any sequence
#  *                  of characters (must be quoted to prevent shell
#  *                  expansion before find sees it).
#  *
#  * basename: strip leading directory components and optional suffix
#  *   basename path/to/file.sh .sh  →  file
#  *   The second argument is the suffix to remove.
#  *
#  * -exec cmd {} \;
#  *   Executes cmd for each matched file, substituting {} with the
#  *   file path. The \; terminates the -exec expression.
#  *
#  * Recursion: find descends into every sub-directory automatically.
#  * There is no need to write loops or call find multiple times.
#  */
find . -name "*.sh" -exec basename {} .sh \;
