#!/bin/sh

#
# update.sh
#
# To use this script, ensure that an instance of aipm is already installed
# (using it without one will mess up a potential future install, and can be
# tested by simply running `aipm` in a newly-opened terminal), then cd into
# the directory this file is contained in, then run it through
# `sh ./update.sh`.
#
# Author: Logan Savage
# Version 0.2.2
# Date: 2022-03-08
# Copyright (c) 2022 Logan Savage. Some Rights Reserved. See LICENSE.
#

if [ ! -d src ]; then
    echo "Make sure that you are cd'd into the aipm directory"
    exit
fi

echo "Updating..."

make
rm ~/local/aipm/aipm
cp ./bin/aipm ~/.local/aipm/aipm

echo "Done!"
