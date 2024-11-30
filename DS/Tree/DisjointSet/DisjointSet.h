#ifndef DISJOINT_SET_H
#define DISJOINT_SET_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tagDisjointSet {
  struct tagDisjointSet *parent;
  void *data;
} DisjointSet;

void DS_UnionSet(DisjointSet *set1, DisjointSet *set2);
DisjointSet *DS_FindSet(DisjointSet *set);
DisjointSet *DS_MakeSet(void *newData);
void DS_DestroySet(DisjointSet *set);

#endif