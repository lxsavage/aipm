#!/bin/sh
echo "Updating..."

make
rm ~/local/aipm/aipm
cp ./bin/aipm ~/.local/aipm/aipm

echo "Done!"
