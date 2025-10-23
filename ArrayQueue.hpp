#ifndef ARRAY_QUEUE_HPP
#define ARRAY_QUEUE_HPP

#include "Queue.hpp"
#include <iostream>
using namespace std;

template <typename T>
class ArrayQueue : public Queue<T> {
private:
    // an array that contains the elements
    T* buffer;

    // the maximum number of elements in the queue
    int maxSize;

    // the current position of the front element in the queue
    int frontIndex;

    // the current position of the back element in the queue
    int backIndex;

    // copy the values from the argument queue to `this`
    void copy(const ArrayQueue<T>&);

public:
    // constructor with the maximum size as the argument
    ArrayQueue(int = 100);

    // copy constructor
    ArrayQueue(const ArrayQueue<T>&);

    // overloaded assignment operator
    ArrayQueue<T>& operator=(const ArrayQueue<T>&);

    // destructor
    virtual ~ArrayQueue();

    // return the element at the back of the queue
    virtual T back() const override;

    // remove all elements in the queue, resetting to the initial state
    virtual void clear() override;

    // remove the front element from the queue
    virtual void dequeue() override;

    // add the argument to the back of the queue
    virtual void enqueue(const T&) override;

    // return the element at the front of the queue
    virtual T front() const override;

    // return the current length of the queue
    virtual int getLength() const override;

    // return the maximum size of the queue
    int getMaxSize() const;

    // determine if the queue is currently empty
    virtual bool isEmpty() const override;

    // determine if the queue is currently full
    bool isFull() const;
};

#include "ArrayQueue.tpp"
#endif