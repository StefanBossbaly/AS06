#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "RN.h"

void reduce(RN this) {
    //Normalize the negative sign
    if (this->N < 0 && this->D < 0) {
		this->D = abs(this->D);
		this->N = abs(this->N);
	} else if (this->N >= 0 && this->D < 0) {
		this->D = abs(this->D);
		this->N = this->N * -1;
	}
	//get the greatest common denominator
	int gcd = GCD(this->N, this->D);

	//if the gcd is equal to 1 or -1 we don't need to divide
	if (gcd == 1 || gcd == -1)
		return;

	//divide both the numerator and denominator by the gcd to reduce
	this->N = this->N / gcd;
	this->D = this->D / gcd;
}

int LCM(int num1, int num2) {
	//TODO implement a better algorithm then this atrocity
	return (num1 * num2);
}

int GCD(int num1, int num2) {
    //If the numbers are equal their values are the GCD
    if (num1 == num2)
        return num1;
    
    //
	int start = ceil(min(num1, num2));

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

int abs(int num) {
    return (num > 0) ? num : num * -1;
}

int ceil(int num) {
    return (num + 1) / 2;
}

RN newS(char *S) {
	int n = 0, d = 0;
	sscanf(S, "%d/%d", &n, &d);
	
	return newI(n, d);
}

RN newI(int N, int D) {
    //No divide by zero
    assert(D != 0);
    
	RN result = (RN) malloc(sizeof(RN));
	result->N = N;
	result->D = D;

	//Reduce the RN before we return it
	reduce(result);

	return result;
}

char *toString(char *buffer, RN this) {
	//format the string as N/D
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
	//invert so that N = D and D = N
	int temp = this->D;
	this->D = this->N;
	this->N = temp;
}

void add(RN this, RN that) {
	int a = this->N;
	int b = this->D;
	int c = that->N;
	int d = that->D;

	//formula for adding two fraction
	this->N = (a * d) + (b * c);
	this->D = (b * d);

	reduce(this);
}

void subtract(RN this, RN that) {
	int a = this->N;
	int b = this->D;
	int c = that->N;
	int d = that->D;

	//formula for subtracting two fraction
	this->N = (a * d) - (b * c);
	this->D = (b * d);

	reduce(this);
}

void multiply(RN this, RN that) {
	int a = this->N;
	int b = this->D;
	int c = that->N;
	int d = that->D;

	//formula for multiplying two fraction
	this->N = (a * c);
	this->D = (b * d);

	reduce(this);
}

void divide(RN this, RN that) {
	int a = this->N;
	int b = this->D;
	int c = that->N;
	int d = that->D;

	//make sure that c != 0
	assert(c != 0);

	//formula for dividing two fraction
	this->N = (a * d);
	this->D = (b * c);

	reduce(this);
}

int compareTo(RN this, RN that) {
	int lcm = LCM(this->D, that->D);

	int num1 = this->N * (lcm / this->D);
	int num2 = that->N * (lcm / that->D);

	if (num1 > num2)
		return 1;
	else if (num2 > num1)
		return -1;
	else
		return 0;
}
