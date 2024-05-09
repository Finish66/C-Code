result = $(expr 5 + 3);
result = $(echo "5.5 + 3" | bc);
echo $result;

-eq, -ne, -gt, -lt, -ge, -le
-a (and), -o (or), ! (not)


if []; then

elif []; then

else 


case variable in
    pattern1)
        command1
        ;;
    pattern2)
        command2
        ;;
    pattern3|pattern4)
        command3
        ;;
    *)
        command4
        ;;
esac



for i in 1 2 3 4 5
do
    echo "i is $i"
done


count=1
while [ $count -le 5 ]
do
    echo "Count: $count"
    ((count++))
done


#!/bin/bash

# Exercise 1: Calculate the sum of numbers from 1 to a user-provided value
sum=0
read -p "Enter a number: " num
for (( i=1; i<=$num; i++ )); do
    (( sum += i ))
done
echo "Sum of numbers from 1 to $num: $sum"

# Exercise 2: Generate the Fibonacci series up to a specified number of terms
read -p "Enter the number of terms in the Fibonacci series: " terms
a=0
b=1
echo "Fibonacci series up to $terms terms:"
for (( i=1; i<=terms; i++ )); do
    echo -n "$a "
    temp=$(( a + b ))
    a=$b
    b=$temp
done
echo

# Exercise 3: Check whether a user-input number is prime or not
read -p "Enter a number to check for prime: " prime_num
is_prime=true
if (( prime_num <= 1 )); then
    is_prime=false
else
    for (( i=2; i<=prime_num/2; i++ )); do
        if (( prime_num % i == 0 )); then
            is_prime=false
            break
        fi
    done
fi
if $is_prime; then
    echo "$prime_num is prime."
else
    echo "$prime_num is not prime."
fi

# Exercise 4: Reverse a given number
read -p "Enter a number to reverse: " input_num
reversed_num=""
while (( input_num > 0 )); do
    digit=$(( input_num % 10 ))
    reversed_num="${reversed_num}${digit}"
    input_num=$(( input_num / 10 ))
done
echo "Reversed number: $reversed_num"

# Exercise 5: Display all files in a directory
echo "Files in the current directory:"
for file in *; do
    echo "$file"
done

# Exercise 6: Username and password authentication
valid_user="username"
valid_pass="password"
read -p "Enter username: " user
read -s -p "Enter password: " pass
echo
if [[ $user == $valid_user && $pass == $valid_pass ]]; then
    echo "Access granted."
else
    echo "Access denied."
fi

# Exercise 7: Menu-driven calculator
while true; do
    echo "Menu:"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Exit"
    read -p "Enter your choice: " choice
    case $choice in
        1)
            read -p "Enter first number: " num1
            read -p "Enter second number: " num2
            echo "Result: $((num1 + num2))"
            ;;
        2)
            read -p "Enter first number: " num1
            read -p "Enter second number: " num2
            echo "Result: $((num1 - num2))"
            ;;
        3)
            read -p "Enter first number: " num1
            read -p "Enter second number: " num2
            echo "Result: $((num1 * num2))"
            ;;
        4)
            read -p "Enter dividend: " num1
            read -p "Enter divisor: " num2
            if (( num2 == 0 )); then
                echo "Error: Division by zero!"
            else
                echo "Result: $((num1 / num2))"
            fi
            ;;
        5)
            echo "Exiting..."
            exit 0
            ;;
        *)
            echo "Invalid choice!"
            ;;
    esac
done
