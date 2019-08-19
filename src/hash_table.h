typedef struct {
  char* key;
  char* value;
} ht_item;

typedef struct {
  int size;
  int count;
  ht_item** items;
} ht_hash_table;

ht_hash_table* ht_new();
void ht_del_hash_table(ht_hash_table* ht);
int ht_hash(const char *s, const int a, const int m);
int ht_get_hash(const char *s, const int num_buckets, const int attempt);
