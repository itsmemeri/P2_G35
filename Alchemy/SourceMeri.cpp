#include <istream>
#include <ostream>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <utility>


//para que no de error con el hash
struct pair_hash {
	template <class T1, class T2>
	std::size_t operator () (const std::pair<T1, T2> &p) const {
		auto h1 = std::hash<T1>{}(p.first);
		auto h2 = std::hash<T2>{}(p.second);
		return h1 ^ h2;
	}
};
//creamos el pair
using key = std::pair <std::string, std::string>;


void Combinaciones()
{
	//abrir archivo
	std::ifstream fentrada;
	fentrada.open("elements.dat");
	//leer archivo y guardarlo
	std::string linea;
	//creamos la variable que usaremos de elemento
	std::string element;
	//creamos el map
	std::unordered_map <key, std::string, pair_hash> combinaciones_map;
	std::pair<std::string, std::string> key;
	int espacio, mas, fin, longitud, inicio;
	inicio = 0;
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
		key.first = linea.substr(inicio, longitud);
		inicio = mas + 1;
		longitud = fin - inicio;
		key.second = linea.substr(inicio, longitud);
		inicio = 0;

		combinaciones_map[key] = element;
		std::cout << element << "=" << key.first << "+" << key.second << std::endl;	
	}
		
	//cerrar archivo
	fentrada.close();
}
	


void main()
{
	Combinaciones();
}