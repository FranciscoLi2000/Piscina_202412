#!/bin/sh
# git_commit.sh - Display the last 5 git commit IDs
#
# /*
#  * git log: shows the commit history of a git repository
#  *   --format="%H": output only the full 40-character SHA-1 hash of each commit
#  *   -5: limit output to the last 5 commits
#  *
#  * Git uses SHA-1 hashes to uniquely identify every commit, tree, blob and tag.
#  * A commit hash is a fingerprint of the entire state of the repository at that point,
#  * making it impossible to alter history without changing all subsequent hashes.
#  */
git log --format="%H" -5
