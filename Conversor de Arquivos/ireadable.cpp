#include "ireadable.hpp"

// Imprime um objeto IReadable
ostream &operator<<(ostream &out, IReadable &readable)
{
  readable.print(out);
  return out;
}
