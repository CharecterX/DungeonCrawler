// Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis id finibus velit. Maecenas efficitur ligula sit amet diam aliquet, at.
#include <iostream>
#include <ctime>
#include <random>
#include <string>
#include <array>

using namespace std;

const char MAIN_MENU_EXIT_KEY = '6';

/*
These are function prototypes.
They have to match the function further down the page,
but they help the compiler keep code ordered.
If you need to add a funtion, add a matching protype()
*/

void printMenu();
void generateStartingArea();
void generateDungeonChamber();
int chamberExitsNormal();
int chamberExitsLarge();
void chamberExitLocation();
void chamberExitType();
string generateDungeonDoor();
void generateDungeonPassage();
void generatePassageWidth();
void generateDoorContents();
void generateStairs();
string secretDoor();
int rollDice(int numberOfDice, int sizeOfDice);

void printMenu()
{
	cout << "1.) Generate a starting area." << endl;
	cout << "2.) Generate a single chamber." << endl;
	cout << "3.) Generate a passage." << endl;
	cout << "4.) Generate door contents." << endl;
	cout << "5.) Generate Stairs." << endl;
	cout << "6.) Exit" << endl;
}

/*
These functions will generate random components
of a dungeon.
*/
void generateStartingArea()
{
	int startingAreaRoll = rollDice(1, 10);
	switch (startingAreaRoll)
	{
	case 1:
		cout << "Square, 20 x 20ft. with a passage on each wall" << endl;
		break;
	case 2:
		cout << "Square, 20 x 20ft. with a" << generateDungeonDoor() << "on the a wall, a" << generateDungeonDoor() << " on another wall and a passage on a third wall" << endl;
		break;
	case 3:
		cout << "Square, 40 x 40ft. with a" << generateDungeonDoor() << "on a wall, a" << generateDungeonDoor() << "on another wall, and a" << generateDungeonDoor() << "on a third wall" << endl;
		break;
	case 4:
		cout << "Rectangle, 80 x 20 ft. with a row of pillars down the middle, two passages leading from each long wall, a" << generateDungeonDoor() << "on one short wall and a" << generateDungeonDoor() << "one the other" << endl;
		break;
	case 5:
		cout << "Rectangle, 20 x 40 ft. with a passage on each wall" << endl;
		break;
	case 6:
		cout << "Circle, 40 ft. diameter with one passage at each cardinal direction" << endl;
		break;
	case 7:
		cout << "Circle, 40 ft. diameter with one passage in each cardinal direction and a well in middle of room (might lead down to lower level)" << endl;
		break;
	case 8:
		cout << "Square, 20 x 20 ft. with a" << generateDungeonDoor() << "on one wall, a" << generateDungeonDoor() << "on another wall, a passage on a third wall, and a secret door on the fourth wall" << endl;
		break;
	case 9:
		cout << "Passage, 10 ft. wide in a T intersection" << endl;
		break;
	case 10:
		cout << "Passage, 10 ft. wide in a four way intersection" << endl;
		break;
	}
}

