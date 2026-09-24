typedef struct LinkedList LinkedList;

LinkedList* linked_list_create(void);
void linked_list_insert(LinkedList *list, int value);
int linked_list_get(LinkedList *list, int pos);
int linked_list_size(LinkedList *list);
void linked_list_free(LinkedList *list);
