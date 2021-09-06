#include "dbmanager.hpp"
#include <string>

DbManager::DbManager()
{

	try
	{
		conn = sqlite3_open("database.db", &db);

		if (conn != 1)
		{
			std::cout << "[+] Connected To Database" << std::endl;
		}

	}
	catch (...)
	{
		std::cerr << sqlite3_errmsg(db) << std::endl;
	}
}

void DbManager::signupUser(const std::string& email, const std::string& passwd)
{
		try
		{
			std::string query = ("INSERT INTO Accounts(Email, Password) VALUES(email, passwd)");
			conn = sqlite3_exec(db, query.c_str(), NULL, 0, &errMsg);

			if (conn == SQLITE_OK)
			{
				std::cout << "Account Successfully Created." << std::endl;
			}
		}
		catch (...)
		{
			std::cerr << "[!] Failed To Create User Account."<< std::endl;
			sqlite3_free(errMsg);
		}
}
DbManager::~DbManager()
{
	sqlite3_close(db);
}