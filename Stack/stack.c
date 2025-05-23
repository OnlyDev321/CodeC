#include "stack.h"

static stack s;

void reset()
{
    s.top = EMPTY;
}
void push(char a)
{
    s.top++;
    s.s[s.top] = a;
}
char pop()
{
    return (s.s[s.top--]);
}
char top()
{
    return (s.s[s.top]);
}
bool empty()
{
    return (s.top == EMPTY);
}
bool full()
{
    return (s.top == FULL);
}