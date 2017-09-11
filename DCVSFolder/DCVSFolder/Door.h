#ifndef Door_h
#define Door_h

#include <string>
using std::string;

class Door
{
	void setLocked(bool);

	void setMaterial(string);

	string getMaterial();

	string getLocked();

	bool isLocked();

	string toString();
};
#endif