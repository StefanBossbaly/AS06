#define LIMIT 16
#define NC    '\0'
#define BLANK ' '
#define SLASH '/'
#include <stdio.h>

void reduce(RN this) {
}

RN newS(char *S) {
  RN result = (RN) malloc(sizeof(RN));
  int i = 0, j = 0;
  sscanf(S, "%d/%d", &i, &j);
  result->N = i;
  result->D = j;
  
  //Reduce the RN before we return it
  reduce(result);
  
  return result;
}

RN newI(int N, int D) {
  RN result = (RN) malloc(sizeof(RN));
  result->N = N;  
  result->D = D;
  
  //Reduce the RN before we return it
  reduce(result);
  
  return result;
} 

char *toString(char *buffer, RN this) {
  sprintf(buffer, "%d%c%d", Nof(this), SLASH, Dof(this));
  return buffer;
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
