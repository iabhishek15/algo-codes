#$ echo $((1 + RANDOM % 10))


for ((i = $(( ( RANDOM % 1000 )  + 1 )); ; ++i));do
	echo $i
	./gen $i > int
	#./a < int > out1
	#./brute < int > out2
	#diff -w out1 out2 || break;
	diff -w <(./c < int) <(./brute < int) || break
done
