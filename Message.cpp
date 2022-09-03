#include "Message.h"

Message::Message(std::string text) {
	this->text = text;
}

std::string Message::getText() {
	return this->text;
}