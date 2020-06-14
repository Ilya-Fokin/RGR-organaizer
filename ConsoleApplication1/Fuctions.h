#pragma once

#include "Event.h"

void EventEntry(Event* (&d), int& n);
void Print(Event* d, int n);
void EventChange(Event* d, int n);
void Copy(Event* d_n, Event* d_o, int n);
void AddEvent(Event* (&d), int& n);
void DeleteEvent(Event* (&d), int& n);
void SaveEvent(Event* d, int n, string filename);
