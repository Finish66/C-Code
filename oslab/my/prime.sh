#!/bin/bash


read a

p="true"

for((i=2; i<a/2; i++))
do
	if [ $((a$i)) -eq 0 ]; then
		 p="false"
		 break
	fi
done

if [ $p == "true" ]; then
	echo "$a is a prime"
else
	echo "$a is not a prime"
fi
