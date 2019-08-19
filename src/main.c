#include <stdio.h>
#include "hash_table.h"

int main() {
  ht_hash_table* ht = ht_new();
  ht_del_hash_table(ht);
  const char* s = "alphabetsoup";

  for (int attempt = 1; attempt < 10; attempt++) {
    int bucket_val = ht_get_hash(s, 53, attempt);
    printf("bucket for %s = %d attempt = %d\n", s, bucket_val, attempt);
  }
}
