#!/bin/bash

read -p "Enter a: " a
read -p "Enter b: " b



echo "1. Addition"
echo "2. Substraction"
echo "3. Multiplication"
echo "4. Division"
read -p "Enter Option (1,2,3,4): " op


case $op in
	1)
		echo "$a + $b = $((a + b))" ;;
	2)
		echo "$a - $b = $((a - b))" ;;
	3)
		echo "$a * $b = $((a * b))" ;;
	4)
		if [ $b -eq 0 ]; then
			echo "Division by 0 Not Valid"
		else
			echo "$a / $b = $((a / b))"
		fi
		;;
	*)
		echo "Choose correct Option"

esac
