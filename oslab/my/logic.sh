read -p "Enter a: " a
read -p "Enter b: " b

if [ $a -gt 5 -a $b -gt 9 ]; then
	echo "Both $a $b"
fi

if [ $a -gt 5 -o $b -gt 9 ]; then 
	echo "Any one $a $b"
fi
