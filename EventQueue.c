#include "eventQueue.h"
#include <stdint.h>
#include <stdio.h>

// The event queue.
Event eventQueue[MAX_EVENTS_IN_EVENT_QUEUE] = {EMPTY, EMPTY, EMPTY, EMPTY,
                                               EMPTY};

// cppcheck-suppress unusedFunction
bool isQueueFull() {
  uint8_t counter = 0;

  for (uint8_t i = 0; i < MAX_EVENTS_IN_EVENT_QUEUE; ++i) {
    if (eventQueue[i] != EMPTY) {
      ++counter;
    }
  }

  return counter >= MAX_EVENTS_IN_EVENT_QUEUE;
}

void popFront() {
  eventQueue[0] = EMPTY;

  // place every item one place to the front.
  for (uint8_t i = 1; i < MAX_EVENTS_IN_EVENT_QUEUE; ++i) {
    eventQueue[i - 1] = eventQueue[i];
  }

  eventQueue[MAX_EVENTS_IN_EVENT_QUEUE - 1] = EMPTY;
}

Event getNextEvent() { return eventQueue[0]; }

// cppcheck-suppress unusedFunction
void printEventsInQueue() {
  printf("EventQueue: ");
  for (uint8_t i = 0; i < MAX_EVENTS_IN_EVENT_QUEUE; ++i) {
    printf("%i, ", eventQueue[i]);
  }
  printf("\n");
}

bool addEvent(Event event) {
  for (uint8_t i = 0; i < MAX_EVENTS_IN_EVENT_QUEUE; ++i) {
    if (eventQueue[i] == EMPTY) {
      eventQueue[i] = event;
      return true;
    }
  }

  return false;
}