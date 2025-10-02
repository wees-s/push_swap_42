# push_swap

An efficient sorting algorithm using two stacks and a limited set of operations as part of the 42 School curriculum.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Operations](#operations)
- [Algorithm](#algorithm)
- [Project Structure](#project-structure)
- [Compilation](#compilation)
- [Testing](#testing)
- [Performance](#performance)
- [Author](#author)

## Description

`push_swap` is a sorting algorithm project where you must sort a list of random integers using two stacks (a and b) with a limited set of operations. The challenge is to sort the numbers using the **minimum number of moves possible**. This project teaches algorithm optimization, data structure manipulation, and computational complexity analysis.

The goal is to sort stack a in ascending order with the least number of operations, where all numbers start in stack a and stack b is initially empty.

## Features

- ✅ Sorts any list of integers efficiently
- ✅ Optimized algorithm for different input sizes
- ✅ Handles edge cases (duplicates, already sorted, reverse sorted)
- ✅ Memory-safe implementation with no leaks
- ✅ Error handling for invalid inputs
- ✅ Outputs the sequence of operations to sort the stack

## Installation

1. Clone the repository:
```bash
git clone git@github.com:wees-s/push_swap_42.git
cd push_swap_42
```

2. Compile the project:
```bash
make
```

This will create the `push_swap` executable (and `checker` if bonus is implemented).

## Usage

### Basic Usage

```bash
./push_swap [list of integers]
```

Example:
```bash
./push_swap 3 2 5 1 4
```

Output (sequence of operations):
```
pb
pb
sa
pa
pa
```

### With Random Numbers

```bash
# Generate 100 random numbers
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | wc -l

# Test with specific range
./push_swap 42 8 15 16 23 4
```

## Operations

The algorithm can only use the following operations:

### Swap Operations
| Operation | Description | Effect |
|-----------|-------------|--------|
| `sa` | Swap a | Swap the first 2 elements at the top of stack a |
| `sb` | Swap b | Swap the first 2 elements at the top of stack b |

### Push Operations
| Operation | Description | Effect |
|-----------|-------------|--------|
| `pa` | Push a | Take the first element at the top of b and put it at the top of a |
| `pb` | Push b | Take the first element at the top of a and put it at the top of b |

### Rotate Operations
| Operation | Description | Effect |
|-----------|-------------|--------|
| `ra` | Rotate a | Shift up all elements of stack a by 1 (first becomes last) |
| `rb` | Rotate b | Shift up all elements of stack b by 1 |

### Reverse Rotate Operations
| Operation | Description | Effect |
|-----------|-------------|--------|
| `rra` | Reverse rotate a | Shift down all elements of stack a by 1 (last becomes first) |
| `rrb` | Reverse rotate b | Shift down all elements of stack b by 1 |

## Algorithm

The implementation uses an **optimized sorting strategy** that adapts based on input size:

### Small Stack (≤ 3 elements)
- **Direct sorting**: Uses hardcoded optimal solutions
- **Operations**: 0-2 moves maximum

### Medium Stack (4-5 elements)
- **Simple algorithm**: Push smaller elements to stack b, sort stack a, push back
- **Operations**: ~12 moves average

### Large Stack (> 5 elements)
- **Chunk/Partition method**: Divides the stack into chunks
- **Two-phase approach**:
  1. **Push phase**: Push elements from stack a to stack b in chunks
  2. **Return phase**: Push elements back to stack a in optimal order
- **Optimization**: Uses cost calculation to minimize moves

### Algorithm Pseudocode

```
1. If size <= 3: use direct sorting
2. If size <= 5: use simple algorithm
3. For larger stacks:
   a. Calculate chunk size based on stack size
   b. Push elements to stack b in chunks (sorted ranges)
   c. While stack b is not empty:
      - Calculate cost to move each element from b to a
      - Choose the element with lowest cost
      - Execute optimal moves
   d. Final rotation to align smallest element at top
```

## Project Structure

```
push_swap/
├── src/
│   ├── push_swap.c           # Main program
│   ├── operations/
│   │   ├── push.c           # Push operations (pa, pb)
│   │   ├── swap.c           # Swap operations (sa, sb, ss)
│   │   ├── rotate.c         # Rotate operations (ra, rb, rr)
│   │   └── reverse_rotate.c # Reverse rotate (rra, rrb, rrr)
│   ├── parsing/
│   │   ├── input_validation.c  # Validate and parse input
│   │   └── error_handling.c    # Error management
│   ├── algorithm/
│   │   ├── small_sort.c     # Sorting for 2-5 elements
│   │   ├── large_sort.c     # Main sorting algorithm
│   │   ├── cost_calculation.c  # Calculate move costs
│   │   └── optimization.c   # Move optimization
│   └── utils/
│       ├── stack_utils.c    # Stack manipulation utilities
│       ├── list_utils.c     # Linked list operations
│       └── ft_atoi.c        # String to integer conversion
├── includes/
│   └── push_swap.h          # Header with prototypes and structs
├── Makefile                 # Compilation rules
└── README.md               # This file
```

## Compilation

The project uses a Makefile with the following targets:

- `make` or `make all`: Compiles the push_swap program
- `make clean`: Removes object files
- `make fclean`: Removes object files and executables
- `make re`: Performs fclean followed by all

### Compilation Flags

```
-Wall -Wextra -Werror
```

## Testing

### Manual Testing

```bash
# Test with 3 numbers
./push_swap 2 1 3

# Test with 5 numbers
./push_swap 5 4 3 2 1

# Test with 100 random numbers
ARG=$(seq 1 100 | shuf); ./push_swap $ARG | wc -l
```

### Performance Benchmarks

Expected maximum number of operations:

| Stack Size | Operations | Grade |
|------------|-----------|-------|
| 3 elements | ≤ 3 | ✓ |
| 5 elements | ≤ 12 | ✓ |
| 100 elements | ≤ 700 | 5 points |
| 100 elements | ≤ 900 | 4 points |
| 100 elements | ≤ 1100 | 3 points |
| 100 elements | ≤ 1300 | 2 points |
| 100 elements | ≤ 1500 | 1 point |
| 500 elements | ≤ 5500 | 5 points |
| 500 elements | ≤ 7000 | 4 points |
| 500 elements | ≤ 8500 | 3 points |
| 500 elements | ≤ 10000 | 2 points |
| 500 elements | ≤ 11500 | 1 point |

### Test Script

```bash
#!/bin/bash

# Test with different sizes
for size in 3 5 10 50 100 500; do
    echo "Testing with $size numbers:"
    total=0
    iterations=10
    
    for i in $(seq 1 $iterations); do
        ARG=$(seq 1 $size | shuf)
        moves=$(./push_swap $ARG | wc -l)
        total=$((total + moves))
    done
    
    average=$((total / iterations))
    echo "Average moves: $average"
    echo "---"
done
```

### Error Handling Tests

```bash
# Test with duplicates (should error)
./push_swap 1 2 3 2

# Test with non-numeric input (should error)
./push_swap 1 2 abc 3

# Test with overflow (should error)
./push_swap 1 2147483648

# Test with empty input (should do nothing)
./push_swap

# Test with invalid format
./push_swap "1 2 3" 4  # Mixed formats
```

## Performance

### Time Complexity
- **Best case**: O(n) - already sorted
- **Average case**: O(n²) to O(n log n) depending on algorithm
- **Worst case**: O(n²)

### Space Complexity
- O(n) for storing the stacks

### Optimization Techniques
1. **Chunk-based sorting**: Reduces operations by grouping elements
2. **Cost calculation**: Chooses most efficient moves
3. **Pre-indexing**: Converts values to indices for easier manipulation

## Author

**wedos-sa** - Cadet at 42 São Paulo

---

*This project demonstrates algorithm design, optimization techniques, and the importance of computational efficiency in solving sorting problems with constraints.*
