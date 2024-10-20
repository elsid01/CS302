#include "LL.hpp"
#include "LL.cpp"
#include "QuickSort.cpp"
#include <string>
#include <iostream>
using namespace std;



int main()
{
   LL<int> list;
   LL<int>::iterator it;
    int x;
    while(cin >> x) list.push_back(x);
    
    LL<int>::iterator l = list.begin();
    LL<int>::iterator r = --list.end();
    
       QuickSort(list, l, r);
    

        for (it = list.begin(); it != list.end(); ++it)
        {
            cout << *it << " ";
        }
        cout <<endl;


    return 0;
}
