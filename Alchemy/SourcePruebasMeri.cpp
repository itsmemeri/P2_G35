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