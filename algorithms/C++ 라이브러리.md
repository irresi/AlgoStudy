# C++ 라이브러리

## 정책 기반 자료구조

g++ 에는 있으나 표준 c++에는 존재하지 않음

### ordered set,multiset,map

```C++
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<int,null_type,less_equal<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
typedef tree<pair<int, int>,null_type,less<pair<int, int>>,rb_tree_tag, tree_order_statistics_node_update> ordered_pairset;
/*
ordered_pairset의 second인자를 이용해
ordered_multiset처럼 사용할 수도 있고 map처럼 사용할 수도 있다.
속도는 ordered_multiset이 조금 더 빨랐다.
set의 함수들을 모두 사용할 수 있고
S.find_by_order(k) : k번째 자료의 iterator를 반환(0-based index)
S.order_of_keys(x) : x의 인덱스를 반환, x가 집합에 없다면 집합에 있었을 때 있어야 할 위치 반환
*/
```

같은 크기의 원소를 다룰 때 잘 만들어진 세그먼트 트리 구현보다 3배 정도 ordered_set이 느린 것 같다.

