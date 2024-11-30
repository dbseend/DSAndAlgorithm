#include "DisjointSet.h"

int main(void) {
  char a = 'a', b = 'n', c = 'c', d = 'd', e = 'e', f = 'f', g = 'g';
  DisjointSet *set1 = DS_MakeSet(&a);
  DisjointSet *set2 = DS_MakeSet(&b);
  DisjointSet *set3 = DS_MakeSet(&c);
  DisjointSet *set4 = DS_MakeSet(&d);
  DisjointSet *set5 = DS_MakeSet(&e);
  DisjointSet *set6 = DS_MakeSet(&f);
  DisjointSet *set7 = DS_MakeSet(&g);

  DS_UnionSet(set1, set2);
  DS_UnionSet(set1, set3);

  DS_UnionSet(set4, set5);
  DS_UnionSet(set4, set6);
  DS_UnionSet(set4, set7);

  DS_UnionSet(set1,set4);

  return 0;
}
