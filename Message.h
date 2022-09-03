#ifndef __MSG_H__
#define __MSG_H__

#include <string>

class Message {
private:
	std::string text;
public:
	Message(std::string);
	std::string getText();
};

#endif
