#Write a shell script to reverse an array without using any inbuilt function?

#!/bin/bash

# Initialize an array
arr=("apple" "banana" "cherry" "date" "elderberry")

# Print the original array
echo "Original array:"
for i in "${arr[@]}"; do
    echo "$i"
done

# Reverse the array
for ((i=${#arr[@]}-1; i>=0; i--)); do
    rev_arr[$(( ${#rev_arr[@]} ))]=${arr[$i]}
done

# Print the reversed array
echo "Reversed array:"
for i in "${rev_arr[@]}"; do
    echo "$i"
done
