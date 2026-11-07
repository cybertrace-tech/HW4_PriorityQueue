#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <vector>
#include <stdexcept>

class PriorityQueue {
private:
    std::vector<int> heap;  // 1-indexed; heap[0] unused

    int parent(int i)     { return i / 2; }
    int leftChild(int i)  { return 2 * i; }
    int rightChild(int i) { return 2 * i + 1; }

    void percolateUp(int i);
    void percolateDown(int i);

public:
    PriorityQueue();

    bool isEmpty() const;
    int size() const;

    void insert(int value);
    int deleteMin();
    int peekMin() const;

    void printArray() const;
};

#endif