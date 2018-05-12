
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

struct Stats //struct of stat values
{
	int hp;
	int attack;
	int defense;
	int spAttack;
	int spDefense;
	int speed;
	int hpB;
	int attackB;
	int defenseB;
	int spAttackB;
	int spDefenseB;
	int speedB;
	int exp;
	int level;
	string expType;
};


struct IVs //the individual gains of each stat IVs
{
	int hp;
	int attack;
	int defense;
	int spAttack;
	int spDefense;
	int speed;
};

struct Move
{
	int id;
	string nameInternal; //name not in battle
	string nameDisplay; //name in battle
	int functionCode; //hex digit
	int power; //damage of move
	string type; //type of move
	int category; //0 = physical; 1 = special; 2 = status
	int accuracy;
	int pp;
	int addEffectChance;
	int target; //0 = single target, 1 = self, 2 = nothing
	int priority; //0 - 6
	string flag;
	string descr; //description of the move
};
struct LevelUp
{
	bool evolve;
	Move lvlUpMoves[25];
};

class Pokemon //creates the pokemon object
{
public:
	string name;
	string type;
	Stats stats;
	IVs ivs;
	int numMoves;
	Move moves[4];
	LevelUp lvlUP;
	void SetDefValues();
	void SetBaseValues(string name, string type, int level, int hp, int attack, int Ndefense,int spAttack, int spDefense, int speed, string expCap);
	void SetIVs();
	void PrintPokemonInfo();

};
struct Global
{
	Move moveList[560];
	Pokemon pokeDex[151];
	Pokemon party[6];
};



void Pokemon::SetDefValues() //sets the default values of a pokemon when created
{
	stats.level = 1;
	stats.hp = stats.hpB;
	stats.attack = stats.attackB;
	stats.defense = stats.defenseB;
	stats.spAttack = stats.spAttackB;
	stats.spDefense = stats.spDefenseB;
	stats.speed = stats.speedB;
	stats.expType = "NULL";
	stats.exp = 0;
}

void Pokemon::SetBaseValues(string Nname, string Ntype, int Nlevel, int Nhp, int Nattack,int Ndefense, int NspAttack, int NspDefense, int Nspeed, string NexpCap) //sets the base values for a pokemon
{
	name = Nname;
	type = Ntype;
	stats.hpB = Nhp;
	stats.level = Nlevel;
	stats.attackB = Nattack;
	stats.defenseB = Ndefense;
	stats.spAttackB = NspAttack;
	stats.spDefenseB = NspDefense;
	stats.speedB = Nspeed;
	stats.expType = NexpCap;
}
void Pokemon::SetIVs() //assigns IV values
{
	ivs.hp = (rand() % 15);
	ivs.attack = (rand() % 15);
	ivs.defense = (rand() % 15);
	ivs.spAttack = (rand() % 15);
	ivs.spDefense = (rand() % 15);
	ivs.speed = (rand() % 15);
}

void Pokemon::PrintPokemonInfo() //prints out pokemon information
{
	cout<<"Name: "<<name <<endl;
	cout <<"Type: "<<type <<endl;
	cout<<"Level: "<<stats.level <<endl;
	cout <<"HP: "<<stats.hp<<endl;
	cout<<"Attack: "<<stats.attack <<endl;
	cout<<"Defense: "<<stats.defense <<endl;
	cout <<"Sp.Attack: "<<stats.spAttack <<endl;
	cout<<"Sp.Defense: "<<stats.spDefense <<endl;
	cout<<"Speed: " <<stats.speed <<endl;
	cout <<"HP IV: "<<ivs.hp<<endl;
	cout<<"Attack IV: "<<ivs.attack <<endl;
	cout<<"Defense IV: "<<ivs.defense <<endl;
	cout <<"Sp.Attack IV: "<<ivs.spAttack <<endl;
	cout<<"Sp.Defense IV: "<<ivs.spDefense <<endl;
	cout<<"Speed IV: " <<ivs.speed <<endl;
	cout<<"Exp Type: "<<stats.expType<<endl;
	cout<<"Current Exp: " <<stats.exp<<endl;

}

Pokemon CreatePokemon(string Nname, string Ntype, int Nlevel, int Nhp, int Nattack,int Ndefense, int NspAttack, int NspDefense, int Nspeed, string NexpCap) //creates a pokemon
{
	Pokemon newPokemon;
	newPokemon.SetBaseValues(Nname,Ntype,Nlevel,Nhp,Nattack,Ndefense,NspAttack,NspDefense,Nspeed,NexpCap);
	newPokemon.SetDefValues();
	newPokemon.SetIVs();
	newPokemon.PrintPokemonInfo();
	return newPokemon;
}