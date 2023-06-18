echo "enter the number"
read num
while((num!=0))
	do
		rem=$((num%10))
		sum=$((sum+rem))
		num=$((num/10))
	done
echo "sum of digits are $sum"
