#include <iostream>
#include "pokemon.h"
#include "pokedexCreation.cpp"
#include "moves.cpp"
#include <string>
using namespace std;



int main(int argc, char const *argv[])
{	
	Global main;
	int hello = 7;
	Pokemon pikachu;
	pikachu = CreatePokemon("pikachu","ELECTRIC",1,35,55,40,50,50,90, "Med Fast");
	main = CreateMoveList(main);
	main = DexCreation(main);

	// cout<<main.moveList[69].id <<endl;

	for(int i = 0; i<151; i++)
	{
		cout<<main.pokeDex[i].name<<endl;
	}
	//cout<<moveList[0].nameInternal<<endl;
	return 0;
} 