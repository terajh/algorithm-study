#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <regex>
using namespace std;

int bm[151];
int main() {
	string noise;
	cin >> noise;
	noise += "-";
	bm[0] = 1<<1; // initial

	for (int i = 0; i < noise.size() - 1; i++) {

		if (bm[i] & (1<<1)) { // Initial
			if (noise.at(i) == '1') 
				bm[i + 1] |= (1 << 2);
			else if (noise.at(i) == '0' && noise.at(i+1) == '1') 
				bm[i + 2] |= (1 << 6);
		}
		 if (bm[i] & (1 << 2)) { // A
			if (noise.at(i) == '0')
				bm[i + 1] |= (1 << 3);
		}
		if (bm[i] & (1 << 3)) { // B
			if (noise.at(i) == '0')
				bm[i + 1] |= (1 << 4);
		}
		if (bm[i] & (1 << 4)) { // C
			if (noise.at(i) == '0') 
				bm[i + 1] |= (1 << 4);
			else if (noise.at(i) == '1') 
				bm[i + 1] |= (1 << 5);
		}
		if (bm[i] & (1 << 5)) { // D
			if (noise.at(i) == '0' && noise.at(i + 1) == '1')
				bm[i + 2] |= (1 << 6);
			else if (noise.at(i) == '1')
				bm[i + 1] |= ((1 << 2) + (1 << 5));
		}
		if (bm[i] & (1 << 6)) { // E
			if (noise.at(i) == '0' && noise.at(i + 1) == '1')
				bm[i + 2] |= (1 << 6);
			else if (noise.at(i) == '1')
				bm[i + 1] |= (1 << 2);
		}
	}

	if (bm[noise.size() - 1] & (64 + 32)) printf("SUBMARINE");
	else printf("NOISE");
}