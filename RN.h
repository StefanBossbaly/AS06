#define LIMIT 16
#define NC    '\0'
#define BLANK ' '
#define SLASH '/'

// Rational Numbers

typedef struct RNS {
	int N;
	int D;
}*RN;

//Constructors

RN newS(char *S);
RN newI(int N, int D);

//Sort of private (because the represetation is always reduced)
void reduce(RN this);
int GCD(int num1, int num2);

//Accessors
char *toString(char *buffer, RN this);
int Nof(RN this);
int Dof(RN this);

//Mutators
void invert(RN this);
void add(RN this, RN that);
void subtract(RN this, RN that);
void multiply(RN this, RN that);
void divide(RN this, RN that);

//Conventional
int compareTo(RN this, RN that);

