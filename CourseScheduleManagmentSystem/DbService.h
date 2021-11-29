using namespace std;
#include <string>

class DbContext
{
public:
	
	string IntToString(int a);
	static int callback(void* data, int argc, char** argv, char** azColName);

};