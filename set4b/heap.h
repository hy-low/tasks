typedef struct Heap Heap;

Heap* heap_create(void);
void heap_push(Heap *heap, int value);
void heap_pop(Heap *heap);
int heap_top(Heap *heap);
int heap_size(Heap *heap);
void heap_free(Heap *heap);
