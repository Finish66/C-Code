read -p "Enter table you want: " a

#for i in {1..10}
for ((i=1; i<=10; i++))
do
	echo "$a x $i = $(echo "$i*$a" | bc)"
done



