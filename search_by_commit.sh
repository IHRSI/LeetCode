#!/bin/bash

# Script to search files in the repository based on commit message keywords
# Usage: ./search_by_commit.sh <keyword>

if [ $# -eq 0 ]; then
    echo "Usage: $0 <keyword>"
    echo "Example: $0 hash"
    echo "Example: $0 POTD"
    echo "Example: $0 'bit mani'"
    exit 1
fi

KEYWORD="$1"

echo "Searching for files with commit messages containing: '$KEYWORD'"
echo "================================================================"
echo ""

# Get all commits that match the keyword
COMMITS=$(git log --all --oneline --grep="$KEYWORD" -i)

if [ -z "$COMMITS" ]; then
    echo "No commits found with keyword: '$KEYWORD'"
    exit 0
fi

echo "Found commits:"
echo "$COMMITS"
echo ""
echo "Files modified in these commits:"
echo "================================"

# For each commit that matches, show the files changed
git log --all --grep="$KEYWORD" -i --name-only --pretty=format:"%h %s" | grep -v '^$' | while read -r line; do
    # Check if this is a commit line (starts with hash)
    if [[ $line =~ ^[0-9a-f]{7}\ .* ]]; then
        echo ""
        echo "Commit: $line"
    else
        echo "  - $line"
    fi
done

echo ""
echo ""
echo "Summary of unique files:"
echo "========================"

# Get unique list of files
git log --all --grep="$KEYWORD" -i --name-only --pretty=format:"" | grep -v '^$' | sort -u
