#!/bin/bash

OS=$(uname)

if [ $OS == "Darwin" ]
then
	checker='./checker_Mac'
fi

if [ $OS == "Linux" ]
then
	checker="./checker_linux"
fi

list()
{
	LIST=$(perl -e "use List::Util 'shuffle'; my @out = (shuffle 0..$1)[0..$1];
		print \"@out\"")
	ARG=$LIST
}

test()
{
	MAX=0
	for (( i=1; i<=$2; i++ ))
	do
		echo
		list $1
		echo $ARG
		./push_swap $ARG > test.txt
		WCL=$(wc -l < "test.txt")
		if [ "$WCL" -ge "$MAX" ]
		then
			MAX=$WCL
		fi
		cat test.txt | $checker $ARG
		rm test.txt
	done
	echo
	echo "Nombre Max d'Opérations: $MAX"
}

echo
echo "Test pour 3 valeurs"
test 2 25

echo
echo "Test pour 5 valeurs"
test 4 25

echo
echo "Test pour 100 valeurs"
test 99 25

echo
echo "Test pour 500 valeurs"
test 499 25

echo
echo "Test des valeurs en erreur"
echo "1 2 3 6 4 a"
./push_swap "a 1 2 3 5 6"
echo "a 1 2 3 5 6"
./push_swap "1 2 3 4 A"
echo "1 2 3 4 A"
./push_swap "A"
echo "A"
./push_swap "1 2 3 4 2147483647"
echo "1 2 3 4 2147483647"
./push_swap "1 2 3 4 2147483648"
echo "1 2 3 4 2147483648"
./push_swap "1 2 3 4 -2147483647"
echo "1 2 3 4 -2147483647"
./push_swap "1 2 3 4 -2147483648"
echo "1 2 3 4 -2147483648"
./push_swap "1 2 3 4 -2147483649"
echo "1 2 3 4 -2147483649"
./push_swap "1 2 3 4 -2147483649"
echo "1 2 3 1"
./push_swap "1 2 3 1"
echo "1 2 1 3"
./push_swap "1 2 1 3"
echo "3 2 1 1"
./push_swap "3 2 1 1"
echo "1 1 2 3"
./push_swap "1 1 2 3"
echo "2 1 1 4"
./push_swap "2 1 1 4"
