
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
	delete [] animals;
	delete [] passports;
	delete background;
	delete background_texture;
	delete character;
	delete passport;
	

}

bool Game::init()
{
	//newAnimal();
	character = new sf::Sprite;
	passport = new sf::Sprite;
	background = new sf::Sprite;
	background_texture = new sf::Texture;
	


	if (!background_texture->loadFromFile("../Data/Images/background.jpg"))
	{
		std::cout << "no background \n";
	}

	auto TextureSize = background_texture->getSize();
	const sf::Vector2u& WindowSize = window.getSize();
	float scaleX = (float)WindowSize.x / float(TextureSize.x);
	float scaleY = (float)WindowSize.y / float(TextureSize.y);
	background->setTexture(*background_texture);
	background->setScale(scaleX, scaleY);

	
	


	if (!animals->loadFromFile("../Data/Critter Crossing Customs/penguin.png"))
	{
		std::cout << "penguin ded :( \n";
	}

	


  return true;
}

void Game::update(float dt)
{
	
}

void Game::newAnimal()
{
	passport_accepted = false;
	passport_rejected = false;

	int animal_index = rand() % 3;
	int passport_index = rand() % 3;
	if (animal_index == passport_index)
	{
		should_accept = true;
	}
	else
	{
		should_accept = false;
	}

	character->setTexture(animals[animal_index], true);
	character->setScale(1.8, 1.8);
	character->setPosition(window.getSize().x / 12, window.getSize().y / 12);

	passport->setTexture(passports[passport_index]);
	passport->setScale(0.6, 0.6);
	passport->setPosition(window.getSize().x / 2, window.getSize().y / 3);

}

void Game::render()
{
	window.draw(*background);
	window.draw(*character);
}

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);


}

void Game::keyPressed(sf::Event event)
{

}


