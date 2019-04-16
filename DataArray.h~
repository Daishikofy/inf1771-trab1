#include <vector>
#include <string>

struct Client
{
	int id;
	int x;
	int y;
	int demand;
};

class DataArray 
{
public:
	void ReadFile (std::vector<Client>& clients, int& capacity, int& nTucks, std::string filePath );
private:
	Client FillClient (std::string line);
	void PrintClient (Client client);
}; 
