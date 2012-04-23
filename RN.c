#define LIMIT 16
#define NC    '\0'
#define BLANK ' '
#define SLASH '/'

void reduce(RN this) {
}

RN newS(char *S) {
  return newI(0,1);
}

RN newI(int N, int D) {
  RN result = (RN)malloc(sizeof(RN));
  result->N = N;  result->D = D;
  return result;
} 

char *toString(RN this) {
  return NULL;
}

int Nof(RN this) {
  return 0;
}

int Dof(RN this) {
  return 1;
}

void invert(RN this) {
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
