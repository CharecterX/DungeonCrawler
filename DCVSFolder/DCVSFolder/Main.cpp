
#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <array>
#include "Door.cpp"

using namespace std;

const char MAIN_MENU_EXIT_KEY = '5';

/* 
These are function prototypes.
They have to match the function further down the page,
but they help the compiler keep code ordered.
If you need to add a funtion, add a matching protype()
*/

void printMenu();
string generateStartingArea();
string generateDungeonChamber();
int chamberExitsNormalSizedChamber();
int chamberExitsLargeSizedChamber();
string chamberExitLocation(); 
string chamberExitType();
string generateDungeonPassage();
string generatePassageWidth();
string generateDoorContents();
string generateStairs();
string secretDoor();
string generateDungeonDoor();
int rollDice(int numberOfDice, int sizeOfDice);

void printMenu()
{
	cout << "1.) Generate a starting area." << endl;
	cout << "2.) Generate a single chamber." << endl;
	cout << "3.) Generate a passage." << endl;
	cout << "4.) Generate door contents." << endl;
	cout << "5.) Exit" << endl;
}

/*
These functions will generate random components
of a dungeon.
*/
string generateStartingArea()
{
	string startingArea;
	int startingAreaRoll = rollDice(1, 10);
	switch (startingAreaRoll)
	{
	case 1:
		startingArea = "Square, 20 x 20ft. with a passage on each wall \n";
		break;
	case 2:
		startingArea = "Square, 20 x 20ft. with a" + generateDungeonDoor() + "on the a wall, a" + generateDungeonDoor() + " on another wall and a passage on a third wall \n";
		break;
	case 3:
		startingArea = "Square, 40 x 40ft. with a" + generateDungeonDoor() + "on a wall, a" + generateDungeonDoor() + "on another wall, and a" + generateDungeonDoor() + "on a third wall \n";
		break;
	case 4:
		startingArea = "Rectangle, 80 x 20 ft. with a row of pillars down the middle, two passages leading from each long wall, a" + generateDungeonDoor() + "on one short wall and a" + generateDungeonDoor() + "one the other \n";
		break;
	case 5:
		startingArea = "Rectangle, 20 x 40 ft. with a passage on each wall \n";
		break;
	case 6:
		startingArea = "Circle, 40 ft. diameter with one passage at each cardinal direction \n";
		break;
	case 7:
		startingArea = "Circle, 40 ft. diameter with one passage in each cardinal direction and a well in middle of room (might lead down to lower level) \n";
		break;
	case 8:
		startingArea = "Square, 20 x 20 ft. with a " + generateDungeonDoor() + " on one wall, a" + generateDungeonDoor() + "on another wall, a passage on a third wall, and a secret door on the fourth wall \n";
		break;
	case 9:
		startingArea = "Passage, 10 ft. wide in a T intersection \n";
		break;
	case 10:
		startingArea = "Passage, 10 ft. wide in a four way intersection \n";
		break;
	}
	return startingArea;
}

