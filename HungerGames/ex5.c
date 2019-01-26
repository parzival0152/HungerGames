#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>

/************************
Ilay Tzuberi
211873286
83-120-05
*************************/

struct Player
{
	char *name;
	int id;
	struct Player *next;
};
typedef struct Player Player;

Player* CreatePlayer(Player * start);
void LetTheHungerGameBegin(Player * start);
Player* addToLast(Player * start, Player * add);
Player* InitTheHungerGame(Player * start);
void abndonShip(Player * start);
void printNames(Player * start);

int main()
{
	Player * start = NULL;//make the starting list
	start = InitTheHungerGame(start);//initiate the game
	if (start == NULL)//if there are no players
		exit(1);//stop imidiatly
	start = addToLast(start, start);//make the list circular
	//printNames(start); //this is for testing
	LetTheHungerGameBegin(start);//run
	system("pause");
	return 0;//end
}

/***************************************************************************************
Function name: LetTheHungerGameBegin
Input: list of players
Output: none (runs the main game)
The function operation: as described in the code itself
****************************************************************************************/
void LetTheHungerGameBegin(Player * start)
{
	Player * temp = NULL;//set temporary pointer to null
	while (start->next != start)//while there isnt only one player left
	{
		printf("%s kills %s\n", start->name, start->next->name);//print the kill line
		temp = start->next->next;//save the person after the next
		free(start->next->name);//free the killed name
		free(start->next);//free the killed person
		start->next = temp;//rejoin the list
		start = temp;//go to the next alive person
	}
	printf("%s stayin alive!!\n",start->name);//announce winner
}

/***************************************************************************************
Function name: CreatePlayer
Input: pointer to the list of players in case of bad memory allocation
Output: pointer to a new player
The function operation: create a player based on user input
****************************************************************************************/
Player* CreatePlayer(Player * start)
{
	Player * add = (Player*)malloc(sizeof(Player));//dynamicly create a player
	char * name = (char*)malloc(80 * sizeof(char));//dynamicly create a char array for a name
	int id;
	if (name == NULL || add == NULL)//if dynamic allocation for the name or player failed
	{
		free(name);//free the name
		free(add);//free the whole player
		abndonShip(start);//free all other players
		exit(1);//close the program
	}
	printf("name:\n");
	scanf(" %[^\n]s", name);
	printf("id:\n");
	scanf("%d", &id);
	//get from the user data
	char * new_name = (char*)malloc((strlen(name) + 1) * sizeof(char));//dynamicly allocate an array with no extra space
	strcpy(new_name,name);//copy the name over
	free(name);//free the big array
	//fill the person with data
	add->id = id;
	add->name = new_name;
	add->next = NULL;
	return add;//return the player
}

/***************************************************************************************
Function name: addToLast
Input: 2 pointers to players
Output: pointer to list of players with add pointer added to the end
The function operation: run to the last person in the list and append the last person to him
****************************************************************************************/
Player* addToLast(Player * start, Player * add)
{
	if (start == NULL)//if the start array is empty
		return add;//return the added player
	Player * save = start;//save the start location
	while (start->next != NULL)
	{
		start = start->next;//advance the start pointer to last item in the list
	}
	start->next = add;//link the add pointer to the end of the list
	return save;//return the start of the list
}

/***************************************************************************************
Function name: InitTheHungerGame
Input: player list(NUll at this point)
Output: the new player list
The function operation: initialize the game
****************************************************************************************/
Player* InitTheHungerGame(Player * start)
{
	int option;
	do
	{
		printf("Add a person to the game? 1 for yes, 0 for no\n");
		scanf("%d",&option);
		if(option==1)
			start = addToLast(start, CreatePlayer(start));
	} while (option != 0);
	return start;
}

/***************************************************************************************
Function name: abndonShip
Input: pointer to the list of existing players
Output: none
The function operation: itirate over all players freeing their name then freeing themself untill all memory has been freed
****************************************************************************************/
void abndonShip(Player * start)
{
	Player * temp; // temporary pointer
	//printf("yeet\n"); //this line is for testing
	while (start!=NULL)
	{
		temp = start->next;//save the next pointer
		free(start->name);//free the name
		free(start);//free the player
		start = temp;//go to the next player
	}
}

/***************************************************************************************
Function name: printNames
Input: player list
Output: prints to screen
The function operation: print all names and ids recursivaly
						this function was for testing
****************************************************************************************/
void printNames(Player * start)
{
	if (start == NULL)//if the list is empty
		return;//stop
	printf("%s %d\n", start->name, start->id);//print name and id
	printNames(start->next);//do the next one
}

/***************************************************************************************
Function name: 
Input: 
Output:
The function operation: 
****************************************************************************************/