# Set 6a

In this exercise, your task is to study the efficiency of array list and linked list implementations that keep the list sorted when a new element is inserted.

In the array list implementation, the function `array_list_insert` should first find the position for the new element and then move all elements after that position one step to the right to make room for the new element.

In the linked list implementation, the function `linked_list_insert` should first find the position for the new element by iterating through the list from left to right and then insert it by modifying pointers.

## Experiment

This is an experimental task where you should compare the list implementations. For both implementations, insert `n` numbers in random order (where `n` is a sufficiently large number) and measure the time for each implementation.

Use the [Fisher–Yates shuffle algorithm](https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle) and the `rand` function (in the C standard library) for shuffling an array of numbers before inserting the numbers.
