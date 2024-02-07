#ifndef EVENT_QUEUE_H__
#define EVENT_QUEUE_H__

#define MAX_EVENTS_IN_EVENT_QUEUE 5

#include "Event.h"
#include <stdbool.h>

/**
 * @brief Checks if the eventQueue is full.
 *
 * @return true is full
 * @return false is not full
 */
bool isQueueFull();

/**
 * @brief removes the first event from the queue, and places all other events
 * one place to the front.
 *
 */
void popFront();

/**
 * @brief Gets the next event from the eventQueue.
 *
 * @return Event The next event in the queue.
 */
Event getNextEvent();

/**
 * @brief prints all the events in the queue. Because it is a enum, it will
 * print the index of the event.
 *
 */
void printEventsInQueue();

/**
 * @brief adds event to queue.
 *
 * @param event
 * @return true Event is added to the queue.
 * @return false The queue is full, and the event is not added to the queue.
 */
bool addEvent(Event event);

#endif // EVENT_QUEUE_H__