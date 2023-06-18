echo " enter a number"
read num
f=1
for((i=num;i>0;i--))
do
((f=f*i))
done
echo $f
