//
//  LL.h
//  cs302Assignment1
//
//  Created by Ely Mbaye on 9/2/24.
//

#include <cstdlib>

#ifndef LL_H
#define LL_H

template <typename type>
class LL
{
private:
    struct node
    {
        type data;
        node * prev;
        node * next;
    };
    
    node * dummy;
    
public:
    class iterator
    {
    private:
        node * current;
        
    public:
        friend class LL;
        iterator() : current(nullptr) {}
        iterator(node * x) : current(x) {}
        
        type operator*() const { return current->data; }
        
        iterator operator++(int)
        {
            iterator i(*this);
            current = current->next;
            return i;
        }
        
        iterator operator++()
        {
            current = current->next;
            return *this;
        }
        
        iterator operator--(int)
        {
            iterator i(*this);
            current = current->prev;
            return i;
        }
        iterator operator--()
        {
            current = current->prev;
            return *this;
        }
        
        bool operator==(const iterator& rhs) const
        {
            return current == rhs.current;
        }
        
        bool operator!=(const iterator& rhs) const
        {
            return current != rhs.current;
        }
    };
    
    LL();
    LL(const LL<type>&);
    const LL<type>& operator=(const LL<type>&);
    ~LL();
    
    void push_front(const type&);
    void pop_front();
    void push_back(const type&);
    void pop_back();
    
    bool isEmpty() const
    {
        return dummy->next == nullptr && dummy->prev == nullptr;
    }
    
    iterator begin() const
    {
        return iterator(!dummy->next ? dummy : dummy->next);
    }
    
    iterator end() const { return iterator(dummy); }
    
    void removeAtPosition(iterator&);
    void swapNodes(iterator&, iterator&);
    void Quicksort(LL<type>& list , iterator l, iterator r);
    iterator Partition(LL<type>& list, iterator l, iterator r);
};
#endif
    
//    void Quicksort(iterator l, iterator r)
//        {
//            if (l != r && l != --iterator(r))
//            {
//                iterator p = Partition(l, r);
//                Quicksort(l, --p);
//                Quicksort(++p, r);
//            }
//        }
//
//        iterator Partition(iterator l, iterator r)
//        {
//            auto pivot = *l;
//            iterator i = ++iterator(l);
//            iterator j = r;
//
//            while (true)
//            {
//                while (i != r && *i <= pivot)
//                    ++i;
//
//                while (j != l && *j > pivot)
//                    --j;
//
//                if (i == j || j == --iterator(i))
//                    break;
//
//                swapNodes(i, j);
//            }
//
//            swapNodes(l, j);
//            return j;
//        }
//    };
//    iterator Partition(LL<type>& list, iterator l, iterator r)
//    {
//        auto pivot = l;
//        auto i = l;
//        i++;
//        auto h = i;
//        auto j = r;
//        auto k = j;
//        
//        bool crossed = false;
//        
//        while(crossed)
//        {
//            if(i.current <= pivot.current) ++i;
//            else h = i;
//            if(j.current > pivot.current) --j;
//            else k = j;
//            if(i == h && j == k)
//            {
//                list.swapNodes(i, j);
//                ++i;
//                --j;
//            }
//            
//            if(j == --i)
//            {
//                crossed = true;
//            }
//            
//         list.swapNodes(i, j);
//
//        }
//        
//        list.swapNodes(l, j);
//        
//        return j;
//    };
//    
//    void QuickSort(LL<type>& list, iterator l, iterator r)
//    {
//        if(l != r && r == --l)
//        {
//            auto p = Partition(list, l, r);
//            QuickSort(list, l, --p);
//            QuickSort(list, ++p, r);
//        }
//    };
//    




