#include <iostream>
using namespace std;

int main()
{
    int N,M;
    cin >> N >> M;
    
    int array[101] ={0,0,0};
    
    for(int i=0; i<M; ++i)
    {
        int start,end,num;
        cin >> start >> end >> num;
        for(int j=start-1; j<end; ++j)
        {
            array[j] = num;
        }
    }
    
    for(int i=0; i<N; ++i)
    {
        cout << array[i] <<' ';
    }
    return 0;
}
