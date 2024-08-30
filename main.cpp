#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "NPC.h"
#include "Weapon.h"
#include "Armor.h"

int main()
{
    
    Player user;
    Weapon x("x", 10, 0, 999);

    user.get_inventory().add_item(&x);
    user.get_inventory().display_inventory();


    user.get_weapon_slot()->display_item();
    user.set_weapon_slot(0);



    return 0;
}


/* 
    // OPEN REGULAR SFML WINDOW

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "KDX RPG");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }
*/