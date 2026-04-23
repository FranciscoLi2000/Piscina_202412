#!/bin/sh
# git_ignore.sh - List all files currently ignored by the git repository
#
# /*
#  * git ls-files: lists files known or related to the git index
#  *   --others        : show untracked files (not in the index)
#  *   --ignored       : restrict output to ignored files only
#  *   --exclude-standard : use the standard ignore sources:
#  *       .gitignore (per-directory), .git/info/exclude, and the
#  *       global gitignore file set via core.excludesFile
#  *
#  * A .gitignore file tells git which files and patterns to skip when
#  * tracking changes. Common uses: build artefacts, editor swap files,
#  * OS metadata (e.g. .DS_Store on macOS), compiled binaries, etc.
#  *
#  * Each matching path is printed on its own line, so piping through
#  * cat -e shows each entry terminated with '$' (end-of-line marker).
#  */
git ls-files --others --ignored --exclude-standard
