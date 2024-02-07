// #include <stdio.h>
// #include "eventQueue.h"

// int main(int argc, char const *argv[])
// {
//     addEvent(SYSTEM_BOOTED_UP);
//     printEventsInQueue();

//     popFront();
//     printEventsInQueue();

//     addEvent(SYSTEM_BOOTED_UP);
//     Event event = getNextEvent();
//     printf("NextEvent: %i\n", event);

//     addEvent(SUBSYSTEM_INITIALIZED);
//     bool isFull = isQueueFull();
//     printf("is queue full: %i\n", isFull);
//     printEventsInQueue();

//     popFront();
//     printEventsInQueue();

//     addEvent(SUBSYSTEM_INITIALIZED);
//     addEvent(SUBSYSTEM_INITIALIZED);
//     addEvent(SUBSYSTEM_INITIALIZED);
//     addEvent(SUBSYSTEM_INITIALIZED);

//     isFull = isQueueFull();
//     printf("is queue full: %i\n", isFull);
//     printEventsInQueue();

//     addEvent(SYSTEM_BOOTED_UP);

//     printEventsInQueue();

//     popFront();
//     printEventsInQueue();
//     addEvent(SYSTEM_BOOTED_UP);
//     printEventsInQueue();
//     return 0;
// }

// ABOVE IS TEST PROGRAM ONE FOR EVENTQUEUE

#include "Statemachine.h"

int main(int argc, char const *argv[]) {
  runStatemachine();
  return 0;
}
