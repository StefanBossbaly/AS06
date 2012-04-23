#define LIMIT 16
#define NC    '\0'
#define BLANK ' '
#define SLASH '/'
#include <stdio.h>

void reduce(RN this) {
}

RN newS(char *S) {
  return newI(0,1);
}

RN newI(int N, int D) {
  RN result = (RN)malloc(sizeof(RN));
  result->N = N;  
  result->D = D;
  return result;
} 

char *toString(RN this) {
  char string[LIMIT];
  sprintf(string, "%d%c%d", Nof(this), SLASH, Dof(this));
  return &string;
}

int Nof(RN this) {
  return this->N;
}

int Dof(RN this) {
  return this->D;
}

void invert(RN this) {
    int temp = this->D;
    this->D = this->N;
    this->N = temp;
}

void add(RN this, RN that) {
}

void subtract(RN this, RN that) {
}

void multiply(RN this, RN that) {
}

void divide(RN this, RN that) {
}

int compareTo(RN this, RN that) {
  int result = 0;
  return result;
}
