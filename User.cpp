#include "User.h"

/*ctor*/
User::User(unsigned long id, std::string name, USocial* us) {
	this->id = id;
	this->name = name;
	this->us = us;
}

/*dtor*/
User::~User() {
	this->_deletePosts();
	this->_deleteReceivedMsgs();
	//delete us; maybe not.
}

/*dtor helpers*/
void User::_deletePosts() {
	//iteration by iterator:
	std::list<Post*>::iterator it;
	for (it = this->posts.begin(); it != this->posts.end(); ++it) {
		delete *it;
	}
}

void User::_deleteReceivedMsgs() {
	//iteration by iterator:
	std::list<Message*>::iterator it;
	for (it = this->receivedMsgs.begin(); it != this->receivedMsgs.end(); ++it) {
		delete* it;
	}
}

/*getters*/
unsigned long User::getId() {
	return this->id;
}

std::string User::getName() {
	return this->name;
}

std::list<Post*> User::getPosts() {
	return this->posts;
}

/*printers*/
void User::viewReceivedMessages() {
	std::list<Message*>::iterator it;
	std::cout << "messages sent to: " << this->getName() << std::endl;
	for (it = this->receivedMsgs.begin(); it != this->receivedMsgs.end(); ++it) {
		std::cout << (*it)->getText() << std::endl;
	}
}

void User::_printPosts(std::list<Post*> otherPosts) {
	/*getting through the posts and print them. will print the media if there is a media.*/
	std::list<Post*>::iterator it;
	for (it = otherPosts.begin(); it != otherPosts.end(); ++it) {
		std::cout << (*it)->getText();
		if ((*it)->getMedia()) { 
			(*it)->getMedia()->display();
		}
	}
}

void User::viewFriendsPosts() {
	std::list<unsigned long>::iterator it;
	std::cout << std::endl << "friends posts of " << this->getName() << ": " << std::endl;
	for (it = this->friends.begin(); it != this->friends.end(); ++it) {
		//us->getUserById(it->getId());
		unsigned int otherId = *it;
		User* other = us->getUserById(otherId);
		std::list<Post*> otherPosts = other->getPosts();
		std::cout << std::endl << "************************Posts of:  " << other->getName() << "  *************************" << std::endl;
		this->_printPosts(otherPosts);
	}
}




/* add/remove friend */
void User::addFriend(User* other) {
	int otherId = other->getId();
	bool found = std::find(this->friends.begin(), this->friends.end(), otherId) != this->friends.end();
	if (found) {
		throw std::invalid_argument("those users already friends");
	}
	this->friends.push_back(otherId);
}

void User::removeFriend(User* other) {
	this->friends.remove(other->id);
}


/*user post*/
void User::post(std::string text) {
	this->posts.push_back(new Post(text));
}

void User::post(std::string text, Media* media) {
	this->posts.push_back(new Post(text, media));
}

/*messages*/

void User::sendMessage(User* other, Message* message) {
	if (this->_isFriendOf(other)) {
		other->receiveMessage(message);
	} else {
		throw std::invalid_argument("they're not friends so they can't send messages");
	}
}

void User::receiveMessage(Message* message) {
	this->receivedMsgs.push_back(message);
}

bool User::_isFriendOf(User* other) {
	std::list<unsigned long>::iterator it;
	for (it = this->friends.begin(); it != this->friends.end(); ++it) {
		if (other->getId() == *it) {
			return true;
		}
	}
	return false;
}










