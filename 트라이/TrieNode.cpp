#include <iostream>

using namespace std;

const int ALPHABETNUM = 26;

struct TrieNode 
{
    TrieNode() : bTerminal(false) 
    {
        for (int i = 0; i < ALPHABETNUM; ++i) 
        {
            // 각 자식 노드를 초기화
            Children[i] = nullptr;
        }
    }
    ~TrieNode() 
    {
        for (int i = 0; i < ALPHABETNUM; ++i) 
        {
            // 동적할당 된 자식 노드들을 해제
            if (Children[i])
            {
                delete Children[i];
            }
        }
    }

public:
    // 문자열을 트라이에 삽입하는 함수
    void Insert(const char* NextCharacter)
    {
        // 문자열의 끝인 경우
        if (*NextCharacter == 0)
        {
            // 현재 노드를 단어의 끝으로 표시
            this->bTerminal = true;
        }
        else
        {
            // 현재 문자의 인덱스 계산
            int alphabetIndex = ToNumber(*NextCharacter);
            // 자식 노드가 없으면 새로운 노드를 생성
            if (nullptr == Children[alphabetIndex])
            {
                Children[alphabetIndex] = new TrieNode;
            }
            // 다음 문자로 재귀 호출하여 삽입
            Children[alphabetIndex]->Insert(NextCharacter + 1);
        }
    }
    // 주어진 문자열을 트라이에서 찾는 함수
    TrieNode* Find(const char* NextCharacter)
    {
        // 문자열의 끝인 경우
        if (*NextCharacter == 0)
        {
            // 현재 노드가 단어의 끝이라면
            if (this->bTerminal)
            {
                // 단어를 찾은 경우 현재 노드를 반환
                return this;
            }
        }
        else
        {
            // 현재 문자의 인덱스 계산
            int alphabetIndex = ToNumber(*NextCharacter);
            // 자식 노드가 있는지 확인하고 재귀적으로 찾기
            if (nullptr != Children[alphabetIndex])
            {
                return Children[alphabetIndex]->Find(NextCharacter + 1);
            }
        }
        // 해당하는 단어가 없으면 nullptr 반환
        return nullptr;
    }

    void Print(const std::string& prefix = "") const
    {
        for (int i = 0; i < ALPHABETNUM; ++i)
        {
            if (Children[i])
            {
                char nextChar = 'a' + i;

                // 단어의 끝이라면 마지막 문자를 표시
                if (Children[i]->bTerminal)
                {
                    std::cout << prefix << "|" << nextChar << "|" << "\n";
                }
                else
                {
                    std::cout << prefix << nextChar << "\n";
                }

                // 재귀적으로 자식 노드를 출력
                Children[i]->Print(prefix + "  ");
            }
        }
    }

private:
    // 문자를 숫자 인덱스로 변환하는 함수 (소문자 : 'a' ~ 'z')
    int ToNumber(const char character) const
    {
        return (character - 'a');
    }

private:
    // 해당 노드가 단어의 끝인지 여부를 저장하는 변수
    bool bTerminal;
    // 각 알파벳에 해당하는 자식 노드를 가리키는 포인터 배열
    TrieNode* Children[ALPHABETNUM + 1];
};

int main() 
{
    // 문자 집합
    const char* characters[10] = { "bus","bat" ,"bup","tea","top","take","bullet","bad","bed","tall" };
   
    // 찾으려는 문자
    const char* cmpStr = "bus";

    // 트라이 루트 노드 초기화
    TrieNode* TrieDataBase = new TrieNode();

    // 문자열 삽입
    for (int i = 0; i < 10; ++i)
    {
        TrieDataBase->Insert(characters[i]);
    }

    // 트리 출력
    TrieDataBase->Print();

    // 검색
    TrieNode* foundNode = TrieDataBase->Find(cmpStr);
    if (foundNode != nullptr)
    {
        std::cout << cmpStr << " found in Trie!" << std::endl;
    }
    else
    {
        std::cout << cmpStr << " not found in Trie!" << std::endl;
    }

    // 메모리 해제
    delete TrieDataBase;
    
    return 0;
}
