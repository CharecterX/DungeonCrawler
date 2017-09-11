/*
*
*	Dungeon-ator V0.1
*	A program to help DMs generate dungeons faster, based on
*	the random dungeon tables in the 
*	Dungeons and Dragons Fifth Edition Dungeon Master's Guide
*
*	Authors: Cole Nordmann, Alex Abernathy
*	Date: 09-2017
*
*/

#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <array>
#include "Door.cpp"

using namespace std;

const char MAIN_MENU_EXIT_KEY = '5';


/*Core functions*/
void printMenu();
int rollDice(int numberOfDice, int sizeOfDice);

/*Menu option functions*/
string generateStartingArea();
string generateDungeonChamber();
string generateDungeonPassage();
string generateDoorContents();

/*Generator subroutines*/
string chamberExitType();
string chamberExitLocation(); 
int chamberExitsNormalSizedChamber();
int chamberExitsLargeSizedChamber();
string secretDoor();
string generateDungeonDoor();
string generatePassageWidth();
string generateChamberExitLayout(int numExitsInChamber);

/* Functions not in use */
//string generateStairs();
	/*
string generateStairs()
{
	string stairs;
	int stairRoll = rollDice(1, 20);
	switch (stairRoll)
	{
	case 1: case 2: case 3: case 4:
		stairs = "Down one level to a chamber \n";
		break;
	case 5: case 6: case 7: case 8:
		stairs = "Down one level to a passage 20 ft. long \n";
		break;
	case 9:
		stairs = "Down two levels to a chamber \n";
		break;
	case 10:
		stairs = "Down two level two a passage 20 ft. long \n";
		break;
	case 11:
		stairs = "Down three levels to a chamber \n";
		break;
	case 12:
		stairs = "Down three level to a passage 20 ft. long \n";
		break;
	case 13:
		stairs = "Up one level to a chamber \n";
		break;
	case 14:
		stairs = "Up one level to a passage 20 ft. long \n";
		break;
	case 15:
		stairs = "Up one level to a dead end \n";
		break;
	case 16:
		stairs = "Down one level to a dead end \n";
		break;
	case 17:
		stairs = "Chimmney up one level to a passage 20 ft. long \n";
		break;
	case 18:
		stairs = "Chimmney up two levels to a passage 20 ft. long \n";
		break;
	case 19:
		stairs = "Shaft (with or without elevator) down one level to a chamber \n";
		break;
	case 20:
		stairs = "Shaft (with or without elevator) up one level to a chamber \n";
		break;
	}
	return stairs;
}
*/

void printMenu()
{
	cout << " 1.) Generate a starting area." << endl;
	cout << " 2.) Generate a single chamber." << endl;
	cout << " 3.) Generate a passage." << endl;
	cout << " 4.) Generate door contents." << endl;
	cout << " 5.) Exit" << endl;
	cout << endl;
}

int rollDice(int numberOfDice, int sizeOfDice)
{
	int rollTotal = 0;
	static default_random_engine randomEngine(time(0)); //crates the actual engine and seeds it with time.
	uniform_int_distribution<int> diceRoll(1, sizeOfDice); //establishes a range

	for (int i = 0; i < numberOfDice; i++)
	{
		rollTotal += diceRoll(randomEngine);//calls the range and random engine seeded with time
	}
	return rollTotal;
}

