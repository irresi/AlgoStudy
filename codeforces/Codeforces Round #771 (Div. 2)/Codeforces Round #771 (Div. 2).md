
 

# [Codeforces Round #771 (Div. 2)](https://codeforces.com/contest/1638)

## A Reverse

i번째에 i가 나오지 않는 위치를 l로 정하고 그 뒤에 l이 등장하는 위치를 r로 정하고

reverse 한 뒤 출력

## B. Odd Swap Sort

i<j이고 $a_i<a_j$인데 $a_i$와 $a_j$의 parity가 같으면 어떻게 해서든 $a_i$가 $a_j$보다 앞에 있다.

따라서 배열 a에 홀수가 오름차순 정렬되어 있고 짝수가 오름차순 정렬되어 있다면 yes

아니면 no

## C.  Inversion Graph

$a_1, \cdots, a_k$가 1부터 k까지의 순열일 때 $a_{k+1},\cdots,a_n$은 k보다 큰 수로 이루어졌다.

따라서 edge가 형성되어 있지 않다. 이를 이용해 $a_k$의 mex가 k+1인 수들의 개수를 세면 된다.

## D. Big Brush

마지막에 칠하는 사각형은 다른 색에 가려지지 않고 온전하다. 칠한 순서 거꾸로 추적하면서 구한다.

이 때 마지막에  (r,c)을 선택하여 (r,c)~(r+1,c+1)을 칠했다면 이에 가려지는 사각형은 (r-1,c-1)~(r+1,c+1)을 선택하는 경우이다. 이 사각형에 의해 가려진 사각형들의 후보를 q에 넣어 bfs를 하는 것처럼 색칠을 해 나간다. 

## E. Colorful Operations

add 할 때 전체 구간에 특정 색깔에 x만큼 더해라라는 것으로 {색 : 더할값}이라는 맵을 lazy배열로 만들었다.
그리고 query나 color를 할 때 lazy를 push하면서 처리하는 방식으로 짰다.

map을 사용해서 메모리와 시간 초과가 났다.

