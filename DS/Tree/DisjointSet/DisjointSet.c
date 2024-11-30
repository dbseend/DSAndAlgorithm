#include "DisjointSet.h"

void DS_UnionSet(DisjointSet *set1, DisjointSet *set2) {
  set2 = DS_FindSet(set2);

  set2->parent = set1;
}

DisjointSet *DS_FindSet(DisjointSet *set) {
  while (set->parent != NULL) {
    set = set->parent;
  }

  return set;
}

DisjointSet *DS_MakeSet(void *newData) {
  DisjointSet *newNode = (DisjointSet *)malloc(sizeof(DisjointSet));
  newNode->parent = NULL;
  newNode->data = newData;

  return newNode;
}

void DS_DestroySet(DisjointSet *set) { free(set); }