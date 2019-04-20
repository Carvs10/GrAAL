#include "../include/graal.hpp"

namespace graal
{
const void *min(const void *first, const void *last, size_t size, Compare cmp)
{
  const byte *first_iterator = (const byte *)first;
  const void *smaller = first_iterator;

  while (first_iterator != last)
  {
    if (cmp(first_iterator, smaller))
    {
      smaller = first_iterator;
    }
    first_iterator += size;
  }

  return smaller;
}

void reverse(void *first, void *last, size_t size)
{
  byte *first_iterator = (byte *)first;
  byte *last_iterator = (byte *)last;

  last_iterator -= size;

  while (first_iterator < last_iterator)
  {
    byte temp = *first_iterator;
    *first_iterator = *last_iterator;
    *last_iterator = temp;

    first_iterator += size;
    last_iterator -= size;
  }
}

void *copy(const void *first, const void *last, const void *d_first, size_t size)
{
  const byte *first_iterator = (const byte *)first;
  byte *new_array_iterator = (byte *)d_first;

  while (first_iterator != last)
  {
    *new_array_iterator = *first_iterator;

    first_iterator += size;
    new_array_iterator += size;
  }

  return new_array_iterator;
}

void *clone(const void *first, const void *last, size_t size)
{
  const byte *first_iterator = (const byte *)first;
  const byte *last_iterator = (const byte *)last;

  int quantity = (last_iterator - first_iterator) / size;
  const void *new_first = calloc(quantity, size);

  byte *new_it = (byte *)new_first;

  while (first_iterator != last_iterator)
  {
    *new_it = *first_iterator;

    first_iterator += size;
    new_it += size;
  }

  return (byte *)new_first;
}

const void *find_if(const void *first, const void *last, size_t size, Predicate p)
{
  const byte *first_iterator = (const byte *)first;

  while (first_iterator != last)
  {
    if (p(first_iterator))
    {
      return first_iterator;
    }

    first_iterator += size;
  }

  return first_iterator;
}

const void *find(const void *first, const void *last, size_t size, const void *value, Equal eq)
{
  const byte *first_iterator = (const byte *)first;

  while (first_iterator != last)
  {
    if (eq(first_iterator, value))
    {
      return first_iterator;
    }

    first_iterator += size;
  }

  return first_iterator;
}

bool all_of(const void *first, const void *last, size_t size, Predicate p)
{
  const byte *first_iterator = (const byte *)first;

  while (first_iterator != last)
  {
    if (!p(first_iterator))
    {
      return false;
    }
    first_iterator += size;
  }

  return true;
}

bool any_of(const void *first, const void *last, size_t size, Predicate p)
{
  const byte *first_iterator = (const byte *)first;

  while (first_iterator != last)
  {
    if (p(first_iterator))
    {
      return true;
    }
    first_iterator += size;
  }

  return false;
}

bool none_of(const void *first, const void *last, size_t size, Predicate p)
{
  const byte *first_iterator = (const byte *)first;

  while (first_iterator != last)
  {
    if (p(first_iterator))
    {
      return false;
    }
    first_iterator += size;
  }

  return true;
}

bool equal(const void *first1, const void *last1, const void *first2, size_t size, Equal eq)
{
  const byte *first1_iterator = (const byte *)first1;
  const byte *first2_iterator = (const byte *)first2;

  while (first1_iterator != last1)
  {
    if (!eq(first1_iterator, first2_iterator))
    {
      return false;
    }

    first1_iterator += size;
    first2_iterator += size;
  }
  return true;
}

bool equal(const void *first1, const void *last1, const void *first2, const void *last2, size_t size, Equal eq)
{
  const byte *first1_iterator = (const byte *)first1;
  const byte *first2_iterator = (const byte *)first2;

  while (first1_iterator != last1)
  {
    if (!eq(first1_iterator, first2_iterator))
    {
      return false;
    }

    first1_iterator += size;
    first2_iterator += size;
  }
  return true;
}

void *unique(void *first, void *last, size_t size, Equal eq)
{
  byte *first_iterator = (byte *)first;
  byte *slow_iterator = first_iterator;

  while (first_iterator != last)
  {
    byte *u_first_it = (byte *)first;
    while (u_first_it != slow_iterator)
    {
      if (eq(u_first_it, first_iterator))
      {
        break;
      }

      u_first_it += size;
    }

    if (u_first_it == slow_iterator)
    {
      byte temp = *u_first_it;
      *u_first_it = *first_iterator;
      *first_iterator = temp;

      slow_iterator += size;
    }

    first_iterator += size;
  }

  return slow_iterator;
}

void *partition(void *first, void *last, size_t size, Predicate p)
{
  byte *first_iterator = (byte *)first;
  byte *fast_iterator;

  while (first_iterator != last)
  {
    if (!p(first_iterator))
    {
      fast_iterator = first_iterator + size;
      while (fast_iterator != last)
      {
        if (p(fast_iterator))
        {
          byte temp = *first_iterator;
          *first_iterator = *fast_iterator;
          *fast_iterator = temp;
          break;
        }

        fast_iterator += size;
      }

      if (fast_iterator == last)
      {
        return first_iterator;
      }
    }

    first_iterator += size;
  }

  return first_iterator;
}

void qsort(void *first, size_t distance, size_t size, Compare cmp)
{
  size_t length = distance * size;

  byte *first_iterator = (byte *)first;
  byte *last = first_iterator + length;

  while (first_iterator != last)
  {
    const void *min = graal::min(first_iterator, last, size, cmp);

    byte temp = *((byte *)min);
    *((byte *)min) = *first_iterator;
    *first_iterator = temp;

    first_iterator += size;
  }
}
} // namespace graal
