## TrieNode 구조체 설명
각 노드는 알파벳 26개에 대한 자식 노드 포인터 배열을 가지고 있으며, 단어의 끝인지 여부를 나타내는 bTerminal 변수를 포함

</br>

### 생성자
모든 자식 노드를 nullptr로 초기화하고, bTerminal을 false로 설정

</br>

### 소멸자
할당된 자식 노드들이 있으면, 소멸자에서 메모리 해제

</br>

### Insert 함수
- 트라이에 문자열을 삽입
- 문자열의 각 문자를 처리하며 자식 노드가 없으면 새로 생성하고, 재귀적으로 다음 문자로 이동해 삽입
- 문자열의 끝에 도달하면 해당 노드를 단어의 끝으로 표시

</br>

### Find 함수
- 주어진 문자열을 트라이에서 찾는다.
- 문자열의 각 문자를 처리하며 재귀적으로 자식 노드를 탐색
- 문자열의 끝에 도달하면 해당 노드가 단어의 끝인지 확인하고, 맞으면 해당 노드를 반환, 아니면 nullptr을 반환

</br>

### ToNumber 함수
- 문자를 숫자 인덱스로 변환하여 자식 배열의 인덱스로 사용

</br>

## Trie를 사용하여 문자열 탐색한 결과
```cpp
 // 문자 집합
 const char* characters[10] = { "bus","bat" ,"bup","tea","top","take","bullet","bad","bed","tall" };
 // 찾으려는 문자
 const char* cmpStr = "bus";
```
![image](https://github.com/user-attachments/assets/69c9a63a-8ab2-443a-abdb-c80ada67aad5)
