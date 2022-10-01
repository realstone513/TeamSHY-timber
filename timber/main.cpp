﻿#include <SFML/Graphics.hpp>
#include <iostream>
#include <list>

#include "SpriteGameObject.h"
#include "Player.h"
#include "Tree.h"

#include "ResourceManager.h"
#include "InputManager.h"
#include "UIManager.h"

#define X 1920
#define Y 1080

using namespace std;
using namespace sf;

int main()
{
   
	VideoMode vm(1920, 1080);
	RenderWindow window(vm, "timber", Style::Default);
<<<<<<< HEAD
	list<SpriteGameObject*> gameObjectList;
    auto resourceMgr = ResourceManager::GetInstance();
    gameObjectList.push_back(new SpriteGameObject(*resourceMgr->GetTexture("graphics/background.png")));
    //
=======
    list<SpriteGameObject*> gameObjectList;
    gameObjectList.push_back(new SpriteGameObject(RMI->GetTexture("graphics/background.png")));
>>>>>>> 17c2a126f8e80abbdbd4babb06a339e066adf603

    UIManager um(RMI->GetFont("fonts/KOMIKAP_.ttf"));

<<<<<<< HEAD
    Text messageText;
    Text titleText;
    messageText.setFont(font);
    titleText.setFont(font);
    messageText.setCharacterSize(75);
    titleText.setCharacterSize(225);
    messageText.setFillColor(Color::White);
    titleText.setFillColor(Color::Cyan);
    messageText.setString("Press Enter to start!");
    titleText.setString("< Timber >");
    Vector2u size = window.getSize();
    messageText.setPosition(size.x * 0.5f, size.y * 0.5f);
    titleText.setPosition(size.x * 0.5f, size.y * 0.25f);
    Utils::SetOrigin(messageText, Origins::MC);
    Utils::SetOrigin(titleText, Origins::TC);
    //
    Text menuText;
    menuText.setFont(font);
    menuText.setCharacterSize(75);
    menuText.setFillColor(Color::White);
    menuText.setString("Menu\n1P\n2P");
    menuText.setPosition(size.x * 0.5f, size.y * 0.5f);
    Utils::SetOrigin(menuText, Origins::MC);
    //
=======
    Vector2u size = window.getSize();

    um.SetTextUI("Press Enter to start!", "press enter");
    um.GetTextUI("press enter")->setPosition({ 500, 600 });
    
    um.SetTextUI("Timber!", "title", 150, Color::Yellow);
    um.GetTextUI("title")->setPosition({ 700, 400 });
    
    um.SetTextUI("Menu");
    um.GetTextUI("Menu")->setPosition({ size.x * 0.5f, size.y * 0.5f });
>>>>>>> 17c2a126f8e80abbdbd4babb06a339e066adf603

    Clock clock;
    bool SelectMenu = false;
    bool PlayGame = false;
    bool Title = true;
    bool run = true;
    int gamemode = 0;
    while ( window.isOpen() )
    {
        //sceneManager.Init();
        Time dt = clock.restart();
        Event ev;

        //Title Scene
        while ( Title )
        {
            Time dt = clock.restart();
            Event ev;
            InputManager::ClearInput();

            while ( window.pollEvent(ev) )
            {
                InputManager::UpdateInput(ev);
            }

            if ( InputManager::GetKeyDown(Keyboard::Key::Return) )
            {
                SelectMenu = true;
                Title = false;
                break;
            }
            if ( InputManager::GetKeyDown(Keyboard::Key::Escape) )
            {
                window.close();
                break;
            }

            float deltaTime = dt.asSeconds();

            //Update
            for ( auto go : gameObjectList )
            {
                go->Update(deltaTime);
            }

            //Draw
            window.clear();
            for ( auto go : gameObjectList )
            {
                go->Draw(window);
            }
<<<<<<< HEAD
            window.draw(titleText);
            window.draw(messageText);
=======
            window.draw(*(um.GetTextUI("title")));
            window.draw(*(um.GetTextUI("press enter")));
>>>>>>> 17c2a126f8e80abbdbd4babb06a339e066adf603
            window.display();
        }


        //Menu Scene
        while ( SelectMenu )
        {
            Time dt = clock.restart();
            Event ev;
            InputManager::ClearInput();
            while ( window.pollEvent(ev) )
            {
                InputManager::UpdateInput(ev);
            }

            if ( InputManager::GetKeyDown(Keyboard::Key::Escape) )
            {
                SelectMenu = false;
                Title = true;
            }
            if ( InputManager::GetKeyDown(Keyboard::Key::Up) )
            {
                gamemode = 1;
            }
            if ( InputManager::GetKeyDown(Keyboard::Key::Down) )
            {
                gamemode = 2;
            }
            //Menu()
            if ( Keyboard::isKeyPressed(Keyboard::Return) && gamemode != 0 )
            {

                SelectMenu = false;
                PlayGame = true;
            }


            float deltaTime = dt.asSeconds();

            //Update
            for ( auto go : gameObjectList )
            {

                go->Update(deltaTime);
            }

            //Draw
            window.clear();
            for ( auto go : gameObjectList )
            {
                go->Draw(window);
            }
            if ( gamemode == 1 )
            {
                um.GetTextUI("Menu")->setString("1P");
            }
            else if( gamemode == 2 )
            {
                um.GetTextUI("Menu")->setString("2P");
            }
            else
            {
                um.GetTextUI("Menu")->setString("Menu");
            }
            window.draw(*um.GetTextUI("Menu"));
            window.display();
        }

        //Game Scene
        if( PlayGame && (gamemode == 1 || gamemode == 2))
        {
            if ( gamemode == 1 )
			{
				Tree* tree = new Tree(RMI->GetTexture("graphics/tree.png"), gamemode, 1);
				tree->SetPosition({ 960, 900 });
				gameObjectList.push_back(tree);
				Player* player1 = new Player(RMI->GetTexture("graphics/player_green.png"), gamemode, 1, tree->GetPosition());
				gameObjectList.push_back(player1);
			}
			else
			{
				Tree* tree1 = new Tree(RMI->GetTexture("graphics/2Ptree.png"), gamemode, 1);
				tree1->SetPosition({ 480, 900 });
				gameObjectList.push_back(tree1);
				Tree* tree2 = new Tree(RMI->GetTexture("graphics/2Ptree.png"), gamemode, 2);
				tree2->SetPosition({ 1440, 900 });
				gameObjectList.push_back(tree2);
				Player* player1 = new Player(RMI->GetTexture("graphics/player_green.png"), gamemode, 1, tree1->GetPosition());
				gameObjectList.push_back(player1);
				Player* player2 = new Player(RMI->GetTexture("graphics/player_red.png"), gamemode, 2, tree2->GetPosition());
				gameObjectList.push_back(player2);
			}
            for ( auto i : gameObjectList )
			{
				i->Init();
			}
            while ( PlayGame )
            {
                Time dt = clock.restart(); //이전 업데이트 시간과 현재 업데이트 시간 차이 기록

                Event ev;
                InputManager::ClearInput();
                while ( window.pollEvent(ev) )
                {
                    InputManager::UpdateInput(ev);
                }
                float deltaTime = dt.asSeconds(); //isPause ? 0.f : dt.asSeconds();
                for ( auto i : gameObjectList )
                {
                    i->Update(deltaTime);
                }
                for ( auto i : gameObjectList )
                {
                    i->Draw(window);
                }
                window.display();
            }
           
        }       
    }
    for ( auto go : gameObjectList )
    {
        go->Release();
        delete go;
    }
    gameObjectList.clear();
    return 0;
}