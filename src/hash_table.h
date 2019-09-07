typedef struct {
  char* key;
  char* value;
} ht_item;

typedef struct {
  int size;
  int count;
  int base_size;
  ht_item** items;
} ht_hash_table;

ht_hash_table* ht_new();
ht_hash_table* ht_new_sized(const int base_size);
void ht_del_hash_table(ht_hash_table* ht);
int ht_hash(const char *s, const int a, const int m);
int ht_get_hash(const char *s, const int num_buckets, const int attempt);

void ht_insert(ht_hash_table* ht, const char* key, const char* value);
char* ht_search(ht_hash_table* ht, const char* key);
void ht_delete(ht_hash_table* ht, const char* key);
