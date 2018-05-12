#include <iostream>

#include "moves.cpp"
#include <string>
#include<map>
using namespace std;


int main(int argc, char const *argv[])
{
	int hello = 7;
	Pokemon pikachu;
	string name = "pikachu";
	string type = "electric";
	string exp = "MedFast";
	pikachu = CreatePokemon(name,type,1,35,55,40,50,50,90, exp);
	AddToMoveList();
	//cout<<moveList[0].nameInternal<<endl;
	return 0;
}