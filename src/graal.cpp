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

  int count = 0;
  while (first_iterator < last_iterator)
  {
    //swap(*first_iterator, *last_iterator);
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
}

const void *find_if(const void *first, const void *last, size_t size, Predicate p)
{
}

const void *find(const void *first, const void *last, size_t size, const void *value, Equal eq)
{
}

bool all_of(const void *first, const void *last, size_t size, Predicate p)
{
  return false;
}

bool any_of(const void *first, const void *last, size_t size, Predicate p)
{
  return false;
}

bool none_of(const void *first, const void *last, size_t size, Predicate p)
{
  return false;
}

bool equal(const void *first1, const void *last1, const void *first2, size_t size, Equal eq)
{
  return false;
}

bool equal(const void *first1, const void *last1, const void *first2, const void *last2, size_t size, Equal eq)
{
  return false;
}

void *unique(void *first, void *last, size_t size, Equal eq)
{
}

void *partition(void *first, void *last, size_t size, Predicate p)
{
}

void qsort(void *ptr, std::size_t count, size_t size, Equal eq)
{
}
} // namespace graal
