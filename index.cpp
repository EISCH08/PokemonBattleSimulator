#include <iostream>
#include "pokemon.h"
#include "pokedexCreation.cpp"
#include "moves.cpp"
#include "battle.cpp"
#include <string>
using namespace std;



int main(int argc, char const *argv[])
{	
	Global main;
	double hello = 7;
	Pokemon pokemon1;
	Pokemon pokemon2;
	
	main = CreateMoveList(main);
	main = DexCreation(main);
	main.SetExpRanges();
	pokemon1 = CreatePokemon(6, 50, main);
	
	pokemon1.PrintPokemonInfo();
	hello = DamageCalc(pokemon1,pokemon1.moves[1], pokemon1);
	cout<<hello<<endl;
	//cout<<pikachu.learnMoveLvl[14]<<endl;
	//cout<<main.moveList[0].nameInternal<<endl;
	




	
	return 0;
} 