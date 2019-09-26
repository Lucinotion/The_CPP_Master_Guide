#include <iostream>

static const int x = 6;

int main()
{
	/*
		CONDITIONS
	*/

	// IF
	if (x > 5)
	{ // Main condition, when the content inside the () is true, the if body executes
		std::cout << "x is bigger than 5" << std::endl;
	}
	else if (x < 5)
	{ // Second case to be checked in case the other one fail
		std::cout << "x is less than 5" << std::endl;
	}
	else
	{ // If everything fails, the last else statement executes
		std::cout << "x is 5" << std::endl;
	}

	// New IF
	if (int y = 10; y > x) // The new syntax uses (inicialization; condition), so the scope of the inicialization line will be the body of the if and will be executed before anything else
	{
		std::cout << "x is less than y" << std::endl;
	}

	// SWITCH
	switch (x) // The variable must be a integer, a floating point value, a boolean, a character or a enum.
	{
	case 3: // Each of the cases in a switch statement must be constant values
	case 4:
	case 5:
		std::cout << "Estás en PRIMAVERA" << std::endl;
		break; // Break statements help you break out of the switch, without them you fall into the next case until exit
	case 6:
	case 7:
	case 8:
		std::cout << "Estás en VERANO" << std::endl;
		break;
	case 9:
	case 10:
	case 11:
		std::cout << "Estás en OTOÑO" << std::endl;
		break;
	case 12:
	case 1:
	case 2:
		std::cout << "Estás en INVIERNO" << std::endl;
		break;
	default:
		std::cout << "Estás en LA LUNA" << std::endl;
		break;
	}

	return 0;
}