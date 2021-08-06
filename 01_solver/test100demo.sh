rm -f meta_test
rm -f stats100

>meta_test
>stats100
for ((j=1;j<100;j+=1)); do
  python3 -c """
import random
import os

l = random.sample(range(-2147483648, 2147483647), 100)
random.shuffle(l)
mon_fichier = open('test100python', 'w')
mon_fichier.write(' '.join(map(str, l)))
mon_fichier.close()
  """
  export ARG=$(cat test100python)
  ./push_swap $ARG | wc -l | sed -e 's/^[ \t]*//' >> stats100
  echo "$j"
done

count=0;
total=0;
max=0; 
min=99999999999; 
for i in $( awk '{ print $1; }' stats100 )
do
  if (( $i > $max )); then
  max=$i
  fi
  if (( $i < $min )); then
  min=$i
  fi
  total=$(echo $total+$i | bc )
  ((count++))
done
echo -n "Moyenne : " >> meta_test
echo "scale=2; $total / $count" | bc >> meta_test
echo -n "MAX : " >> meta_test
echo "$max" >> meta_test
echo -n "MIN : " >> meta_test
echo "$min" >> meta_test
cat meta_test
rm -f stats100
rm -f meta_test
rm -f test100python
