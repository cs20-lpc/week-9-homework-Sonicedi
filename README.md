[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/VA6FTQIx)
[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-2e0aaae1b6195c2367325f4f02e2d04e9abb55f0b24a779b69b11b9e10269abc.svg)](https://classroom.github.com/online_ide?assignment_repo_id=21243244&assignment_repo_type=AssignmentRepo)
# Week 9 Homework

## Directions

You will bring the circular array based `Queue` from Week 9 Wed Lab and linked list based `Queue` from Week 9 Mon Lab. You will bring in the completed code from these labs into this repository.

You will implement a factory class that will have a method `GetQueue` that will return a linked list based queue if there is no length parameter specified. Otherwise it will return a Array based queue.

Write a driver program that simulates the two scenarios. Make appropriate decision to use for each of these cases (ArrayBased or Linkedlist based). Make sure to use the factory class to generate the queue.

### Simulation Example 1:

A small ticket counter can serve only a limited number of customers at a time. Customers arrive randomly and form a waiting line. If the line is already full, newly arriving customers cannot join and must leave. The counter serves one customer at a time. Implement the waiting line using a queue data structure. The maximum number of customers that can wait in line is 10. When the queue is full, new arrivals are turned away.

#### To simulate the arrival and service process:

Generate a random number between -1 and 1 a total of 100 times. If the number is negative, remove (dequeue) one element from the queue to represent a customer being served and leaving. If the number is 0 or positive, add (enqueue) a new customer to the queue to represent a new arrival. The actual values stored in the queue are not important.

### Simulation Example 2: Bank Service Line

A busy bank serves customers who arrive randomly throughout the day. Each customer joins the end of the line when they arrive, and the line can grow dynamically as needed. There is no fixed maximum size for the waiting line. Implement the waiting line using a queue data structure.

#### To simulate customer arrivals and departures:

Generate a random number between -1 and 2 a total of 100 times. If the number is negative, remove (dequeue) one element from the queue to represent a customer finishing service. If the number is 0 or positive, add (enqueue) a new customer to the queue to represent an arrival. The actual values added to the queue are not important. 


