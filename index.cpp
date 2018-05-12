#include <iostream>

#include "moves.cpp"
#include <string>
#include<map>
using namespace std;



int main(int argc, char const *argv[])
{	
	Global main;
	int hello = 7;
	Pokemon pikachu;
	pikachu = CreatePokemon("pikachu","ELECTRIC",1,35,55,40,50,50,90, "Med Fast");
	main = CreateMoveList(main);
	cout<<main.moveList[69].id <<endl;
	//cout<<moveList[0].nameInternal<<endl;
	return 0;
}