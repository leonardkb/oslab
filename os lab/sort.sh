echo " enter the limit"
read l
echo "enter the numbers"
for((i=0;i<l;i++))
	do
		read ar[$i]
	done
for((i=0;i<l;i++))
	do
		for((j=0;j<l;j++))
			do
				if((${ar[i]}>${ar[j]}))
					then
						temp=${ar[i]}
						ar[$i]=${ar[j]}
						ar[$j]=$temp
					fi
			done
	done
echo "sorted array is:"
for((i=0;i<l;i++))
	do
		echo ${ar[i]}
	done

