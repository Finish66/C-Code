read a

if [ $a -ge 18 ]; then
	echo "Can Vote as age is ${a}"
elif [ $a -ge 10 ]; then
	echo "Wait na ${a}"
else 
	echo "Get Lost ${a}"
fi
