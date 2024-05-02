#!/bin/bash

echo "Enter a number A:"
read a

if [ $a -ge 18 ]; then
	echo "Person can vote"
elif [ $a -le 5 ]; then
	echo "Child"
else
	echo "Not eligible"

fi

