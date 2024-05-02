res1=$(expr 3 + 5)
echo "Result = $res1"


res2=$(echo "5.5 + 3.2" | bc)
echo "Result : $res2"


res3=$(echo "3 + 4" | bc)
echo "Result: $res3"


