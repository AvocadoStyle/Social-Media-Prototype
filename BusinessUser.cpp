#include "User.h"



BusinessUser::BusinessUser(unsigned long id, std::string name, USocial* us) : User(id, name, us) {
}

void BusinessUser::sendMessage(User* other, Message* message) {
	other->receiveMessage(message);
}