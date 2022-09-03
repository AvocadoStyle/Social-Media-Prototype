#include "USocial.h"
#include "User.h"
#include <exception>
#include <iostream>
//

int main() {



	/*run one*/
	//std::cout << "starts from here" << std::endl;
	//USocial us;

	//User* u1 = us.registerUser("Eden");
	//User* u2 = us.registerUser("Nir", true);
	//User* u3 = us.registerUser("Fenny", true);
	//User* u4 = us.registerUser("Liron");
	//User* u5 = us.registerUser("Yahav", true);
	//us.getUserById(2);

	///*user 1 to 3 posts*/
	//u1->post("Hello World!");
	//u2->post("Hey man!1");
	//u2->post("Hey man!2");
	//u2->post("Hey man!3");
	//u3->post("tov meod!!1");
	//u3->post("tov meod!!2");
	//u3->post("tov meod!!3");
	//u3->post("tov meod!!4", new Video());

	///*user 1 to 3 friends*/
	//u1->addFriend(u2);
	//u1->addFriend(u3);
	//u2->addFriend(u1);
	//u2->addFriend(u3);
	//u3->addFriend(u1);
	//u3->addFriend(u2);
	///*view posts*/
	//u1->viewFriendsPosts();
	//u2->viewFriendsPosts();
	//u5->viewFriendsPosts();

	//u1->sendMessage(u2, new Message("you are good friend!"));
	//u1->sendMessage(u2, new Message("and one of the best!"));
	//u2->viewReceivedMessages();
	//u3->sendMessage(u2, new Message("i love your panties smell"));
	//u2->viewReceivedMessages();


	//u2->sendMessage(u4, new Message("needs to be sent"));


	///*send message to non friend*/
	///*regular user*/
	//try {
	//	u1->sendMessage(u4, new Message("will not be sent because u4 is not friend of u1"));
	//} catch (const std::exception& e) {
	//	std::cout << "error: " << e.what() << std::endl;
	//}
	///*buisness user*/



	///* make exception same friend can't be added twice */
	////try {
	////	u1->addFriend(u2);
	////} catch (const std::exception& e) {
	////	std::cout << "error: " << e.what() << std::endl;
	////}










	/*run two*/
	USocial us;
	User* u1 = us.registerUser("Liron");
	User* u2 = us.registerUser("Yahav");
	User* u3 = us.registerUser("Shachaf");
	User* u4 = us.registerUser("Tsur", true);
	User* u5 = us.registerUser("Elit");
	u1->post("Hello world!");
	u2->post("I'm having a great time here :)", new Audio());
	u3->post("This is awesome!", new Photo());
	u5->addFriend(u1);
	u5->addFriend(u2);
	u5->viewFriendsPosts(); // should see only u1, u2 s' posts
	u4->sendMessage(u5, new Message("Buy Falafel!"));
	u5->viewReceivedMessages();
	try
	{
		u3->sendMessage(u5, new Message("All your base are belong us"));
	}
	catch (const std::exception& e)
	{
		std::cout << "error: " << e.what() << std::endl;
	}
	u5->viewReceivedMessages();
	u3->addFriend(u5);
	u3->sendMessage(u5, new Message("All your base are belong to us"));
	u5->viewReceivedMessages();





	return 0;
}