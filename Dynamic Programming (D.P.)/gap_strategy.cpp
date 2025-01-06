// INTRODUCTION:
// Gap Buffer is a data structure for the dynamic insertion and deletion of elements in a buffer or an array. It represents a buffer or an array as a gap surrounded by two pointers, one pointing to the beginning of the buffer and the other pointing to the end. When elements are inserted or deleted, the gap is moved to accommodate the change, instead of resizing the entire buffer.

// Gap Buffer is designed to be an efficient data structure for real-time applications, such as text editors and code editors, where fast and dynamic insertion and deletion of elements are important. The gap buffer data structure provides an average time complexity of O(1) for inserting elements at the current cursor position, making it a suitable choice for applications that require low latency.

// In addition to its efficiency and real-time capabilities, Gap Buffer is also a space-efficient data structure, as it uses a gap to represent empty space in the buffer, minimizing the number of memory reallocations required for insertions and deletions. The Gap Buffer data structure is relatively simple to implement, making it a popular choice for a wide range of applications.

// Gap Buffer is a data structure used for editing and storing text in an efficient manner that is being currently edited. It is also similar to an array but a gap is introduced in the array for handling multiple changes at the cursor. Let’s assume a gap to be another array that contains empty spaces. 

// Example: Consider an example with initial gap size 10, initially, array or gap are of the same size, as we insert the elements in the array similarly elements will be inserted in the gap buffer, the only difference is gap size reduces on each insert. 

// This was the basic case to insert the character in the front. Now, whenever there is need to insert a character at certain position we will just move the gap up-to that position using left() and right() then try to insert the character.

// Need for Gap Buffer
// Array is a data structure which stores items at contiguous memory location. However, it takes O(1) insertion at end of the array while O(n) time in front because the array will be shifted n places right, n being the length of the array.
// When it comes to text editors we need a faster data structure for insertion, modification as there are multiple changes at the cursor positions.
// In worst case array will take O(n) time for insertion or modification as shown in the example below.
// For inserting ‘GEEKS’ at the front, space is made for inserting each character by shifting the array. 

// Basic operations in Gap Buffer
// insert(): It is a procedure used to insert character into the text at a given position. It first checks whether the gap is empty or not, if it finds that the gap is empty it calls procedure grow() and resizes the gap and now the element can be inserted.
// left() : It is a procedure used for moving the cursor to left and this cursor point is used as position for changes. 
 

// right: It is a procedure used for moving the cursor to right and this cursor point is used as position for changes. 

// grow: It is a procedure used when the gap size has become zero and therefore we need to resize the array by inserting a gap at desired position. 

// Gap Buffer vs Ropes
// Now, although its insertion is taking O(1) time but there is another function grow() which  takes approximately O(n) time. So there might a thought that this may take the same time as the rope data structures but the cost of grow is being compensated by amortized cost of other cheaper procedures such as left(), right() and insert(). Therefore this data structure get preferences in text-editors over other such as rope as it is easy to implement.