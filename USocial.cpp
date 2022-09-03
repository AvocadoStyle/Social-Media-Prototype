#include "USocial.h"

User* USocial::getUserById(unsigned long id) {
	auto it = this->users.find(id);
	if (it == users.end()) {
		throw "user not found!";
	}
	else {
		return it->second;
	}
};

void USocial::removeUser(User* user) {
	delete user;
};

User* USocial::registerUser(std::string name, bool userBusiness) {
	if (userBusiness) {
		User* u = new BusinessUser(this->current_id, name, this);
		this->users.insert(std::pair<unsigned long, User*>(this->current_id++, u));
		return u;
	} else{
		return this->registerUser(name);
	}
};
User* USocial::registerUser(std::string name) {
	User* u = new User(this->current_id, name, this);
	this->users.insert(std::pair<unsigned long, User*>(this->current_id++, u));
	return u;
};

USocial::~USocial() {
	std::map<unsigned long, User*>::iterator it;
	it = this->users.begin();
	for (it;it != this->users.end(); ++it) {
		delete it->second;
	}
}