#include <string>

using namespace std;

class Passage
{
private: 
	string width;
	string length;
	bool hasDoor;
	bool hasSidePassage;
	bool hasTurn;
	

public:
	Passage(string width = "10 ft. ", string length = "40 ft.")
	{
		setWidth(width);
		setLength(length);
	}

	void setWidth(string widthSize)
	{
		width = widthSize;
	}

	void setLength(string lengthSize)
	{
		length = lengthSize;
	}

	string getWidth()
	{
		return width;
	}

	string getLength()
	{
		return length;
	}
	
	string toString()
	{
		
	}

	
};