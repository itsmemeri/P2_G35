#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>
#include <Windows.h>


//Para que no de error con el hash
struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);
		return h1 ^ h2;
	}
};
//Creamos el pair
using key = std::pair <std::string, std::string>;

//Creamos el unordered_map
std::unordered_map <key, std::string, pair_hash> combinaciones_map;

//Leer y guardar archivo
void Combinaciones()
{
	//abrir archivo
	std::ifstream fentrada;
	fentrada.open("elements.dat");

	//leer archivo y guardarlo
	std::string linea;

	//creamos la variable que usaremos de elemento
	std::string element;

	//creamos variables necesarias
	int espacio, mas, fin, longitud, inicio;
	inicio = 0;
	key key1;
	while (getline(fentrada, linea))
	{
		//find
		espacio = linea.find("=");
		mas = linea.find("+");
		fin = linea.find("\n");

		longitud = espacio - inicio;
		element = linea.substr(inicio, longitud);
		inicio = espacio + 1;
		longitud = mas - inicio;
		key1.first = linea.substr(inicio, longitud);
		inicio = mas + 1;
		longitud = fin - inicio;
		key1.second = linea.substr(inicio, longitud);
		inicio = 0;

		combinaciones_map[key1] = element;
		//std::cout << element << "=" << key.first << "+" << key.second << std::endl;	
	}
	//cerrar archivo
	fentrada.close();
}
std::vector <std::string> basics({"Air", "Earth", "Fire", "Water"});
std::vector <std::string> elements({"Air", "Earth", "Fire", "Water"});

//funcion para imprimir los nuevos elementos
void Print()
{
	for (int i = 0; i < elements.size(); i++)
	{
		std::cout << i + 1 << " " << elements[i] << std::endl;
	}
}
//Declaramos que existe la funcion delete
void Delete(int pos);

//funcion combinar
void Combinar(int pos1, int pos2)
{
	key aux;
	if (pos1 != pos2)
	{
		
		aux.first = elements[pos1];
		aux.second = elements[pos2];
		elements.insert(elements.end(), combinaciones_map[aux]);
		Delete(pos2);
		Delete(pos1);
	}
	else
	{
		std::cout << "Error" << std::endl;
	}
}
//funcion add (DONE)
void Add(int pos)
{
	elements.insert(elements.end(), elements[pos - 1]);
}

//funcion add basics (DONE)
void Addbasics()
{
	for (int i = 0; i < 4; i++)
	{
		elements.insert(elements.end(), basics[i]);
	}
}

//funcion delete (DONE)
void Delete(int pos)
{
	elements.erase(elements.begin() + pos - 1);
}

//funcion info (DONE)
void Info(int pos)
{
	std::string url;
	url = "https://en.wikipedia.org/wiki/" + elements[pos - 1];
	ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}

//funcion sort (DONE)
void Sort()
{
	std::sort(elements.begin(), elements.end());
}

//funcion clean (DONE)
void Clean()
{
	for (int i = 0; i < elements.size() / 2; i++)
	{
		for (int j = i + 1; j < elements.size(); j++)
		{
			if (elements[i] == elements [j])
			{
				Delete(j);
			}
		}
	}
}

void main()
{
	//std::string input;
	Combinaciones();
	Addbasics();
//	Sort();
	//Print();
	//system ("cls");
	//Clean();
	Print();
	system("cls");
	Combinar(1, 2);
	Print();
	//Info(3);
	
}