void generateDungeonChamber()
{
	int exitsNormal;
	int exitsLarge;
	int chamberRoll = rollDice(1, 20);
	switch (chamberRoll)
	{
	case 1:
	case 2:
		exitsNormal = chamberExitsNormal();
		cout << "Square 20 x 20 ft. \n";
		cout << "with " << exitsNormal;
		if (exitsNormal == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsNormal == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsNormal - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	case 3:
	case 4:
		exitsNormal = chamberExitsNormal();
		cout << "Square 30 x 30 ft. \n";
		cout << "with " << exitsNormal;
		if (exitsNormal == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsNormal == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsNormal - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	case 5:
	case 6:
		exitsNormal = chamberExitsNormal();
		cout << "Square 40 x 40 ft. \n";
		cout << "with " << exitsNormal;
		if (exitsNormal == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsNormal == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsNormal - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	case 7:
	case 8:
	case 9:
		exitsNormal = chamberExitsNormal();
		cout << "Rectangle 20 x 30 ft. \n";
		cout << "with " << exitsNormal;
		if (exitsNormal == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsNormal == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsNormal - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	case 10:
	case 11:
	case 12:
		exitsNormal = chamberExitsNormal();
		cout << "Rectangle 30 x 40 ft. \n";
		cout << "with " << exitsNormal;
		if (exitsNormal == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsNormal == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsNormal - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	case 13:
	case 14:
		exitsLarge = chamberExitsLarge();
		cout << "Rectangle 40 x 50 ft. \n";
		cout << "with " << exitsLarge;
		if (exitsLarge == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsLarge == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsLarge - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	case 15:
		exitsLarge = chamberExitsLarge();
		cout << "Rectangle 50 x 80 ft. \n";
		cout << "with " << exitsLarge;
		if (exitsLarge == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsLarge == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsLarge - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	case 16:
		exitsNormal = chamberExitsNormal();
		cout << "Circle 30 ft. diameter \n";
		cout << "with " << exitsNormal;
		if (exitsNormal == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsNormal == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsNormal - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	case 17:
		exitsLarge = chamberExitsLarge();
		cout << "Circle 50 ft. diameter \n";
		cout << "with " << exitsLarge;
		if (exitsLarge == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsLarge == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsLarge - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	case 18:
		exitsLarge = chamberExitsLarge();
		cout << "Octogon 40 x 40 ft. \n";
		cout << "with " << exitsLarge;
		if (exitsLarge == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsLarge == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsLarge - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	case 19:
		exitsLarge = chamberExitsLarge();
		cout << "Octogon 60 x 60 ft. \n";
		cout << "with " << exitsLarge;
		if (exitsLarge == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsLarge == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsLarge - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	case 20:
		exitsLarge = chamberExitsLarge();
		cout << "Trapezoid, Roughly 40 x 60 ft. \n";
		cout << "with " << exitsLarge;
		if (exitsLarge == 1)
		{
			chamberExitType();
			cout << "on the ";
			chamberExitLocation();
		}
		else if (exitsLarge == 0) { cout << " exits \n"; }
		else
		{
			cout << " exits, one"; chamberExitType();
			cout << "on the "; chamberExitLocation();
			for (int i = 0; i < exitsLarge - 2; i++) { cout << " one"; chamberExitType(); cout << "on the "; chamberExitLocation(); }
			cout << " and one"; chamberExitType(); cout << "on the "; chamberExitLocation();
		}
		break;
	}
}

int chamberExitsNormal()
{
	int numberOfExits;
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

int chamberExitsLarge()
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

void chamberExitLocation()
{
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
		cout << "wall opposite the entrance \n";
		break;
	case 8:
	case 9:
	case 10:
	case 11:
	case 12:
		cout << "wall left of the entrance \n";
		break;
	case 13:
	case 14:
	case 15:
	case 16:
	case 17:
		cout << "wall right of the entrance \n";
		break;
	case 18:
	case 19:
	case 20:
		cout << "same wall as the entrance \n";
		break;
	}
}

void chamberExitType()
{
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
		cout << generateDungeonDoor();
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
		cout << " 10 ft. long corridor ";
		break;
	}
}

string generateDungeonDoor()
{
	string doorType;
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
		doorType = " wooden door ";
		break;
	case 11:
	case 12:
		doorType = " barred or locked wooden door ";
		break;
	case 13:
		doorType = " stone door ";
		break;
	case 14:
		doorType = " barred or locked stone door ";
		break;
	case 15:
		doorType = " iron door ";
		break;
	case 16:
		doorType = " barred or locked iron door ";
		break;
	case 17:
		doorType = " protcullis ";
		break;
	case 18:
		doorType = " locked portcullis ";
		break;
	case 19:
		doorType = " secret door ";
		break;
	case 20:
		doorType = " locked secret door ";
		break;
	}
	return doorType;
}

void generateDungeonPassage()
{
	generatePassageWidth();
	int passageRoll = rollDice(1, 20);
	switch (passageRoll)
	{
	case 1:
	case 2:
		cout << "continues straight 30 feet, with no doors or side passages." << endl;
		break;
	case 3:
		cout << "continues straight 20 feet, with a" << generateDungeonDoor() <<  "to the right, then an additional 10 feet ahead." << endl;
		break;
	case 4:
		cout << "continues straight 20 feet, with a" << generateDungeonDoor() << "to the right, then an additional 10 feet ahead." << endl;
		break;
	case 5:
		cout << "continues straight 20 feet, passage ends in a" << generateDungeonDoor() << endl;
		break;
	case 6:
	case 7:
		cout << "continues straight 20 feet, with a side passage to the right then an additional 10 feet ahead." << endl;
		break;
	case 8:
	case 9:
		cout << "continues straight 20 feet, side passage to the left, then an additional 10 feet ahead." << endl;
		break;
	case 10:
		cout << "continues straight 20 feet, comes to a dead end." << secretDoor() << endl;
		break;
	case 11:
	case 12:
		cout << "continues straight 20 feet, then the passage turns left and continuess 10 feet." << endl;
		break;
	case 13:
	case 14:
		cout << "continues straight 20 feet, then the passage turns right and continuess 10 feet." << endl;
		break;
	case 15:
	case 16:
	case 17:
	case 18:
	case 19:
		cout << "Chamber (Roll on the Chamber Table)" << endl;
		break;
	case 20:
		cout << "Stairs (Roll on the Stairs Table)" << endl;
		break;
	}

}

void generatePassageWidth()
{
	int passageWidthRoll = rollDice(1, 20);
	switch (passageWidthRoll)
	{
	case 1:
	case 2:
		cout << "The passage is 5 feet wide, and ";
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
		cout << "The passage is 10 feet wide, and ";
		break;
	case 13:
	case 14:
		cout << "The passage is 20 feet wide, and ";
		break;
	case 15:
	case 16:
		cout << "The passage is 30 feet wide, and ";
		break;
	case 17:
		cout << "The passage is 40 feet wide with a row of pillars down the middle, and ";
		break;
	case 18:
		cout << "The passage is 40 feet wide with a double row of pillars, and ";
		break;
	case 19:
		cout << "The passage is 40 feet wide, 20 feet high, and ";
		break;
	case 20:
		cout << "The passage is 40 feet, 20 feet high, and has a gallery 10 feet above the floor allowing access to the level above. It then ";
		break;
	}
}

void generateDoorContents()
{
	int doorContentsRoll = rollDice(1, 20);
	switch (doorContentsRoll)
	{
	case 1:
	case 2:
		cout << "Passage extending 10 ft., the T intersection extending 10 ft. to the right left. \n";
		generatePassageWidth();
		break;
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
		cout << "Passage 20 ft. straight ahead. \n";
		generatePassageWidth();
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
		cout << "Chamber (Roll on the chamber table) \n";
		break;
	case 19:
		cout << "Stairs (Roll on the Stairs table) \n";
		break;
	case 20:
		cout << "False door with trap \n";
		break;
	}
}

void generateStairs()
{
	int stairRoll = rollDice(1, 20);
	switch (stairRoll)
	{
	case 1:
	case 2:
	case 3:
	case 4:
		cout << "Down one level to a chamber \n";
		break;
	case 5:
	case 6:
	case 7:
	case 8:
		cout << "Down one level to a passage 20 ft. long \n";
		break;
	case 9:
		cout << "Down two levels to a chamber \n";
		break;
	case 10:
		cout << "Down two level two a passage 20 ft. long \n";
		break;
	case 11:
		cout << "Down three levels to a chamber \n";
		break;
	case 12:
		cout << "Down three level to a passage 20 ft. long \n";
		break;
	case 13:
		cout << "Up one level to a chamber \n";
		break;
	case 14:
		cout << "Up one level to a passage 20 ft. long \n";
		break;
	case 15:
		cout << "Up one level to a dead end \n";
		break;
	case 16:
		cout << "Down one level to a dead end \n";
		break;
	case 17:
		cout << "Chimmney up one level to a passage 20 ft. long \n";
		break;
	case 18:
		cout << "Chimmney up two levels to a passage 20 ft. long \n";
		break;
	case 19:
		cout << "Shaft (with or without elevator) down one level to a chamber \n";
		break;
	case 20:
		cout << "Shaft (with or without elevator) up one level to a chamber \n";
		break;
	}

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
		case '1': generateStartingArea();
			break;
		case '2': generateDungeonChamber();
			break;
		case '3': generateDungeonPassage();
			break;
		case '4': generateDoorContents();
			break;
		case '5': generateStairs();
			break;
		case '6':
			break;
		}
	} while (input != MAIN_MENU_EXIT_KEY);

	return 0;
}