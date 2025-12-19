# LeetCode
Questions solved by me.

## Search Files by Commit Message

You can search for files in this repository based on commit message keywords using the provided search script.

### Usage

```bash
./search_by_commit.sh <keyword>
```

### Examples

Search for files related to "hash" techniques:
```bash
./search_by_commit.sh hash
```

Search for "Problem of the Day" (POTD) solutions:
```bash
./search_by_commit.sh POTD
```

Search for files using specific techniques like "bit manipulation":
```bash
./search_by_commit.sh "bit mani"
```

Search for files related to dynamic programming:
```bash
./search_by_commit.sh dp
```

### What the script shows

The script will display:
1. All commits that contain the keyword in their commit message
2. Files modified in each of those commits
3. A summary list of all unique files found

This is useful for finding files that use specific algorithms, data structures, or techniques based on how they were documented in commit messages.
