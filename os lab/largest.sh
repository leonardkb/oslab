#!/bin/bash

echo "Enter the limit: "
read limit

echo "Enter the numbers: "
for ((i=0; i<limit; i++))
do
    read ar[$i]
done

for ((i=0; i<limit; i++))
do
    for ((j=0; j<limit; j++))
    do
        if ((${ar[i]}>${ar[j]}))
        then
            temp=${ar[i]}
            ar[$i]=${ar[j]}
            ar[$j]=$temp
        fi
    done
done

echo "Largest number: ${ar[0]}"

