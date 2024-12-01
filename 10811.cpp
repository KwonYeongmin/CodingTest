#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int N, M;
    int array[101] = { 0, };
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        array[i] = i + 1;
    }

    for (int i = 0; i < M; ++i)
    {
        int start, end;
        cin >> start >> end;

        // 역순으로 뒤집기
        int left = start - 1;
        int right = end - 1;
        while (left < right) 
        {
            int temp = array[left];
            array[left] = array[right];
            array[right] = temp;
            ++left;
            --right;
        }
    }
    
    for (int i = 0; i < N; ++i)
    {
        cout << array[i] << ' ';
    }

    return 0;
}
