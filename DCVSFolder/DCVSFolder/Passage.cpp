#include <string>
#include <random>
#include <ctime>

using namespace std;

class Passage
{
private: 
	string width;
	string length;
	string description;
	

public:
	Passage(string width = "\n\tA passage that is 5 feet wide, and ", string length = "continues straight 30 feet, ", string description = "with no doors or side passages. \n\n")
	{
		setWidth(width);
		setLength(length);
		setDescription(description);
	}

	void setWidth(string widthSize)
	{
		width = widthSize;
	}

	void setLength(string lengthSize)
	{
		length = lengthSize;
	}

	void setDescription(string passageDescrition)
	{
		description = passageDescrition;
	}

	string getWidth()
	{
		return width;
	}

	string getLength()
	{
		return length;
	}

	string getDescription()
	{
		return description;
	}
	
	string toString()
	{
		return getWidth() + getLength() + getDescription();
	}

	
};