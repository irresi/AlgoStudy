g++ D.cpp -o D
g++ D2.cpp -o D2
for((i=1;i<=100;++i)); do
    echo $i
    ./gen $i > int
    ./D <int > out1
    ./D2 < int > out2
    diff -w out1 out2 || break
done