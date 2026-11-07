#include "PriorityQueue.h"
#include <iostream>

// Constructor
PriorityQueue::PriorityQueue() {
    heap.push_back(0);  // Index 0 is unused
}

// Check if heap is empty
bool PriorityQueue::isEmpty() const {
    return heap.size() == 1;
}

// Return number of elements
int PriorityQueue::size() const {
    return static_cast<int>(heap.size()) - 1;
}

// Insert a new value
void PriorityQueue::insert(int value) {
    heap.push_back(value);

    // Restore the min-heap property
    percolateUp(size());
}

// Move the inserted value upward
void PriorityQueue::percolateUp(int i) {
    while (i > 1 && heap[i] < heap[parent(i)]) {

        // Swap child with parent
        std::swap(heap[i], heap[parent(i)]);

        // Move to parent's position
        i = parent(i);
    }
}

// Delete and return the minimum value
int PriorityQueue::deleteMin() {
    if (isEmpty()) {
        throw std::underflow_error("Priority Queue is empty!");
    }

    int minimum = heap[1];

    // Move the last element to the root
    heap[1] = heap.back();

    // Remove the last element
    heap.pop_back();

    // Restore heap property if elements remain
    if (!isEmpty()) {
        percolateDown(1);
    }

    return minimum;
}

// Move a value downward
void PriorityQueue::percolateDown(int i) {

    while (leftChild(i) <= size()) {

        int smallerChild = leftChild(i);

        // Find the smaller of the two children
        if (rightChild(i) <= size() &&
            heap[rightChild(i)] < heap[leftChild(i)]) {

            smallerChild = rightChild(i);
        }

        // Stop if parent is already smaller
        if (heap[i] <= heap[smallerChild]) {
            break;
        }

        // Swap parent with smaller child
        std::swap(heap[i], heap[smallerChild]);

        // Continue downward
        i = smallerChild;
    }
}

// Return minimum without deleting it
int PriorityQueue::peekMin() const {
    if (isEmpty()) {
        throw std::underflow_error("Priority Queue is empty!");
    }

    return heap[1];
}

// Print the array representation
void PriorityQueue::printArray() const {

    if (isEmpty()) {
        std::cout << "Priority Queue is empty!\n";
        return;
    }

    std::cout << "Heap array: ";

    for (int i = 1; i < static_cast<int>(heap.size()); i++) {
        std::cout << heap[i] << " ";
    }

    std::cout << std::endl;
}