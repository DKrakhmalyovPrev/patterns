#pragma once
#define _CRT_SECURE_NO_WARNINGS 

#include <iostream> 
#include <string> 
#include <iostream> 
#include <stdio.h> 
#include <cstdlib> 
#include <cmath> 
#include <string> 
#include <stdexcept> 
#include <algorithm> 
#include <vector> 
using namespace std;

int strcomp(string& a, const string& b);
class Character
{
public:
	void incPar(string& s, int n);
	int getPar(int n) const;
	Character(string n = "Hero", short a = 34, short d = 33, short l = 32);
private:
	string name;
	short attack;
	short defence;
	short luck;

};
bool Fight(const Character& player, const Character& enemy);
int game();