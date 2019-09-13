#pragma once
#include<string>
#include"Vector.h"
#include<vector>

class Menu {
private:
	std::vector<double>Coordinates;
	int ControlVar;
	std::string  Str;
	int ArithSign;
public:
	void MenuCall();
	void GetStr();
	void ParsStr();
	void Schect();
	void FindLengthStr();
	void SetLength();
};

