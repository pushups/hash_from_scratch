#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"

int num_digits(int x) {

  if (x == 0) {
    return 1;
  }
  
  int count = 0;
  while(x != 0) {
    x = x / 10;
    count++;
  }

  return count;
}

char* copy_int_to_string(int i) {
  int size = num_digits(i);
  int string_size = size*sizeof(char) + 1;
  char* str = (char*) malloc(string_size);
  snprintf(str, string_size, "%d", i);
  return str;
}

int main() {
  ht_hash_table* ht = ht_new();

  char* key;
  char* value = "test value";

  int num_items = 2000000;

  printf("Creating: %d keys", num_items);
  for (int i = 0; i < num_items; i++) {
    key = copy_int_to_string(i);
    ht_insert(ht, key, value);
    char* found_val = ht_search(ht, key);
    printf("%s = %s\n", key, found_val);
  }

  printf("Deleting: %d keys", num_items);
  for (int i=0; i < num_items; i++) {
    key = copy_int_to_string(i);
    ht_delete(ht, key);
    char* found_val = ht_search(ht, key);
    printf("%s = %s\n", key, found_val);
  }

  printf("Final count: %d, Final size: %d\n", ht->count, ht->size);

  return 0;
}
