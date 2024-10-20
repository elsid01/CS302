
#include "LL.hpp"
#include <iostream>
using namespace std;


// template <class type>
// typename LL<type>::iterator Partition(LL<type>& list, typename LL<type>::iterator l, typename LL<type>::iterator r)
// {
//     type pivot = *l;
//     auto i = l;
//     i++;
//     auto j = r;
//     bool crossed = false;
// 
//     while (!crossed)
//     {
//         bool moved = false;
//         
//         if(*i <= pivot)
//         {
//             if(i == j)
//             {
//                 crossed = true;
//             }
//             i++;
//             moved = true;
//         }
//         
//         if(*j > pivot)
//         {
//             if(i == j)
//             {
//                 crossed = true;
//             }
//             j--;
//             moved = true;
//         }
//         
//         if(moved == false)
//         {
//             auto temp = i;
//             if(++temp == j || i == j)
//             {
//                 crossed = true;
//             }
//             list.swapNodes(i, j);
// 
//             if(i == r)
//             {
//                 r = j;
//             }
//             if(j == l)
//             {
//                 l = i;
//             }
//             i++;
//             j--;    
//         }
//         
//         // auto k = j;
//         // auto h = i;
//         // 
//         // if(k == --h)
//         // {
//         //     crossed = true;
//         // }
// 
//     }
// 
// 
//     return j;
// }
// 
// template <class type>
// void QuickSort(LL<type>& list, typename LL<int>::iterator l, typename LL<int>::iterator r)
// {
//     
//     if (l != r )
//     {
//      LL<int>::iterator p = Partition(list, l, r);
//      LL<int>::iterator pPrev = p;
//      pPrev--;
//      LL<int>::iterator pNext = p;
//      pNext++;
//      list.swapNodes(l,p);
//      if(l == r)
//      {
//        r = p;
//      }
//     if(p != l)
//     {
//      QuickSort(list, l, pPrev);
//     }
//        if(p !=r )
//     {
//      QuickSort(list, pNext, r);
//     }
//     }
//       
// }

LL<int>::iterator Partition(LL<int>& list, LL<int>::iterator& l, LL<int>::iterator& r)
{

    //Set pivot
    LL<int>::iterator pivot = l;

    //Set i and j, i = l + 1, j = r
    LL<int>::iterator i = l;
    i++;
    LL<int>::iterator j = r;
    LL<int>::iterator k = i;
    k--;
    bool swapped = k == j; //used to check if the iterators are crossed


    //While i and j haven't crossed, or while i's previous is not j
    while(!swapped)
    {
        bool iterShifted = false; //used to check if an iterator moved

        //Check to see if i <= pivot then if j > pivot and move accordingly
        if(*i <= *pivot)
        {
            if(i == j) //check cross
            {
                swapped = true;
            }
            i++;
            iterShifted = true;
        }
        if(*j > *pivot)
        {
            if(i == j) //check cross
            {
                swapped = true;
            }
            j--;
            iterShifted = true;
        }
 
        //Check if i and j didn't move, swap them
        if(!iterShifted)
        {
            LL<int>::iterator temp = i;
            if(++temp == j || i == j) //check cross
            {
                swapped = true;
            }
            list.swapNodes(i, j); //swap


            //If the starting ideces are being changed, then change those as well so that they are on the correct side
            if(i == r)
            {
                r = j;
            }
            if(j == l)
            {
                l = i;
            }

            //Increment, i++, j--
            i++;
            j--;
        }
    }

    return j;
}



void QuickSort(LL<int> list, LL<int>::iterator& l, LL<int>::iterator& r)
{
    //Check to make sure l and r are not the same
    if(l != r)
    {
        //Get result of partition
        LL<int>::iterator p = Partition(list, l, r);

        //Swap
        list.swapNodes(l, p);

        if(l == r) //move r to the correct spot if needed
        {
            r = p;
        }

        LL<int>::iterator pPrev = p;
        pPrev--;
        LL<int>::iterator pNext = p;
        pNext++;

        if(p != l) //if p == l, then there's no need to quicksort
        {
            QuickSort(list, l, pPrev);
        }
        if(p != r) //see above
        {
            QuickSort(list, pNext, r);
        }

        return;
    }

}
