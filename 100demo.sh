rm -f meta_test
rm -f stats100

>meta_test
>stats100
for ((j=1;j<500;j+=1)); do
  python3 tester100.py
  export ARG=$(cat test100python)
  ./push_swap $ARG | wc -l | sed -e 's/^[ \t]*//' >> stats100
  echo "$j"
done

count=0;
total=0;
max=0; 
for i in $( awk '{ print $1; }' stats100 )
do
  if (( $i > $max )); then
  max=$i
  fi
  total=$(echo $total+$i | bc )
  ((count++))
done
echo -n "Moyenne : " >> meta_test
echo "scale=2; $total / $count" | bc >> meta_test
echo -n "MAX : " >> meta_test
echo "$max" >> meta_test
cat meta_test
rm -f stats100
rm -f meta_test
