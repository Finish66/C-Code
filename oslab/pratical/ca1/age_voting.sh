#!/bin/bash

read -p "Enter the age of the person: " age
read -p "Enter country(IN or US): " con


if [ $age -ge 18 -a $con == "IN" ]; then
	echo "You are eligible to vote in India"
elif [ $age -ge 18 -a $con == "US" ]; then
	echo "You are eligible to vote in US"
elif [ $age -gt 18 -a $con != "US" -o $con != "IN" ]; then
	echo "Enter Valid country"
else 
	echo "Not eligible less than 18"
fi
