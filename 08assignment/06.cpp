#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

class MaxHeapPQ {
private:
    vector<int> heap;

    void siftUp(int idx) {
        while (idx > 0) {
            int parent = (idx - 1) / 2;
            if (heap[parent] < heap[idx]) {
                swap(heap[parent], heap[idx]);
                idx = parent;
            } else break;
        }
    }

    void siftDown(int idx) {
        int n = heap.size();
        while (true) {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int largest = idx;

            if (left < n && heap[left] > heap[largest])
                largest = left;

            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != idx) {
                swap(heap[idx], heap[largest]);
                idx = largest;
            } else break;
        }
    }

public:
    MaxHeapPQ() {}

    bool empty() {
        return heap.empty();
    }

    int size() {
        return heap.size();
    }

    int top() {
        if (heap.empty()) throw runtime_error("Priority queue is empty");
        return heap[0];
    }

    void push(int val) {
        heap.push_back(val);
        siftUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) throw runtime_error("Priority queue is empty");

        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty())
            siftDown(0);
    }

    void printHeap() {
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    MaxHeapPQ pq;

    pq.push(10);
    pq.push(40);
    pq.push(5);
    pq.push(20);
    pq.push(1);

    cout << "Heap elements: ";
    pq.printHeap();

    cout << "Top = " << pq.top() << endl;

    pq.pop();
    cout << "Top after pop = " << pq.top() << endl;

    return 0;
}
