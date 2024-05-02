#!/bin/bash


read a

r=0


while [ $a -gt 0 ]; 
do
	rem=$((a%10))
	r=$((r*10 + rem))
	a=$((a/10))
done

echo $r
