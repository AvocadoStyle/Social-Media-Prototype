#ifndef __USOCIAL_H__ //if this macro not defined do the following code
#define __USOCIAL_H__

#include "User.h"
#include <map>
#include <iostream>

class USocial {
private:
	friend class User;
	unsigned long current_id = 1;
	std::map<unsigned long, User*> users;
public:
	~USocial();
	User* registerUser(std::string);
	User* registerUser(std::string, bool);
	void removeUser(User*);
	User* getUserById(unsigned long);
};




#endif