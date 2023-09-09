//
// Created by Tony Pham on 29/08/2023.
//
#include <iostream>
#include <stdio.h>

using namespace std;

int main() {
  int a = 0x1234560;
  int &b = a;
  int *p = &a;
  char *q = (char *)p;
  printf("%x \n", b);       // 1
  printf("%x\n", &b);       // 2
  printf("%x\n", p);        // 3
  printf("%x\n", *p);       // 4
  printf("%x\n", &p);       // 5
  printf("%x\n", q);        // 6
  printf("%x\n", q + 2);    // 7
  printf("%x\n", *(q + 2)); // 8
  return 0;
}
