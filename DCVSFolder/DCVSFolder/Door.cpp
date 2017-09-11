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