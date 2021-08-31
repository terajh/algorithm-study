#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <regex>
using namespace std;


int main() {
	string noise;
	cin >> noise;
	string ptn = "(100+1+|01)+";
	if (regex_match(noise, regex(ptn))) printf("SUBMARINE");
	else printf("NOISE");

	return 0;
}