string generateStartingArea()
{
	string startingArea;
	int startingAreaRoll = rollDice(1, 10);
	switch (startingAreaRoll)
	{
	case 1:
		startingArea = "\n\tSquare, 20 x 20ft. with a passage on each wall \n\n";
		break;
	case 2:
		startingArea = "\n\tSquare, 20 x 20ft. with a" + generateDungeonDoor() + "on the a wall, a" + generateDungeonDoor() + " on another wall and a passage on a third wall \n\n";
		break;
	case 3:
		startingArea = "\n\tSquare, 40 x 40ft. with a" + generateDungeonDoor() + "on a wall, a" + generateDungeonDoor() + "on another wall, and a" + generateDungeonDoor() + "on a third wall \n\n";
		break;
	case 4:
		startingArea = "\n\tRectangle, 80 x 20 ft. with a row of pillars down the middle, two passages leading from each long wall, a" + generateDungeonDoor() + "on one short wall and a" + generateDungeonDoor() + "one the other \n\n";
		break;
	case 5:
		startingArea = "\n\tRectangle, 20 x 40 ft. with a passage on each wall \n\n";
		break;
	case 6:
		startingArea = "\n\tCircle, 40 ft. diameter with one passage at each cardinal direction \n\n";
		break;
	case 7:
		startingArea = "\n\tCircle, 40 ft. diameter with one passage in each cardinal direction and a well in middle of room (might lead down to lower level) \n\n";
		break;
	case 8:
		startingArea = "\n\tSquare, 20 x 20 ft. with a " + generateDungeonDoor() + " on one wall, a" + generateDungeonDoor() + "on another wall, a passage on a third wall, and a secret door on the fourth wall \n\n";
		break;
	case 9:
		startingArea = "\n\tPassage, 10 ft. wide in a T intersection \n\n";
		break;
	case 10:
		startingArea = "Passage, 10 ft. wide in a four way intersection \n\n";
		break;
	}
	return startingArea;
}

string generateDungeonChamber()
{
	string chamber;
	int chamberRoll = rollDice(1, 20);
	switch (chamberRoll)
	{
	case 1: case 2:
		chamber = "\n\tSquare 20 x 20 ft. \n\twith " + generateChamberExitLayout(chamberExitsNormalSizedChamber());
		/*
		numExitsInChamber = chamberExitsNormalSizedChamber();
		chamber = "Square 20 x 20 ft. \n with " + numExitsInChamber;
		if (numExitsInChamber == 0)
		{
		chamber += " exits \n";
		}
		else if (numExitsInChamber == 1)
		{
		chamber += chamberExitType() + "on the " + chamberExitLocation();
		}
		else
		{
		chamber += " exits, one" + chamberExitType() + "on the " + chamberExitLocation();
		for (int i = 0; i < numExitsInChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
		chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		*/
		break;
	case 3: case 4:
		chamber = "\n\tSquare 30 x 30 ft. \n\twith " + generateChamberExitLayout(chamberExitsNormalSizedChamber());
		break;
	case 5: case 6:
		chamber = "\n\tSquare 40 x 40 ft. \n\twith " + generateChamberExitLayout(chamberExitsNormalSizedChamber());
		break;
	case 7: case 8: case 9:
		chamber = "\n\tRectangle 20 x 30 ft. \n\twith " + generateChamberExitLayout(chamberExitsNormalSizedChamber());
		break;
	case 10: case 11: case 12:
		chamber = "\n\tRectangle 30 x 40 ft. \n\twith " + generateChamberExitLayout(chamberExitsNormalSizedChamber());
		break;
	case 13: case 14:
		chamber = "\n\tRectangle 40 x 50 ft. \n\twith " + generateChamberExitLayout(chamberExitsLargeSizedChamber());
		break; case 15:
			chamber = "\n\tRectangle 50 x 80 ft. \n\twith " + generateChamberExitLayout(chamberExitsLargeSizedChamber());
			break;
		case 16:
			chamber = "\n\tCircle 30 ft. diameter \n\twith " + generateChamberExitLayout(chamberExitsNormalSizedChamber());
			break;
		case 17:
			chamber = "\n\tCircle 50 ft. diameter \n\twith " + generateChamberExitLayout(chamberExitsLargeSizedChamber());
			break;
		case 18:
			chamber = "\n\tOctagon 40 x 40 ft. \n\twith " + generateChamberExitLayout(chamberExitsLargeSizedChamber());
			break;
		case 19:
			chamber = "\n\tOctogon 60 x 60 ft. \n\twith " + generateChamberExitLayout(chamberExitsLargeSizedChamber());
			break;
		case 20:
			chamber = "\n\tTrapezoid, Roughly 40 x 60 ft. \n\twith " + generateChamberExitLayout(chamberExitsLargeSizedChamber());
			break;
	}
	chamber += "\n";
	return chamber;
}

