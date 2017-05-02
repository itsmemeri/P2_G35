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
#include "Header.h"

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

//Creamos la variable puntuacion
int puntuacion;

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

	//bucle para obtener el unordered_map
	while (getline(fentrada, linea))
	{
		//find
		espacio = linea.find("=");
		mas = linea.find("+");
		fin = linea.find("\n");

		longitud = espacio - 1;
		element = linea.substr(inicio, longitud);
		inicio = espacio + 2;
		longitud = (mas - 1) - (espacio + 2);
		key1.first = linea.substr(inicio, longitud);
		inicio = mas + 2;
		longitud = fin - inicio;
		key1.second = linea.substr(inicio);
		inicio = 0;

		combinaciones_map[key1] = {element};
	}

	//cerrar archivo
	fentrada.close();
}
std::vector <std::string> basics({"Air", "Earth", "Fire", "Water"});
std::vector <std::string> elements (basics);

//funcion para imprimir los nuevos elementos
void Print()
{
	std::cout << "Your score is: " << puntuacion << std::endl;
	std::cout << "You have these elements: " << std::endl;
	for (int i = 0; i < elements.size(); i++)
	{
		std::cout << i + 1 << " " << elements[i] << std::endl;
	}
	
}
//Declaramos que existe la funcion delete
void Delete(int pos);
//void NewElement();
//funcion combinar
void Combinar(int pos1, int pos2)
{
	key aux;
	if (pos1 != pos2)
	{
		aux.first = elements[pos1-1];
		aux.second = elements[pos2-1];
		auto search = combinaciones_map.find({ aux.first, aux.second });
		
		if (!combinaciones_map.count(aux))
		{
			aux.first = elements[pos2 - 1];
			aux.second = elements[pos1 - 1];
			search = combinaciones_map.find({ aux.first, aux.second });		
		}		
		elements.insert(elements.end(), search->second);
		Delete(pos1);
		Delete(pos2);
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

//funcion clean
void Clean()
{
	Sort();
	elements.erase(unique(elements.begin(), elements.end()), elements.end());
}
void Help() 
{
		std::cout << "--------------------------------------------------------------" << std::endl;
		std::cout << "                       P2_G35's ALCHEMY                       " << std::endl;
		std::cout << "--------------------------------------------------------------" << std::endl;
		std::cout << "- Enter the word 'combine' and two numbers of your elements list to combine them." << std::endl;
		std::cout << "- Enter the word 'add' and the number of an element to add a new instance of that element." << std::endl;
		std::cout << "- Enter 'add basics' to add new instances of the 4 basic elements." << std::endl;
		std::cout << "- Enter the word 'delete' and the number of an element to erase it from your list." << std::endl;
		std::cout << "- Enter the word 'info' and the number of an element to get information about it in the explorer." << std::endl;
		std::cout << "- Enter the word 'sort' to sort by alphabetical order the elements in the list." << std::endl;
		std::cout << "- Enter the word 'clean' to delete all the instances of repeated elements." << std::endl;
		std::cout << "- Enter the word 'help' to show this tutorial." << std::endl;
		std::cout << std::endl;
		
}

//funcion elemento nuevo
void NewElement(std::string element)
{
	bool repetido = false;

	for (int i = 0; i < elements.size() - 1; i++)
	{
		if (elements.end() == elements.begin() + i)
		{
			repetido = true;
		}
	}
	if (!repetido)
	{
		puntuacion++;
	}
}

void main()
{
	std::string input;
	Combinaciones();
	Help();
	Print();
	if (combinaciones_map.size() != 390)
	{
		system("pause");
	}

	while (puntuacion < 395)
	{
		if (input == "help")
		{
			Help();
		}
		std::cin >> input;
		system("cls");
		if (input == "add")
		{
			std::string aux;
			std::cin >> aux;
			if (aux == "basics")
			{
				Addbasics();
			}
			else /*if (aux == "%d" )*/
			{				
				int num;
				num = stoi(aux);
				Add(num);
			}
			/*else {
				std::cout << "Error" << std::endl;
			}*/
		}
		else if (input == "info")
		{
			std::string aux;
			std::cin >> aux;
			int num;
			num = std::stoi(aux);
			Info(num);
		}
		else if (input == "delete")
		{
			std::string aux;
			std::cin >> aux;
			int num;
			num = std::stoi(aux);
			Delete(num);
		}
		else if (input == "clean")
		{
			Clean();
		}
		else if (input == "sort")
		{
			Sort();
		}
		else if (input == "combine") 
		{
			int aux1;
			int aux2;
			std::cin >> aux1 >> aux2;	
			Combinar(aux1,aux2);	
		}

		else 
		{ 
			std::cout << "Error" << std::endl;
		}
		Print();
	}
}