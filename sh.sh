#!/bin/bash

file="conf-file.txt"

while read -r origin dest; do
	echo "origin: $origin, dest: $dest"
	echo "................"
done < $file
