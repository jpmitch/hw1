#include "split.h"
#include <cstddef>
#include <iostream>

using namespace std;

void deleteList(Node** head_ref)
{
 
    /* deref head_ref to get the real head */
    Node* current = *head_ref;
    Node* next = NULL;
 
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
 
    /* deref head_ref to affect the real head back
        in the caller. */
    *head_ref = NULL;
}
void prints(Node* head)
{
    if (head == NULL)
       return;
     
    // If head is not NULL, print current node
    // and recur for remaining list  
    cout << head->value << " ";
 
    prints(head->next);
}
int main()
{
    Node* even = nullptr;
    Node* odd = nullptr;
    Node* ins = new Node{ 1, new Node{2, new Node{3, new Node{4, new Node{5, new Node{ 6, new Node{7, nullptr}} } } } } };
    split(ins, odd, even);
    
    cout << "Even: ";
    prints(even);
    cout << endl;
    cout << "Odd: ";
    prints(odd);
    cout << endl;
    cout << "List: ";
    prints(ins);
    cout << endl;
    deleteList(&ins);
    even = odd = NULL;

    return 0;
}