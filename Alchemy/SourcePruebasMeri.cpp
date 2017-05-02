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
}

void Clean()
{
	Sort();
	for (int i = 0; i < elements.size(); i++)
	{
	for (int j = elements.size() - 1; j > i; j--)
	{
	if (elements[i] == elements [j])
	{
	Delete(j);
	}
	}
	}

	elements.erase(unique(elements.begin(), elements.end()), elements.end());
}
void Combinar(int pos1, int pos2)
{
key aux;
if (pos1 != pos2)
{
bool existe;
aux.first = elements[pos1-1];
aux.second = elements[pos2-1];

auto search = combinaciones_map.find({ aux.first, aux.second });
if (it)
{

}


elements.insert(elements.end(), search -> second);
Delete(pos2);
Delete(pos1);
}
else
{
std::cout << "Error" << std::endl;
}
}*/