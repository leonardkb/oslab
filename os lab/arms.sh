#!/bin/bash

echo "Enter a number: "
read num

temp=$num
res=0

while ((num!=0))
do
  rem=$((num%10))
  res=$((res+rem*rem*rem))
  num=$((num/10))
done

if ((res==temp))
then
  echo "Number is an Armstrong number"
else
  echo "Number is not an Armstrong number"
fi

