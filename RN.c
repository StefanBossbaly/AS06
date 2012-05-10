//Rational Numbers Program
//Author: Stefan Bossbaly
//See RH.h for write up

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include "RN.h"

static void normalize(RN *this) {
    //Normalize the negative sign
    if (this->N < 0 && this->D < 0) {
		this->D = abs(this->D);
		this->N = abs(this->N);
	} else if (this->N >= 0 && this->D < 0) {
		this->D = abs(this->D);
		this->N = this->N * -1;
    }
    
    //reduce the fraction
    reduce(this);
}

static void reduce(RN *this) {
	//get the greatest common denominator
	int gcd = GCD(this->N, this->D);

	//if the gcd is equal to 1 or -1 we don't need to divide
	if (gcd == 1 || gcd == -1)
		return;

	//divide both the numerator and denominator by the gcd to reduce
	this->N = this->N / gcd;
	this->D = this->D / gcd;
}

static int LCM(int num1, int num2) {
	//TODO implement a better algorithm then this atrocity
	return (num1 * num2);
}

static int GCD(int num1, int num2) {
    //If the numbers are equal their values are the GCD
    if (num1 == num2)
        return num1;
    
	int start = (min(num1, num2) + 1) / 2;

	for (int i = start; i > 0; i--) {
		if ((num1 % i == 0) && (num2 % i == 0))
			return i;
	}
    
    //Should never happen (under normal parameters)
	return -1;
}

int min(int num1, int num2) {
	return (num1 > num2) ? num1 : num2;
}

RN *newS(char *string) {
	int n = 0, d = 0;
	sscanf(string, "%d/%d", &n, &d);
	
	return newI(n, d);
}

RN *newI(int numerator, int denominator) {
    //No divide by zero
    assert(denominator != 0);
    
    //Get a pointer to a block of memory on the heap
	RN *result = (RN *) malloc(sizeof(RN));
	
	//If the pointer is null the allocation failed
	//Alert the user and exit the program
	if (result == NULL) {
		printf("Error allocating memory");
		exit(1);
	}
	
	//Set the vars in the struct
	result->N = numerator;
	result->D = denominator;

	//Normalize the RN before we return it
	normalize(result);

	return result;
}

char *toString(char *buffer, RN *this) {
	//format the string as N/D
	sprintf(buffer, "%d%c%d", Nof(this), SLASH, Dof(this));
	return buffer;
}

int Nof(RN *this) {
	return this->N;
}

int Dof(RN *this) {
	return this->D;
}

void invert(RN *this) {
	//invert so that N = D and D = N
	int temp = this->D;
	this->D = this->N;
	this->N = temp;
}

void add(RN *this, RN *that) {
	int a = this->N;
	int b = this->D;
	int c = that->N;
	int d = that->D;

	//formula for adding two fraction
	this->N = (a * d) + (b * c);
	this->D = (b * d);

	normalize(this);
}

void subtract(RN *this, RN *that) {
	int a = this->N;
	int b = this->D;
	int c = that->N;
	int d = that->D;

	//formula for subtracting two fraction
	this->N = (a * d) - (b * c);
	this->D = (b * d);

	normalize(this);
}

void multiply(RN *this, RN *that) {
	int a = this->N;
	int b = this->D;
	int c = that->N;
	int d = that->D;

	//formula for multiplying two fraction
	this->N = (a * c);
	this->D = (b * d);

	normalize(this);
}

void divide(RN *this, RN *that) {
	int a = this->N;
	int b = this->D;
	int c = that->N;
	int d = that->D;

	//make sure that c != 0
	assert(c != 0);

	//formula for dividing two fraction
	this->N = (a * d);
	this->D = (b * c);

	normalize(this);
}

int compareTo(RN *this, RN *that) {
    //Find the lcm of the two numbers
	int lcm = LCM(this->D, that->D);

    //Multiply the numerator to adjust for the common denominator
	int num1 = this->N * (lcm / this->D);
	int num2 = that->N * (lcm / that->D);

    //Compare the numerator of the common denominator fraction
	if (num1 > num2)
		return 1;
	else if (num2 > num1)
		return -1;
	else
		return 0;
}
