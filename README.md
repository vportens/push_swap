## Push_swap
Give the algo a list to sort as argument, and it will sort it using specific move on two stack.
The objectif is to do the minimun move possible.  
Print all the move to sort on the terminal.  
For sort you are allowed 4 type of move :  
|move name| what it does|
|--|--|
|sa| swap the two first element of lst a|
|sb| swap the two first element of lst b|
|ss| do sa && sb|
|pa| push the first element of lst b at the top of lst a|
|pb| push the first element of lst a at the top of lst b|
|ra| rotate each element of the lst a upward, the first element became the last|
|rb| rotate each element of the lst b upward, the first element beacame the last|
|rr| ra && rb|
|rra| rotate each element of the lst a downward, the last element became the first|
|rrb| rotate each element of the lst b downward, the last element became the first|
|rrr| rra && rrb|  

# Execution
Push_swap sorter  
```make && ./push_swap arg1 arg2 ... argn```
Push_swap checker  
```make bonus && ./checker arg1 arg2 ... argn```  

# Algo use
For the Project I use three type of algo,  
**First algo**
Sort a list of three element, 
Using only the stack a, you only need two move to sort it.  

**Second algo**
Up to 8 to 12 element, I push all element in stack b till I go three elem in a, then I push back element from b in a in a way the element will be.

**Third algo**
Up to 500 element, this one is more complexe.  
I replace the number by their place in a sort list (ex : 24 - 12 - 2 become : 3 - 2 - 1)
Then, for each element of list a, I will check how much ra, rra, rb, rrb it's need to be push and sort revers in lst b.  
Then I compare :  
```ra > rb``` and take the bigest number here name **r_move** 
```rra > rrb``` and take the bigest number here name **rr_move**
```ra + rrb > rb + rra``` and take the lowest number here name **both_move**
**I set the minimun move to the lowest number between r_move - rr_move - both_move**   
It's will be the minimun move to do to push the element and make it be reverse sort in b,  
**note** : (If you have 10 ra to do and 12 rb it's the same as 10 rr and 2 rb)
Repeat it along all the number in the lst a,
Then I push the element with the minimun move to make in all list a,
And reapete that till I do not have element in lst a, push back all element from b to a and put the first element to the top.
