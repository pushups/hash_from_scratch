#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hash_table.h"


void debug(ht_hash_table* ht, char* key) {
  printf("key: %s has value %s\n", key, ht_search(ht, key));
}

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

int main() {
  ht_hash_table* ht = ht_new();

  char* key;
  char* value = "test value";

  for (int i = 0; i < 20000; i++) {
    int size = num_digits(i);
    int string_size = size*sizeof(char) + 1;
    key = (char*) malloc(string_size);
    snprintf(key, string_size, "%d", i);
    ht_insert(ht, key, value);
  }

  for (int i=0; i < 20000; i++) {
    int size = num_digits(i);
    int string_size = size*sizeof(char) + 1;
    key = (char*) malloc(string_size);
    snprintf(key, string_size, "%d", i);
    ht_delete(ht, key);
  }
}
