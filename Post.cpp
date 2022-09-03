#include "Post.h"


Post::Post(std::string text) {
	this->text = text;
	this->media = NULL;
}

Post::Post(std::string text, Media* media) {
	this->text = text;
	this->media = media;
}

Post::~Post() {
	delete media;
}

std::string Post::getText() {
	return this->text;
}

Media* Post::getMedia() {
	return this->media;
}