string generateDungeonChamber()
{
	string chamber;
	int numExitsNormalChamber;
	int numExitsLargeChamber;
	int chamberRoll = rollDice(1, 20);
	switch (chamberRoll)
	{
	case 1:
	case 2:
		numExitsNormalChamber = chamberExitsNormalSizedChamber();
		chamber = "Square 20 x 20 ft. \n with " + numExitsNormalChamber;
		if (numExitsNormalChamber == 0) 
		{ 
			chamber += " exits \n"; 
		}
		else if (numExitsNormalChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		}
		else
		{
			chamber += " exits, one" + chamberExitType() + "on the " + chamberExitLocation();
			for (int i = 0; i < numExitsNormalChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	case 3:
	case 4:
		numExitsNormalChamber = chamberExitsNormalSizedChamber();
		chamber = "Square 30 x 30 ft. \n with " + numExitsNormalChamber;
		if (numExitsNormalChamber == 0) 
		{ 
			chamber += " exits \n"; 
		}
		else if (numExitsNormalChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		}
		else
		{
			chamber += " exits, one" + chamberExitType() + "on the " + chamberExitLocation();
			for (int i = 0; i < numExitsNormalChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	case 5:
	case 6:
		numExitsNormalChamber = chamberExitsNormalSizedChamber();
		chamber = "Square 40 x 40 ft. \n with " + numExitsNormalChamber;
		if (numExitsNormalChamber == 0) 
		{ 
			chamber += " exits \n"; 
		}
		else if (numExitsNormalChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		}
		else
		{
			chamber += " exits, one" + chamberExitType() + "on the " + chamberExitLocation();
			for (int i = 0; i < numExitsNormalChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	case 7:
	case 8:
	case 9:
		numExitsNormalChamber = chamberExitsNormalSizedChamber();
		chamber = "Rectangle 20 x 30 ft. \n with " + numExitsNormalChamber;
		if (numExitsNormalChamber == 0) 
		{ 
			chamber += " exits \n"; 
		} else if (numExitsNormalChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		} else
		{
			chamber += " exits, one" + chamberExitType() + "on the "; chamberExitLocation();
			for (int i = 0; i < numExitsNormalChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	case 10:
	case 11:
	case 12:
		numExitsNormalChamber = chamberExitsNormalSizedChamber();
		chamber = "Rectangle 30 x 40 ft. \n with " + numExitsNormalChamber;
		if (numExitsNormalChamber == 0)
		{ 
			chamber += " exits \n"; 
		} else if (numExitsNormalChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		} else
		{
			chamber += " exits, one" + chamberExitType() + "on the " + chamberExitLocation();
			for (int i = 0; i < numExitsNormalChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	case 13:
	case 14:
		numExitsLargeChamber = chamberExitsLargeSizedChamber();
		chamber = "Rectangle 40 x 50 ft. \n with " + numExitsLargeChamber;
		if (numExitsLargeChamber == 0)
		{ 
			chamber += " exits \n"; 
		} else if (numExitsLargeChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		} else
		{
			chamber += " exits, one" + chamberExitType() + "on the " + chamberExitLocation();
			for (int i = 0; i < numExitsLargeChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	case 15:
		numExitsLargeChamber = chamberExitsLargeSizedChamber();
		chamber = "Rectangle 50 x 80 ft. \n with " + numExitsLargeChamber;
		if (numExitsLargeChamber == 0) 
		{ 
			chamber += " exits \n"; 
		} else if (numExitsLargeChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		} else
		{
			chamber += " exits, one" + chamberExitType() + "on the "+ chamberExitLocation();
			for (int i = 0; i < numExitsLargeChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	case 16:
		numExitsNormalChamber = chamberExitsNormalSizedChamber();
		chamber = "Circle 30 ft. diameter \n with " + numExitsNormalChamber;
		if (numExitsNormalChamber == 0) 
		{
			chamber += " exits \n";
		} else if (numExitsNormalChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		} else
		{
			chamber += " exits, one" + chamberExitType() + "on the " + chamberExitLocation();
			for (int i = 0; i < numExitsNormalChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	case 17:
		numExitsLargeChamber = chamberExitsLargeSizedChamber();
		chamber = "Circle 50 ft. diameter \n with " + numExitsLargeChamber;
		if (numExitsLargeChamber == 0) 
		{ 
			chamber += " exits \n"; 
		} else if (numExitsLargeChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		} else
		{
			chamber += " exits, one" + chamberExitType() + "on the "; chamberExitLocation();
			for (int i = 0; i < numExitsLargeChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	case 18:
		numExitsLargeChamber = chamberExitsLargeSizedChamber();
		chamber = "Octogon 40 x 40 ft. \n with " + numExitsLargeChamber;
		if (numExitsLargeChamber == 0) 
		{
			chamber += " exits \n";
		} else if (numExitsLargeChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		} else
		{
			chamber += " exits, one" + chamberExitType() + "on the " + chamberExitLocation();
			for (int i = 0; i < numExitsLargeChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	case 19:
		numExitsLargeChamber = chamberExitsLargeSizedChamber();
		chamber = "Octogon 60 x 60 ft. \n with " + numExitsLargeChamber;
		if (numExitsLargeChamber == 0) 
		{
			chamber += " exits \n";
		} else if (numExitsLargeChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		} else
		{
			chamber += " exits, one" + chamberExitType() + "on the " + chamberExitLocation();
			for (int i = 0; i < numExitsLargeChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	case 20:
		numExitsLargeChamber = chamberExitsLargeSizedChamber();
		chamber = "Trapezoid, Roughly 40 x 60 ft. \n with " + numExitsLargeChamber;
		if (numExitsLargeChamber == 0)
		{
			chamber += " exits \n";
		} else if (numExitsLargeChamber == 1)
		{
			chamber += chamberExitType() + "on the " + chamberExitLocation();
		} else
		{
			chamber += " exits, one" + chamberExitType() + "on the " + chamberExitLocation();
			for (int i = 0; i < numExitsLargeChamber - 2; i++) { chamber += " one" + chamberExitType() + "on the " + chamberExitLocation(); }
			chamber += " and one" + chamberExitType() + "on the " + chamberExitLocation();
		}
		break;
	}
	return chamber;
}

int chamberExitsNormalSizedChamber()
{
	char numberOfExits;
	int exitRoll = rollDice(1, 20);
	switch (exitRoll)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		numberOfExits = 0;
		break;
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
		numberOfExits = 1;
		break;
	case 12:
	case 13:
	case 14:
	case 15:
		numberOfExits = 2;
		break;
	case 16:
	case 17:
	case 18:
		numberOfExits = 3;
		break;
	case 19:
	case 20:
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
	case 1:
	case 2:
	case 3:
		numberOfExits = 0;
		break;
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		numberOfExits = 1;
		break;
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
		numberOfExits = 2;
		break;
	case 14:
	case 15:
	case 16:
	case 17:
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

string chamberExitLocation()
{
	string exit;
	int exitLocationRoll = rollDice(1, 20);
	switch (exitLocationRoll)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
		exit = "wall opposite the entrance \n";
		break;
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		exit =  "wall left of the entrance \n";
		break;
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
		exit = "wall right of the entrance \n";
		break;
	case 18:
	case 19:
	case 20:
		exit = "same wall as the entrance \n";
		break;
	}
	return exit;
}

string chamberExitType()
{
	string exit;
	int exitTypeRoll = rollDice(1, 20);
	switch (exitTypeRoll)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		exit = generateDungeonDoor();
		break;
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
	case 20:
		exit = " 10 ft. long corridor ";
		break;
	}
	return exit;
}

string generateDungeonDoor()
{
	Door newDoor;
	int doorRoll = rollDice(1, 20);
	switch (doorRoll)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		newDoor = Door();
		break;
	case 11:
	case 12:
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

string generateDungeonPassage()
{
	string passage;
	int passageRoll = rollDice(1, 20);
	switch (passageRoll)
	{
	case 1:
	case 2:
		passage = generatePassageWidth() + "continues straight 30 feet, with no doors or side passages. \n";
		break;
	case 3:
		passage = generatePassageWidth() + "continues straight 20 feet, with a" + generateDungeonDoor() +  "to the right, then an additional 10 feet ahead. \n";
		break;
	case 4:
		passage = generatePassageWidth() + "continues straight 20 feet, with a" + generateDungeonDoor() + "to the right, then an additional 10 feet ahead \n";
		break;
	case 5:
		passage = generatePassageWidth() + "continues straight 20 feet, passage ends in a" + generateDungeonDoor() + "\n";
		break;
	case 6:
	case 7:
		passage = generatePassageWidth() + "continues straight 20 feet, with a side passage to the right then an additional 10 feet ahead. \n";
		break;
	case 8:
	case 9:
		passage = generatePassageWidth() + "continues straight 20 feet, side passage to the left, then an additional 10 feet ahead. \n";
		break;
	case 10:
		passage = generatePassageWidth() + "continues straight 20 feet, comes to a dead end." + secretDoor() + "\n";
		break;
	case 11:
	case 12:
		passage = generatePassageWidth() + "continues straight 20 feet, then the passage turns left and continuess 10 feet. \n";
		break;
	case 13:
	case 14:
		passage = generatePassageWidth() + "continues straight 20 feet, then the passage turns right and continuess 10 feet. \n";
		break;
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
		passage = generatePassageWidth() + "Chamber (Roll on the Chamber Table) \n";
		break;
	case 20:
		passage = generatePassageWidth() + "Stairs (Roll on the Stairs Table) \n";
		break;
	}
	return passage;
}

string generatePassageWidth()
{
	string passageWidth;
	int passageWidthRoll = rollDice(1, 20);
	switch (passageWidthRoll)
	{
	case 1:
	case 2:
		passageWidth = "A passage that is 5 feet wide, and ";
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		passageWidth = "A passage that is 10 feet wide, and ";
		break;
	case 13:
	case 14:
		passageWidth = "A passage that is 20 feet wide, and ";
		break;
	case 15:
	case 16:
		passageWidth = "A passage that is 30 feet wide, and ";
		break;
	case 17:
		passageWidth = "A passage that is 40 feet wide with a row of pillars down the middle, and ";
		break;
	case 18:
		passageWidth = "A passage that is 40 feet wide with a double row of pillars, and ";
		break;
	case 19:
		passageWidth = "A passage that is 40 feet wide, 20 feet high, and ";
		break;
	case 20:
		passageWidth = "A passage that is 40 feet, 20 feet high, and has a gallery 10 feet above the floor allowing access to the level above. It then ";
		break;
	}
	return passageWidth;
}

string generateDoorContents()
{
	string doorContents;
	int doorContentsRoll = rollDice(1, 20);
	switch (doorContentsRoll)
	{
	case 1:
	case 2:
		doorContents = generatePassageWidth() + "extends 10 ft., ending in a T intersection extending 10 ft. to the right and left. \n";
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		doorContents = generatePassageWidth() + "extends 20 ft. straight ahead. \n";
		break;
	case 9:
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
	case 18:
		doorContents = "Chamber (Roll on the chamber table) \n";
		break;
	case 19:
		doorContents = "Stairs (Roll on the Stairs table) \n";
		break;
	case 20:
		doorContents = "False door with trap \n";
		break;
	}
	return doorContents;
}

string generateStairs()
{
	string stairs;
	int stairRoll = rollDice(1, 20);
	switch (stairRoll)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		stairs = "Down one level to a chamber \n";
		break;
	case 5:
	case 6:
	case 7:
	case 8:
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