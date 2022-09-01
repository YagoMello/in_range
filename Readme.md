# in_range
Header-only, C++ > 17\
For C++ programmers who like python's `for i in range(...):`

## Syntax
`for i in range(stop):` => `for(auto i : in_range(stop))`\
`for i in range(start,stop):` => `for(auto i : in_range(start, stop))`\
`for i in range(start, stop, step):` => `for(auto i : in_range(start, stop, step))`

## `in_range<T>(...)`
`T` defaults to `int32_t`, and can be anything that works as a number:
- ints
- unsigned ints
- float
- double
- ...

Technically, T requires:
- Operators > and < (or operator <=>)
- Initializable with 1 and 0 (`T t = 1`)
- Copy constructible

## Installation
Download `in_range.hpp`, place in your project folder and `#include "in_range.hpp"`

## Types
The type of `i` is the same used in the template:
```cpp
for(T i : in_range<T>(...)) 
```


## Examples
Prints 0 1 2 3 4 5 6 7 8 9
```cpp
#include <iostream>
#include "in_range.hpp"

int main() {
  
  for(auto i : in_range(10)) {
    std::cout << i << " ";
  }
  
  return 0;
}
```

Prints 0.4 0.2 -0 -0.2 -0.4 -0.6 -0.8
```cpp
#include <iostream>
#include "in_range.hpp"

int main() {
  
  for(double iter : in_range<double>(0.4, -0.9, -0.2)) {
    std::cout << iter << " ";
  }
  
  return 0;
}
```
