#!/bin/sh

#
# upgrade.sh
#
# To use this script, cd into the directory this file is contained
# in, then run it through `./upgrade.sh`.
#
# Author: Logan Savage
#

if ! command -v aipm; then
    sh install.sh
    exit 1
fi

if [ ! -d src ]; then
    echo "Make sure that you are cd'd into the aipm directory"
    exit
fi

echo "Updating..."

make
mv -f ./bin/aipm ~/.local/aipm/aipm

echo "Done!"
