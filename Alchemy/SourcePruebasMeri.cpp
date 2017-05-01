/*
while (getline(fentrada, linea))
{
	do
	{
		//element += getchar();
		getline(fentrada, element);
	} while (getchar() != '=');

	do
	{
		//key.first += getchar();
		getline(fentrada, key.first);
	} while (getchar() != '+');
	do
	{
		//key.second += getchar();
		getline(fentrada, key.second);
	} while (getchar() != '\n');

	combinaciones_map[key] = element;
	//std::cout << linea << std::endl;
	std::cout << element << "=" << key.first << "+" << key.second << std::endl;
	contador++;
}

void Delete()
{
int posicion;
std::cin >> posicion;
element.erase(element.begin() + posicion);
}

void Info()
{
int posicion;
std::cin >> posicion;
std::string url;
url = "https://en.wikipedia.org/wiki/" + element[posicion]
ShellExecuteA(nullptr, "open", url.c_str(), nullptr, nullptr, SW_SHOWNORMAL);
}*/