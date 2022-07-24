#!/bin/sh

set _curr_cd=$PWD

# Git clone the current version of the repo to a temp directory
echo "Fetching newest version..."
cd $HOME
git clone -q --depth 1 https://github.com/lxsavage/aipm.git

# Run upgrade script
echo "Running upgrade scripts..."
cd aipm
./upgrade.sh

# Remove local clone of current version
cd $_curr_cd
rm -rf $HOME/aipm
echo "Update complete!"
