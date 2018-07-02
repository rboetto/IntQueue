/******************************************************************************
Ricardo Boetto 2519915
Assignment 2, Problem 2
I certify that this is my own work
Programming 3 : Summer C w/ Dr. Kianoosh Boroojeni
*******************************************************************************/
#include <stdio.h>

#define MAXSTACK 100

static int stack1[MAXSTACK];
static int stack2[MAXSTACK];

static int stack1length = 0;
static int stack2length = 0;

static void flush (void);

static void
push1 (int entity)
{
  if (stack1length < MAXSTACK)
    {
      stack1[stack1length++] = entity;
    }
  else if (stack2length == 0)	// If queue is flushed while stack 2 is not empty, elements would become disorganized
    {
      flush ();
      stack1[stack1length++] = entity;
    }
  else
    {
      printf ("Queue is full");
    }
}

static int
pop1 (void)
{
  if (stack1length > 0)
    {
      return stack1[--stack1length];
    }
  else
    {
      printf ("Error: Stack 1 is empty");
    }
}

static void
push2 (int entity)
{
  if (stack2length < MAXSTACK)
    {
      stack2[stack2length++] = entity;
    }
  else
    {
      printf ("Error: Stack 2 full");
    }
}

static int
pop2 (void)
{
  if (stack2length > 0)
    {
      return stack2[--stack2length];
    }
  else if (stack1length > 0)
    {
      flush ();
      return stack2[--stack2length];
    }
  else
    {
      printf ("Queue is empty");
    }
}

static void
flush (void)
{
  if (stack2length != 0)
    {
      printf ("Stack 2 must be emptied before it can be flushed");
    }
  else
    {
      int temp;
      while (stack1length > 0 && stack2length < MAXSTACK)
	{
	  temp = pop1 ();
	  push2 (temp);
	}
    }
}

void
enqueue (int entity)
{
  push1 (entity);
}

int
dequeue (void)
{
  if (stack2length == 0)
    {
      flush ();
    }
  if (stack2length > 0)
    {
      return pop2 ();
    }
  else
    {
      printf ("Stack is empty");
    }
}

int
main ()
{
    printf("Instructions didn't say to implement a main");
    return 0;
}
