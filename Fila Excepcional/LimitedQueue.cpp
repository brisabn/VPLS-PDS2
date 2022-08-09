#include "LimitedQueue.hpp"
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

int LimitedQueue::get_max_size()
{
  return max_size;
}

LimitedQueue::LimitedQueue()
{
}

LimitedQueue::LimitedQueue(int k)
{
  if (k <= 0)
    throw InvalidSizeException();
  else
    this->max_size = k;
}

void LimitedQueue::push_back(int k)
{
  if (lista.size() >= max_size)
    throw QueueFullException();
  else
    lista.push_back(k);
}

void LimitedQueue::pop_front()
{
  if (lista.empty())
    throw QueueEmptyException();
  else
    lista.pop_front();
}

int LimitedQueue::front()
{
  if (lista.empty())
    throw QueueEmptyException();
  else
    return lista.front();
}

int LimitedQueue::back()
{
  if (lista.empty())
    throw QueueEmptyException();
  else
    return lista.back();
}

int LimitedQueue::find(int k)
{
  int pos = 0;
  int ter = 0;

  if (lista.size() == 0)
    throw QueueEmptyException();
  else
  {
    for (auto it = lista.cbegin(); it != lista.cend(); it++)
    {
      if (*it == k)
      {
        ter = 1;
        return pos;
      }
      pos++;
    }
    if (ter == 0)
      throw ItemNotFoundException();
    return 0;
  }
}

void LimitedQueue::print()
{
  if (lista.size() == 0)
    throw QueueEmptyException();
  else
  {
    for (auto it = lista.cbegin(); it != lista.cend(); it++)
    {
      cout << *it << endl;
    }
  }
}
