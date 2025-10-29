#!/bin/bash

# ----------- CONFIGURATION -----------
# Replace these with your repo info
read -p "GitHub username: " GITHUB_USER
read -p "Repository name: " REPO_NAME
# Use SSH URL
REPO_URL="git@github.com:$GITHUB_USER/$REPO_NAME.git"
read -p "Branch name (default: main): " BRANCH_NAME
BRANCH_NAME=${BRANCH_NAME:-main}
# ------------------------------------

# Check if we're in a git repo
if [ ! -d ".git" ]; then
    echo "Initializing new Git repository..."
    git init
fi

# Add all files
echo "Adding files..."
git add .

# Commit changes
echo "Committing..."
git commit -m "Initial commit" 2>/dev/null || echo "Nothing to commit"

# Add remote if it doesn't exist
if ! git remote | grep -q origin; then
    echo "Adding remote origin..."
    git remote add origin "$REPO_URL"
fi
# ignore
git add .gitignore
git commit -m "Ignore VSCode config"

# Set branch name
git branch -M "$BRANCH_NAME"

# Push to GitHub
echo "Pushing to GitHub..."
git push -u origin "$BRANCH_NAME"

echo "Done! Your project should now be on GitHub."
