/* Rational Numbers Program
   Author: Stefan Bossbaly
   Description: This program provides subroutines that mutate rational numbers
   Compile using: gcc --std=c99 testRN.c RN.c -o RN.o
   
   Explanations for changes
   (1) The char* toString(RM *this) subroutine was changed to char *toString(char *buffer, RN *this).
   It is a normal c convention to have the client program provide the allocated space to save any sort
   of data that will live past the scope of the subprogram. This helps with memory leaks.
   
   (2) RN was changed from a pointer to a struct. This does not change the way the program functions
   however it makes it clear that we are passing an address to the subroutines and not pushing the values
   contained by RN onto the runtime stack. This is a normal C convention and will also help when writing
   the assembly language port of this program.
   
   (3) I added free calls where needed in the test program. I confirmed that there are no leaks using an
   opensource program called Valgrind. Here is the output ....
   
   ==2857== HEAP SUMMARY:
   ==2857==     in use at exit: 0 bytes in 0 blocks
   ==2857==   total heap usage: 17 allocs, 17 frees, 2,120 bytes allocated
   ==2857== 
   ==2857== All heap blocks were freed -- no leaks are possible
*/

#define LIMIT 16
#define NC    '\0'
#define BLANK ' '
#define SLASH '/'

//Rational Numbers
typedef struct {
	int N;
	int D;
} RN;

//Constructors
RN *newS(char *string);
RN *newI(int numerator, int denominator);

//Sort of private (because the represetation is always reduced)
static void reduce(RN *this);
static void normalize(RN *this);

//Other private functions
static int GCD(int num1, int num2);
static int LCM(int num1, int num2);

//Math helper functions
static inline int min(int num1, int num2);

//Accessors
char *toString(char *buffer, RN *this);
int Nof(RN *this);
int Dof(RN *this);

//Mutators
void invert(RN *this);
void add(RN *this, RN *that);
void subtract(RN *this, RN *that);
void multiply(RN *this, RN *that);
void divide(RN *this, RN *that);

//Conventional
int compareTo(RN *this, RN *that);