string generateDungeonPassage()
{
	string passage;
	int passageRoll = rollDice(1, 20);
	switch (passageRoll)
	{
	case 1: case 2:
		passage = generatePassageWidth() + "continues straight 30 feet, with no doors or side passages. \n\n";
		break;
	case 3:
		passage = generatePassageWidth() + "continues straight 20 feet, with a" + generateDungeonDoor() + "to the right, then an additional 10 feet ahead. \n\n";
		break;
	case 4:
		passage = generatePassageWidth() + "continues straight 20 feet, with a" + generateDungeonDoor() + "to the right, then an additional 10 feet ahead \n\n";
		break;
	case 5:
		passage = generatePassageWidth() + "continues straight 20 feet, passage ends in a" + generateDungeonDoor() + "\n\n";
		break;
	case 6: case 7:
		passage = generatePassageWidth() + "continues straight 20 feet, with a side passage to the right then an additional 10 feet ahead. \n\n";
		break;
	case 8: case 9:
		passage = generatePassageWidth() + "continues straight 20 feet, side passage to the left, then an additional 10 feet ahead. \n\n";
		break;
	case 10:
		passage = generatePassageWidth() + "continues straight 20 feet, comes to a dead end." + secretDoor() + "\n\n";
		break;
	case 11: case 12:
		passage = generatePassageWidth() + "continues straight 20 feet, then the passage turns left and continuess 10 feet. \n\n";
		break;
	case 13: case 14:
		passage = generatePassageWidth() + "continues straight 20 feet, then the passage turns right and continuess 10 feet. \n\n";
		break;
	case 15: case 16: case 17: case 18: case 19:
		passage = generatePassageWidth() + "Chamber (Roll on the Chamber Table) \n\n";
		break;
	case 20:
		passage = generatePassageWidth() + "Stairs (Roll on the Stairs Table) \n\n";
		break;
	}
	return passage;
}

string generateDoorContents()
{
	string doorContents;
	int doorContentsRoll = rollDice(1, 20);
	switch (doorContentsRoll)
	{
	case 1: case 2:
		doorContents = generatePassageWidth() + "extends 10 ft., ending in a T intersection extending 10 ft. to the right and left. \n\n";
		break;
	case 3: case 4: case 5: case 6: case 7: case 8:
		doorContents = generatePassageWidth() + "extends 20 ft. straight ahead. \n\n";
		break;
	case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18:
		doorContents = "\n\tChamber (Roll on the chamber table) \n\n";
		break;
	case 19:
		doorContents = "\n\tStairs (Roll on the Stairs table) \n\n";
		break;
	case 20:
		doorContents = "\n\tFalse door with trap \n\n";
		break;
	}
	return doorContents;
}

string chamberExitType()
{
	string exit;
	int exitTypeRoll = rollDice(1, 20);
	switch (exitTypeRoll)
	{
	case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
		exit = generateDungeonDoor();
		break;
	case 11: case 12: case 13: case 14: case 15: case 16: case 17: case 18: case 19: case 20:
		exit = " 10 ft. long corridor ";
		break;
	}
	return exit;
}

string chamberExitLocation()
{
	string exit;
	int exitLocationRoll = rollDice(1, 20);
	switch (exitLocationRoll)
	{
	case 1: case 2: case 3:	case 4:	case 5: case 6: case 7:
		exit = "wall opposite the entrance \n\t";
		break;
	case 8: case 9: case 10: case 11: case 12:
		exit = "wall left of the entrance \n\t";
		break;
	case 13: case 14: case 15: case 16: case 17:
		exit = "wall right of the entrance \n\t";
		break;
	case 18: case 19: case 20:
		exit = "same wall as the entrance \n\t";
		break;
	}
	return exit;
}

int chamberExitsNormalSizedChamber()
{
	char numberOfExits;
	int exitRoll = rollDice(1, 20);
	switch (exitRoll)
	{
	case 1: case 2: case 3: case 4: case 5:
		numberOfExits = 0;
		break;
	case 6: case 7: case 8: case 9: case 10: case 11:
		numberOfExits = 1;
		break;
	case 12: case 13: case 14: case 15:
		numberOfExits = 2;
		break;
	case 16: case 17: case 18:
		numberOfExits = 3;
		break;
	case 19: case 20:
		numberOfExits = 4;
		break;
	}
	return numberOfExits;
}

