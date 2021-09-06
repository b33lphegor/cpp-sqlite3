#ifndef DBMANAGER_HPP
#define DBMANAGER_HPP

#include <sqlite3.h>
#include <iostream>

class DbManager
{
	private:
		sqlite3 *db;
		char *errMsg;
		int conn;

		static int callBack(void *data, int argc,char **argv, char **azColName)
		{
			fprintf(stderr, "%s", (const char *)data);

			int i;
			for (i = 0; i < argc; i++)
			{
				printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL"); 
			}
			printf("\n");
			return 1;
		}
	public:
		// connect to database
		DbManager();
		// kill connection to database
		~DbManager();
		// signup new user
		void signupUser(const std::string& email,const std::string& passwd);
		// login existing user
		void loginUser(const std::string& email,const std::string& passwd);
};

#endif
