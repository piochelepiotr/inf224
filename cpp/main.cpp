#include <iostream>
#include "image.h"
#include "group.h"

int main()
{
    Group group("Images");
    MediaPtr image1(new Image("image char", "char.jpg",1,1));
    MediaPtr image2(new Image("image voiture", "voiture.png",1,1));
    group.push_back(image1);
    group.push_back(image2);
    group.display();
	return 0;
}
