#include"Menu.h"
void Menu::MenuCall() {
	do {
		std::cout << "1 - Нахождение длины вектора " << std::endl;
		std::cout << "2 - Арифметические операции над векторами " << std::endl;
		std::cout << "3 - Выход из программы " << std::endl;
		std::cin >> ControlVar;
		switch (ControlVar)
		{
		case 1:
			Menu::FindLengthStr();
			Menu::ParsStr();
			Menu::SetLength();
			break;
		case 2:
			Menu::GetStr();
			Menu::ParsStr();
			Schect();
			break;
		case 3:
			std::cout << "Досвидания " << std::endl;
			break;
		default:
			std::cout << ControlVar << std::endl;
			std::cout << "Что-то введено не верно,попробуйте ввести ещё раз" << std::endl;
			break;
		}
	} while (ControlVar != 3);
}
void Menu::GetStr() {
	std::cout << "Введите координаты векторов и арифметическое действие над ними " << std::endl;
	std::cout << "Пример : (3,4,5) + (3,2,3) " << std::endl;
	std::getline(std::cin, Str);
	std::getline(std::cin, Str);
}
void Menu::ParsStr() {
	bool IsCoordinate;
	std::vector<std::string> StrCoordinates;
	int NumCount;
	NumCount = 0;
	Coordinates.clear();
	IsCoordinate = false;
	for (int i = 0; i < Str.size(); i++) {
		if (Str[i] == ' ') {
			continue;
		}
		if (Str[i] == '=') {
			continue;
		}
		switch (Str[i]) {
		case '+':
			if (Str[(i + 1)] == '=') {
				ArithSign = 1;
			}
			else {
				ArithSign = 2;
			}
			break;
		case '-':
			if (Str[(i + 1)] == '=') {
				ArithSign = 3;
			}
			else {
				ArithSign = 4;
			}
			break;
		case '*':
			if (Str[(i + 1)] == '=') {
				ArithSign = 5;
			}
			else {
				ArithSign = 6;
			}
			IsCoordinate = true;
			continue;
			break;
		case '/':
			if (Str[(i + 1)] == '=') {
				ArithSign = 7;
			}
			else {
				ArithSign = 8;
			}
			IsCoordinate = true;
			continue;
			break;
		case '^':
			ArithSign = 9;
			break;
		case '>':
			if (Str[(i + 1)] == '=') {
				ArithSign = 10;
			}
			else {
				ArithSign = 11;
			}
			break;
		case '<':
			if (Str[(i + 1)] == '=') {
				ArithSign = 12;
			}
			else {
				ArithSign = 13;
			}
			break;
		}
		if (Str[i] == '(') {
			IsCoordinate = true;
			continue;
		}
		if (Str[i] == ')') {
			IsCoordinate = false;
			NumCount++;
			continue;
		}
		if (IsCoordinate) {
			if (Str[i] == ',') {
				NumCount++;
				continue;
			}
			if (Str[(i - 1)] == '(' || Str[(i - 1)] == ',' || ArithSign == 5 || ArithSign == 6 || ArithSign == 7 || ArithSign == 8) {
				StrCoordinates.push_back("");
			}
			StrCoordinates[NumCount] += Str[i];
		}
	}
	for (int i = 0; i < StrCoordinates.size(); i++) {
		std::cout << StrCoordinates[i] << std::endl;
		Coordinates.push_back(std::stod(StrCoordinates[i]));
	}
}
void Menu::Schect() {
	int k;
	Vector FirstVec(Coordinates[0], Coordinates[1], Coordinates[2]);
	Vector SecondVec, Vec;
	if (Coordinates.size() == 4) {
		k = Coordinates[3];
	}
	else {
		SecondVec.GetCoordinates(Coordinates[3], Coordinates[4], Coordinates[5]);
	}
	switch (ArithSign)
	{
	case 1:
		FirstVec += SecondVec;
		FirstVec.PutVector();
		break;
	case 2:
		Vec = FirstVec + SecondVec;
		Vec.PutVector();
		break;
	case 3:
		FirstVec -= SecondVec;
		FirstVec.PutVector();
		break;
	case 4:
		Vec = FirstVec - SecondVec;
		Vec.PutVector();
		break;
	case 5:
		if (Coordinates.size() > 4) {
			std::cout << (FirstVec *= SecondVec) << std::endl;
		}
		else {
			FirstVec *= k;
			FirstVec.PutVector();
		}
		break;
	case 6:
		if (Coordinates.size() > 4) {
			std::cout << FirstVec * SecondVec << std::endl;
		}
		else {
			Vec = FirstVec * k;
			Vec.PutVector();
		}
		break;
	case 7:
		FirstVec /= k;
		FirstVec.PutVector();
		break;
	case 8:
		Vec = FirstVec / k;
		Vec.PutVector();
		break;
	case 9:
		std::cout << (FirstVec ^ SecondVec) << std::endl;
		break;
	case 10:
		if (FirstVec >= SecondVec) {
			std::cout << "true" << std::endl;
		}
		else {
			std::cout << "false" << std::endl;
		}
		break;
	case 11:
		if (FirstVec > SecondVec) {
			std::cout << "true" << std::endl;
		}
		else {
			std::cout << "false" << std::endl;
		}
		break;
	case 12:
		if (FirstVec <= SecondVec) {
			std::cout << "true" << std::endl;
		}
		else {
			std::cout << "false" << std::endl;
		}
		break;
	case 13:
		if (FirstVec < SecondVec) {
			std::cout << "true" << std::endl;
		}
		else {
			std::cout << "false" << std::endl;
		}
		break;
	default:
		break;
	}
}
void Menu::FindLengthStr() {
	std::cout << "Введите координаты вектора" << std::endl;
	std::cout << "Пример : (3,4,5) " << std::endl;
	std::getline(std::cin, Str);
	std::getline(std::cin, Str);
}
void Menu::SetLength() {
	Vector Vec(Coordinates[0], Coordinates[1], Coordinates[2]);
	std::cout << "Длина вектора равна : " << Vec.FindLength() << std::endl;
	std::cout << std::endl;
}