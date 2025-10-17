#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
    //write the operator() required to make this a functor that compares Events by time
    bool operator()(const Event* e1, const Event* e2) const //we're sure we don't change anything
    {
      return ((e1->time)<(e2->time)); //smaller than for min-heap
    }
} EventLess;
	
#endif
