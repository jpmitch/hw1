

#include "split.h"
#include <cstddef>

void split(Node*& in, Node*& odds, Node*& evens)
{
  
  Node* temp = in;
  in = nullptr; 
  if( temp == nullptr){ 
    return;
  }
  else if (temp->value % 2 == 0) { //even
    evens = temp;
    split(temp->next, odds, evens->next);
  }
  else{ //odd
    odds = temp;
    split(temp->next, odds->next, evens);
  }
}

