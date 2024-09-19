// bucket array - an array which store value with index as a key.
// hash function
// hash code -  the value which is store in the bucketarray . so basically it mean the convertion of object or variable to code and map it with the array is done by this hash code.
        // ->some important key word:
                // ->indentity function -  it mean that the input given to this function will return the ouput as the same number. in the middle we will convert it in code and use it.
                                    //Ex -  23 -> H.C -> 23
                // ->Uniform distribution
                // ->collision - when we try to access same index.
                // ->collision handling - 
                    // ->open hashing - same place me hi jao. means in a index there are linked for storing mutiple value. which is know as seperate chaining
                    // ->closed Addressing - agli jaga dekh lo yaar. means if a indedx is already filled than  we will search for next empty index.
                                                // Hi(a) = H(a) + (Fi(a)) where is finding the next location
                                    // ->linear probing:   f(i) = i
                                    // ->Quadradic probimg:  f(i) = i^2

// compression function - the main function of this is to make the index lie in the array arrange. for example if the array size is 6 and the number is 12 so we will (%) it with the size of the array than the number will lies between the array range. or we can say that the code from hash code to make it in the range of the array is done by the compression function.

// complexity Analisys :
        // ->Insertion process:O(1)
                // let's suppose n is total number of words
                // let's suppoae k is lenght of the word
                // insertion opeartion is O(k),n>>>>k, which mean k is very samll value compare to n.thus the insertion compl. is O(1).
                // n be the no. of entries and b will be the total box avaiable.
                // load factor - (n / b)
                // we always ensure that (n/b) < 0.7. always.
                // if the value of the n is incresing than we also have to increse the value of b of that it is < 0.7. and the process is know as rehashing.its means that we will increase the size of b by 2 fold and than do the hashing again of all the elements.

        // -> same process for deletion and searching.
