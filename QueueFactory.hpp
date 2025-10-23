#ifndef QUEUE_FACTORY_HPP
#define QUEUE_FACTORY_HPP

#include "Queue.hpp"
#include "LinkedQueue.hpp"
#include "ArrayQueue.hpp"

// Simple factory: no capacity -> LinkedQueue; with capacity -> ArrayQueue
struct QueueFactory {
    template <typename T>
    static Queue<T>* GetQueue() {
        return new LinkedQueue<T>();
    }
    template <typename T>
    static Queue<T>* GetQueue(int capacity) {
        return new ArrayQueue<T>(capacity);
    }
};

#endif
