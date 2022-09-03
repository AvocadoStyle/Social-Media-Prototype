#ifndef __POST_H__
#define __POST_H__

#include <string>

#include "Media.h"

class Post {
private:
	std::string text;
	Media* media;

public:
	Post(std::string);
	Post(std::string, Media*);
	std::string getText();
	Media* getMedia();
	~Post();
};









#endif