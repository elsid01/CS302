/*
Name: Ely Sidibe
NSHE ID: 2002305081
Section: 1001
Assignment: 1
Description: implementing a linked list
*/

/************************************************************************************/

#include "LL.hpp"

template <class type>
LL<type>::LL()
{
    dummy = new node; // assign dummy to a new node

    // Assigning both dummy's pointer to null shows that the list is empty
    dummy->next = dummy;
    dummy->prev = dummy;
}

/*
The deep copy method will copy an existing list to the
to the linked list
*/
template <class type>
LL<type>::LL(const LL<type>& copy)
{
    // reset the list
    dummy = new node; // assign dummy to a new node

    // Assigning both dummy's pointer to null shows that the list is empty
    dummy->next = dummy;
    dummy->prev = dummy;

    
    // loop through copy and push nodes to list

    for(auto it = copy.begin(); it != copy.end(); it++)
    {
        push_back(*it);
    }
    
}

/*
This overloading method will check if the list in parameter
has the cotent as the linked list. if not, it will erase the
content and add the new list to the linked list.
*/
template <class type>
const LL<type>& LL<type>::operator=(const LL<type>& rhs)
{
    //check for self assignment
    if (this != &rhs)
    {
        // clear the list
        // while (isEmpty())
        // {
        //     pop_front();
        // }
        for(auto it = this->begin(); it != this->end(); it++)
        {
            pop_front();
        }
        
        //Loop through the list to be copied and push_back in the linked list
        for(auto it = rhs.begin(); it != rhs.end(); it++)
        {
            push_back(*it);
        }
        
    }
    // Return the linked list
    return *this;
}

/*
The destructor will erase the content of the linked list
and deallocates dummy node
*/
template <class type>
LL<type>::~LL()
{
    // Check first if the list is empty
    for(auto it = this->begin(); it != this->end(); it++)
    {
        pop_back();
    }


    // Deallocate dummy
    delete dummy;
    
}
/*
push back is a method that inserts a new
by adding it at the front. Its return type is void and
its parameter is called "item" which represents the data that
each node will carry
*/
template <class type>
void LL<type>::push_front(const type& item)
{
    //create a temperary node called temp
    node* temp = new node();

    // assign data field of temp to item
    temp->data = item;

    // connect the temp node to the rest of the list
    temp->next = dummy->next;
    temp->prev = dummy;
    dummy->next->prev = temp;
    dummy->next = temp;
}

/*
pop_front is a method that will remove the first node
of the list. Its return type is void. And it has no
parameter;
*/
template <class type>
void LL<type>::pop_front()
{
    // Case1: the list is empty
    if(isEmpty()) return; // don't remove anything

    //Case2: when the list has one or more nodes

    node* temp = dummy->next; // assign the node to remove to temp;

    dummy->next = temp->next; // dummy's next should point to the node that follows temp

    temp->next->prev = dummy; // and that node should point back to dummy

    // deallocate the temp
    delete temp;

}

/*
push_back will insert a node front the back
of the list. This method returns nothing back
but carries a parameter tha will represent the
data field of the node to be added
*/
template <class type>
void LL<type>::push_back(const type& item)
{
    //create a temperary node called temp
    node* temp = new node();

    // assign data field of temp to item
    temp->data = item;

    // connect the temp node to the rest of the list
    temp->prev = dummy->prev;
    temp->next = dummy;
    dummy->prev->next = temp;
    dummy->prev = temp;
}

/*
pop_back dont return anything and don't have
a parameter. The method will remove nodes from
the back of the list
*/
template <class type>
void LL<type>::pop_back()
{
    // Case1: the list is empty
    if(isEmpty()) return; // don't remove anything

    //Case2: when the list has one or more nodes
    node* temp = dummy->prev; // assign the last node to temp

    dummy->prev = temp->prev; // connect dummy to the node before temp

    temp->prev->next = dummy; // that node point back to dummy

    // Deallocate temp
    delete temp;
    
}

template <class type>
void LL<type>::removeAtPosition(iterator& i)
{
// if the iterator is pointing to dummy, list is empty
 if(i == end())
 {
    return; // Don't remove
 }
 //assign the node to remove to temp
 node* temp = i.current;
 
 node* tempN = temp->next;
 node* tempP = temp->prev;
 // Reconnect the rest of the list
 tempN->prev = temp->prev;
 tempP->next = temp->next;
 
 // Deallocate
 delete temp;
 
 i.current = tempN;
 

}



template <class type>
void LL<type>::swapNodes(iterator& i, iterator& j)
{
if(i == end() || j == end())
{
    return;
}

// assign the nodes to swap to temparary nodes

node* tempI = i.current;
node* tempJ = j.current;

// If the two nodes are next to each other
if(tempI->next == tempJ) // here i comes first
{
    // do the wapping
    tempI->prev->next = tempJ;
    tempI->next = tempJ->next;
    tempJ->next->prev = tempI;
    tempJ->next = tempI;
    tempJ->prev = tempI->prev;
    tempI->prev = tempJ;
}
else if(tempJ->next == tempI) // here j comes first
{
    //do the swap
    tempJ->prev->next = tempI;
    tempJ->next = tempI->next;
    tempI->next->prev = tempJ;
    tempI->next = tempJ;
    tempI->prev = tempJ->prev;
    tempJ->prev = tempI;
}
else // here the two nodes are not next to each other
{

// Temparary assignments
node* tempPrevI = tempI->prev;
node* tempNextI = tempI->next;

node* tempPrevJ = tempJ->prev;
node* tempNextJ = tempJ->next;

// Do the swapping

// swap i
tempI->prev = tempPrevJ;
tempI->next = tempNextJ;
tempPrevJ->next = tempI;
tempNextJ->prev = tempI;

// swap j

tempJ->prev = tempPrevI;
tempJ->next = tempNextI;
tempPrevI->next = tempJ;
tempNextI->prev = tempJ;


}

j.current = tempI;
i.current = tempJ;

}
