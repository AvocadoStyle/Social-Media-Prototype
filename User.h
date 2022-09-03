#ifndef __USER_H__
#define __USER_H__

#include <string>
#include <list>
#include "USocial.h"
#include "Message.h"
#include "Post.h"
#include <algorithm>

class User {
private:
protected:
	friend class USocial;
	USocial *us;
	unsigned long id;
	std::string name;
	std::list <unsigned long> friends;
	std::list <Post*> posts;
	std::list <Message*> receivedMsgs;
	User();
	~User();
	User(unsigned long, std::string, USocial*);

public:
	unsigned long getId();
	std::string getName();
	void addFriend(User*);
	void removeFriend(User*);
	void post(std::string);
	void post(std::string, Media*);
	std::list<Post*> getPosts();
	void viewFriendsPosts();
	void receiveMessage(Message*);
	virtual void sendMessage(User*, Message*);
	void viewReceivedMessages();
private:
	void _deletePosts();
	void _deleteReceivedMsgs();

	void _printPosts(std::list<Post*>);

	bool _isFriendOf(User*);
};

class BusinessUser : protected User {
public:
	void sendMessage(User*, Message*);
protected:
	friend class USocial;
	BusinessUser(unsigned long, std::string, USocial*);
};

#endif