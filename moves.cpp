#include "pokemon.cpp"
#include <iostream>
#include <string>
#include <map>
#include<fstream>
#include<sstream>
using namespace std;
Move moveList[200];
Move CreateMove(int id,string nameInternal,string nameDisplay,int function,int power,string type, int category, int accuracy, int pp, int target,int priority, int addEffectChance, string flag, string descr)
{
	Move newMove;
	newMove.id = id;
	newMove.nameInternal = nameInternal;
	newMove.nameDisplay=nameDisplay;
	newMove.functionCode = function;
	newMove.power = power;
	newMove.type = type;
	newMove.category = category;
	newMove.accuracy = accuracy;
	newMove.pp = pp;
	newMove.target = target;
	newMove.priority = priority;
	newMove.addEffectChance= addEffectChance;
	newMove.flag = flag;
	newMove.descr = descr;

	return newMove;
}
 //stores all
void AddToMoveList()
{
	ifstream file;
	file.open("moves.txt");
	
	string line;
	if(file.is_open())
	{
		while(getline(file,line, ','))
		{
			string output;
			istringstream ss(line);
		
			int id;
			ss >> id;
			string test;
			ss >> test;
			cout <<test ;
			
		}
		cout<<"end of line"<<endl;
	}
		
		
		
	

	//Move absorb = CreateMove(0,"ABSORB","Absorb",0x0DD, 20, "GRASS", 1, 100, 25, 0, 0, 0, "", "User recovers half the HP inflicted on opponent");
	//moveList[0] = absorb;
}

