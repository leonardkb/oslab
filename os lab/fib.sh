echo "entethe number"
read num
a=0
b=1
for((i=0;i<num;i++))
	do
		echo $a
		fib=$((a+b))
		a=$b;
		b=$fib
	done
