# Seg-fault0 GarbageCollector

A simple garbage collector for C that automatically tracks and frees dynamically allocated memory. This garbage collector uses a linked list to keep track of all allocated memory blocks and ensures they are freed when no longer needed.

## Features
- **Automatic Memory Tracking**: Tracks every memory allocation made using `malloc_GC`.
- **Memory Cleanup**: Frees all tracked memory with a single call to `free_all_GC`.
- **Linked List Implementation**: The garbage collector uses a linked list to manage memory blocks, making it easy to track and release memory.

## Functions

### `malloc_GC`

- The fuctions allocates memory like malloc does
```c
void *malloc_GC(size_t size);
````

### `free_all_GC`
- This Function is called at the exit
```c
void free_all_GC(void);
```