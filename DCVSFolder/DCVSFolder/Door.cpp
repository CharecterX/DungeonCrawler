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

#include <string>

using namespace std;

class Door
{
private:
	string material;
	bool locked;

public:
	Door(string material = "wooden", bool locked = false)
	{
		setMaterial(material);
		setLocked(locked);
	}

	void setLocked(bool lockedStatus)
	{
		locked = lockedStatus;
	}

	void setMaterial(string materialType)
	{
		material = materialType;
	}

	string getMaterial()
	{
		return material;
	}

	string getLocked()
	{
		if (locked)
		{
			return "locked ";
		}
		else
		{
			return " ";
		}
	}

	bool isLocked()
	{
		return locked;
	}

	string toString()
	{
		return " " + getLocked() + getMaterial() + " door ";
	}
};