#include <iostream>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    
    int array[101] ={0, };
    
    for(int i=0; i<N; ++i)
    {
        array[i] = i+1;
    }
    
    for(int i=0; i<M; ++i)
    {
        int a,b;
        cin >> a >>b;
        int temp = array[a-1];
        array[a-1] = array[b-1];
        array[b-1] = temp;
    }
    
    for(int i=0; i<N; ++i)
    {
        cout << array[i] <<' ';
    }
    
    
    return 0;
}
