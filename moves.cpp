#include <iostream>
#include <string>
#include <map>
#include<fstream>
#include<sstream>
using namespace std;
Global source;

 //stores all
Global CreateMoveList(Global source) //creates a deck with all the possible moves
{
	ifstream file;
	file.open("textFiles/moves.txt");
	
	string line;
	
	if(file.is_open())
	{
		
		int i = 0;
		while(getline(file,line))
		{
			stringstream iss;
			string data;
			iss<<line;
			Move newMove;
			int count =0;
			while(getline(iss,data,',') &&count < 14)
			{ 
				if (count == 0) //id of move
				{
					newMove.id = stoi(data);
				}
				else if(count ==1)//internal name
				{
					newMove.nameInternal = data;
				}
				else if(count ==2)
				{
					newMove.nameDisplay = data;
				}
				else if(count ==3)
				{
					newMove.functionCode = stoi("0x"+data);
				}
				else if(count ==4)
				{
					newMove.power = stoi(data);
				}
				else if(count ==5)
				{
					newMove.type = data;
				}
				else if(count ==6)
				{
					int form;
					if(data == "Physical")
					{
						form =0; 
					}
					else if (data == "Special")
					{
						form =1;
					}
					else
					{
						form = 2;
					}
					newMove.category = form;
				}
				else if(count ==7)
				{
					newMove.accuracy = stoi(data);
				}
				else if(count ==8)
				{
					newMove.pp = stoi(data);
					newMove.ppCur = newMove.pp;
				}
				else if(count ==9)
				{
					newMove.addEffectChance = stoi(data);
				}
				else if(count ==10)
				{
					newMove.target = stoi(data);
				}
				else if(count ==11)
				{
					newMove.priority = stoi("0x"+data);
				}
				else if(count ==12)
				{
					newMove.flag = data;
				}
				else if(count ==13)
				{
					newMove.descr = data;
				}
				count++;
			}
			source.moveList[i] =newMove;
			i++;
		}
			return source;	
		
		
}
		
		return source;
		
	

	//Move absorb = CreateMove(0,"ABSORB","Absorb",0x0DD, 20, "GRASS", 1, 100, 25, 0, 0, 0, "", "User recovers half the HP inflicted on opponent");
	//moveList[0] = absorb;
}

