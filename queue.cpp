#include "queue.h"
#include <stdexcept>

void init(Queue* q) {
    q->front = nullptr;
    q->rear = nullptr;
}

bool isEmpty(const Queue* q) {
    return q->front == nullptr;
}

bool isFull(const Queue* q) {
    return (q->rear != nullptr && (q->rear - q->data) >= MAX - 1);
}

void enqueue(Queue* q, int value) {
    if (isFull(q)) throw std::runtime_error("Queue Full");
    if (isEmpty(q)) {
        q->front = q->data;
        q->rear = q->data;
    } else {
        q->rear++;
    }
    *(q->rear) = value;
}

void dequeue(Queue* q) {
    if (isEmpty(q)) throw std::runtime_error("Queue Empty");
    if (q->front == q->rear) {
        init(q);
    } else {
        q->front++;
    }
}

int front(const Queue* q) {
    if (isEmpty(q)) throw std::runtime_error("Queue Empty");
    return *(q->front);
}