int chamberExitsLargeSizedChamber()
{
	int numberOfExits;
	int exitRoll = rollDice(1, 20);
	switch (exitRoll)
	{
	case 1: case 2: case 3:
		numberOfExits = 0;
		break;
	case 4: case 5: case 6: case 7: case 8:
		numberOfExits = 1;
		break;
	case 9: case 10: case 11: case 12: case 13:
		numberOfExits = 2;
		break;
	case 14: case 15: case 16: case 17:
		numberOfExits = 3;
		break;
	case 18:
		numberOfExits = 4;
		break;
	case 19:
		numberOfExits = 5;
		break;
	case 20:
		numberOfExits = 6;
		break;
	}
	return numberOfExits;
}

string secretDoor()
{
	string str;
	int secretDoorRoll = rollDice(1, 100);
	if (secretDoorRoll >= 90)
	{
		str = " (There is a secret door)";
	}
	return str;
}

string generateDungeonDoor()
{
	Door newDoor;
	int doorRoll = rollDice(1, 20);
	switch (doorRoll)
	{
	case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10:
		newDoor = Door();
		break;
	case 11: case 12:
		newDoor = Door("wooden", true);
		break;
	case 13:
		newDoor = Door("stone", false);
		break;
	case 14:
		newDoor = Door("stone", true);
		break;
	case 15:
		newDoor = Door("iron", false);
		break;
	case 16:
		newDoor = Door("iron", true);
		break;
	case 17:
		newDoor = Door("portcullis", false);
		break;
	case 18:
		newDoor = Door("portcullis", true);
		break;
	case 19:
		newDoor = Door("secret", false);
		break;
	case 20:
		newDoor = Door("secret", true);
		break;
	}
	return newDoor.toString();
}

string generatePassageWidth()
{
	string passageWidth;
	int passageWidthRoll = rollDice(1, 20);
	switch (passageWidthRoll)
	{
	case 1: case 2:
		passageWidth = "\n\tA passage that is 5 feet wide, and ";
		break;
	case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
		passageWidth = "\n\tA passage that is 10 feet wide, and ";
		break;
	case 13: case 14:
		passageWidth = "\n\tA passage that is 20 feet wide, and ";
		break;
	case 15: case 16:
		passageWidth = "\n\tA passage that is 30 feet wide, and ";
		break;
	case 17:
		passageWidth = "\n\tA passage that is 40 feet wide with a row of pillars down the middle, and ";
		break;
	case 18:
		passageWidth = "\n\tA passage that is 40 feet wide with a double row of pillars, and ";
		break;
	case 19:
		passageWidth = "\n\tA passage that is 40 feet wide, 20 feet high, and ";
		break;
	case 20:
		passageWidth = "\n\tA passage that is 40 feet, 20 feet high, and has a gallery 10 feet above the floor allowing access to the level above. It then ";
		break;
	}
	return passageWidth;
}

string generateChamberExitLayout(int numExitsInChamber)
{
	string chamber = to_string(numExitsInChamber);
	if (numExitsInChamber == 0)
	{
		chamber += " exits \n";
	}
	else if (numExitsInChamber == 1)
	{
		chamber += chamberExitType() + "on the " + chamberExitLocation();
	}
	else
	{
		chamber += " exits, one" + chamberExitType() + "on the " + chamberExitLocation();
		for (int i = 0; i < numExitsInChamber - 2; i++)
		{
			chamber += "one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		chamber += "and one" + chamberExitType() + "on the " + chamberExitLocation();
	}
	return chamber;
}

int main()
{
	char input = 0;

	cout << "Welcome to Dungeon-ator!!!" << endl;
	cout << endl;
	do
	{
		printMenu();
		cout << "Enter your menu choice: ";
		cin >> input;
		while (input < '1' || input > MAIN_MENU_EXIT_KEY)
		{
			cout << "That's not a menu option, please choose another: ";
		}
		switch (input)
		{
		case '1': cout << generateStartingArea();
			break;
		case '2': cout << generateDungeonChamber();
			break;
		case '3': cout << generateDungeonPassage();
			break;
		case '4': cout << generateDoorContents();
			break;
		case '5':
			break;
		}
	} while (input != MAIN_MENU_EXIT_KEY);

	return 0;
}