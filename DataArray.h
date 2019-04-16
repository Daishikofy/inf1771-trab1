#include <vector>
#include <string>

struct Client
{
	int id;
	int x;
	int y;
	int demand;
}

class DataArray 
{
public:
	ReadFile (std::vector<Client>& clients, int& capacity, int& nTucks, std::string filePath );
private:
	FillClient (std::string line);
	PrintClient (Client client);
}; 
