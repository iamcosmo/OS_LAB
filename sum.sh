echo "Enter a number: "
read num
sum=0
while [ $num -ne 0 ]
do
sum=`expr $num % 10 + $sum`
num=`expr $num / 10`
done
echo "Sum of the digits = $sum"

