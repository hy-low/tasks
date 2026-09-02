typedef struct Tree Tree;

Tree* tree_create(void);
void tree_insert(Tree *tree, int value);
void tree_remove(Tree *tree, int value);
int tree_check(Tree *tree, int value);
int* tree_min(Tree *tree);
int* tree_max(Tree *tree);
int* tree_find(Tree *tree, int value);
int tree_size(Tree *tree);
void tree_free(Tree *tree);
