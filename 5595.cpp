#include <iostream>
using namespace std;

int main()
{
    bool array[30] ={false, };
    
    for(int i=0; i<28; ++i)
    {
        int temp;
        cin >> temp;
        array[temp-1] = true;
    }
    
     for(int i=0; i<30; ++i)
     {
         if(array[i] == false)
         {
             cout << i+1 <<'\n';
         }
     }
    
    return 0;
}
