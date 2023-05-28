echo "Enter limit: "
read n
j=1
echo "The even numbers till $n are:-"
for ((i=1; i<=$n; i++))
do
if test `expr $j % 2` -eq 0
then
echo "$j"
fi
j=`expr $j + 1`
done

