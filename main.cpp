#include "QueueFactory.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Avoid throwing on empty during “service”
template <typename Q>
inline void safeDequeue(Q* q, int& servicedCount) {
    if (!q->isEmpty()) {
        q->dequeue();
        ++servicedCount;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // -------- Simulation 1: Ticket Counter (Array-based, capacity 10) --------
    Queue<int>* ticketLine = QueueFactory::GetQueue<int>(10); // ArrayQueue<int>(10)

    int steps1 = 100;
    int turnedAway = 0;
    int arrivals1 = 0, services1 = 0;
    int minLen1 = 0, maxLen1 = 0;

    for (int i = 0; i < steps1; ++i) {
        int r = (rand() % 3) - 1; // -1, 0, 1
        if (r < 0) {
            // service one customer
            safeDequeue(ticketLine, services1);
        } else {
            // arrival
            try {
                ticketLine->enqueue(1);
                ++arrivals1;
            } catch (string&) {
                // queue full -> turned away
                ++turnedAway;
            }
        }
        int len = ticketLine->getLength();
        if (i == 0) { minLen1 = maxLen1 = len; }
        if (len < minLen1) minLen1 = len;
        if (len > maxLen1) maxLen1 = len;
    }

    cout << "Simulation 1 - Ticket Counter (ArrayQueue, capacity 10)\n";
    cout << "  Total arrivals accepted: " << arrivals1 << "\n";
    cout << "  Total arrivals turned away (full): " << turnedAway << "\n";
    cout << "  Total services completed: " << services1 << "\n";
    cout << "  Final line length: " << ticketLine->getLength() << "\n";
    cout << "  Min length observed: " << minLen1 << "\n";
    cout << "  Max length observed: " << maxLen1 << "\n\n";

    // -------- Simulation 2: Bank Service Line (Linked-list, unbounded) -------
    Queue<int>* bankLine = QueueFactory::GetQueue<int>(); // LinkedQueue<int>()

    int steps2 = 100;
    int arrivals2 = 0, services2 = 0;
    int minLen2 = 0, maxLen2 = 0;

    for (int i = 0; i < steps2; ++i) {
        int r = (rand() % 4) - 1; // -1, 0, 1, 2
        if (r < 0) {
            // service one customer
            safeDequeue(bankLine, services2);
        } else {
            // arrival
            bankLine->enqueue(1);
            ++arrivals2;
        }
        int len = bankLine->getLength();
        if (i == 0) { minLen2 = maxLen2 = len; }
        if (len < minLen2) minLen2 = len;
        if (len > maxLen2) maxLen2 = len;
    }

    cout << "Simulation 2 - Bank Service Line (LinkedQueue, unbounded)\n";
    cout << "  Total arrivals accepted: " << arrivals2 << "\n";
    cout << "  Total services completed: " << services2 << "\n";
    cout << "  Final line length: " << bankLine->getLength() << "\n";
    cout << "  Min length observed: " << minLen2 << "\n";
    cout << "  Max length observed: " << maxLen2 << "\n";

    // Cleanup
    delete ticketLine;
    delete bankLine;
    return 0;
}