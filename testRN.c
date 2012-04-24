#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "RN.h"

#define WHAT '?'
#define QUIT 'Q'
#define READ 'R'
#define PRINT 'P'
#define ADD   '+'
#define SUBTRACT '-'
#define MULTIPLY '*'
#define DIVIDE '/'
#define NUM 'N'
#define DEM 'D'
#define INVERT 'I'
#define COMPARE 'C'

void print(RN this) {
	char buffer[16];
	printf(" %s", toString(buffer, this));
}

void println(RN this) {
	print(this);
	printf("\n");
}

RN read() {
	RN result;
	char input[LIMIT];
	printf(":");
	scanf("%s", input);
	result = newS(input);
	return result;
}

void printWHAT() {
	printf(" Valid Commands are:\n");
	printf("   %c=List Commands, %c=Quit, %c=Read, %c=Print,\n", WHAT, QUIT,
			READ, PRINT);
	printf("   %c=Add, %c=Subtract, %c=Multiply, %c=Divide,\n", ADD, SUBTRACT,
			MULTIPLY, DIVIDE);
	printf("   %c=Invert, %c=Numerator, %c=Denominator, %c=Compare\n", INVERT,
			NUM, DEM, COMPARE);
}

int main() {
	RN X = newI(0, 1);
	RN Y;
	char input[LIMIT];
	int toPrint;
	do {
		toPrint = 1;
		printf("?");
		scanf("%s", input);
		if (input[0] == WHAT) {
			printWHAT();
			toPrint = 0;
		} else if (input[0] == READ) {
			X = read();
		} else if (input[0] == PRINT) {
		} else if (input[0] == ADD) {
			Y = read();
			add(X, Y);
		} else if (input[0] == SUBTRACT) {
			Y = read();
			subtract(X, Y);
		} else if (input[0] == MULTIPLY) {
			Y = read();
			multiply(X, Y);
		} else if (input[0] == DIVIDE) {
			Y = read();
			divide(X, Y);
		} else if (input[0] == NUM) {
			toPrint = 0;
			printf("%d\n", Nof(X));
		} else if (input[0] == DEM) {
			toPrint = 0;
			printf(" %d\n", Dof(X));
		} else if (input[0] == INVERT) {
			invert(X);
		} else if (input[0] == COMPARE) {
			toPrint = 0;
			Y = read();
			printf(" %d\n", compareTo(X, Y));
		} else if (input[0] != QUIT) {
			toPrint = 0;
			printf(" --->UNKNOWN COMMAND\n");
		}
		if ((input[0] != QUIT) && toPrint) {
			println(X);
		}
	} while (input[0] != QUIT);
}

