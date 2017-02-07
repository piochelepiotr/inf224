#include <iostream>
#include "image.h"

int main()
{
	Media *medias [] = { new Image("photo char", "char.jpg",1,1),
		new Image("photo voiture","voiture.png",1,1)};
	int length = 2;
	//Media *image = new Image("name","~/inf224/voiture.png");
	//image->play();
	for(int i = 0 ; i < length ; i++)
	{
		medias[i]->play();
	}
	return 0;
}
