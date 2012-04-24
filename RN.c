#include <stdio.h>
#include "RN.h"

void reduce(RN this) {
    int gcd = GCD(this->N, this->D);
    
    if (gcd == 1 || gcd == -1)
        return;

    this->N = this->N / gcd;
    this->D = this->D / gcd;
}

int LCM(RN this, RN that){
}

int GCD(int num1, int num2){
    int start = (min(num1, num2) + 1) / 2;
    
    for (int i = start; i > 0; i--){
        if ((num1 % i == 0) && (num2 % i == 0))
            return i;
    }

    return -1;
}

int min(int num1, int num2){
    return (num1 > num2) ? num1 : num2;
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
