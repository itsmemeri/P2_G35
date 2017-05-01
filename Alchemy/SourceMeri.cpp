#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>

void Combinaciones()
{
	//leer y guardar el fichero en un unordered_map
	std::ifstream fentrada;
	fentrada.open("elements.dat");
	std::string linea;
	while (getline(fentrada, linea))
	{
		std::cout << linea << std::endl;
	}
}

void main()
{
	Combinaciones();
}