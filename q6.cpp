#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void heapifyDown(int i) {
        int smallest = i;
        int l = left(i), r = right(i);

        if (l < heap.size() && heap[l] < heap[smallest])
            smallest = l;
        if (r < heap.size() && heap[r] < heap[smallest])
            smallest = r;

        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    int top() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        return heap[0];
    }

    void pop() {
        if (heap.empty()) throw runtime_error("Heap is empty");
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }

    bool empty() {
        return heap.empty();
    }
};

int main() {
    MinHeap pq;
    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(3);

    cout << "Top element: " << pq.top() << endl; // 3

    pq.pop();
    cout << "Top element after pop: " << pq.top() << endl; // 5

    return 0;
}
