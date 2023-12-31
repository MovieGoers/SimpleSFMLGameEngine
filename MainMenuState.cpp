#include <sstream>
#include "MainMenuState.hpp"
#include "DEFINITIONS.hpp"

#include <iostream>

namespace Sonar {
	MainMenuState::MainMenuState(GameDataRef data) : _data(data) {
	}

	void MainMenuState::Init() {
		this->_data->assets.LoadTexture("Background", MAIN_MENU_BACKGROUND_FILEPATH);
		this->_data->assets.LoadTexture("Game Title", MAIN_MENU_TITLE_FILEPATH);
		this->_data->assets.LoadTexture("Play Button", MAIN_MENU_PLAY_BUTTON_FILEPATH);
		this->_data->assets.LoadTexture("Play Button Outer", MAIN_MENU_PLAY_BUTTON_OUTER_FILEPATH);

		this->_background.setTexture(this->_data->assets.GetTexture("Background"));
		this->_title.setTexture(this->_data->assets.GetTexture("Game Title"));
		this->_playButton.setTexture(this->_data->assets.GetTexture("Play Button"));
		this->_PlayButtonOuter.setTexture(this->_data->assets.GetTexture("Play Button Outer"));

		this->_playButton.setPosition((SCREEN_WIDTH / 2) - (this->_playButton.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_playButton.getGlobalBounds().height / 2));
		this->_PlayButtonOuter.setPosition((SCREEN_WIDTH / 2) - (this->_PlayButtonOuter.getGlobalBounds().width / 2), (SCREEN_HEIGHT / 2) - (this->_PlayButtonOuter.getGlobalBounds().height / 2));
		this->_title.setPosition((SCREEN_WIDTH / 2) - (this->_title.getGlobalBounds().width / 2), this->_title.getGlobalBounds().height / 10);
	}

	void MainMenuState::HandleInput() {
		sf::Event event;
		while (this->_data->window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				this->_data->window.close();
			}

			if (this->_data->input.IsSpriteClicked(this->_playButton, sf::Mouse::Button::Left, this->_data->window)) {
				std::cout << "Go to Game Screen\n";
			}
		}
	}

	void MainMenuState::Update(float dt) {
		// 프레임 당 나타낼 효과, 애니메이션 등.
	}

	void MainMenuState::Draw(float dt) {
		//clear->draw->display
		this->_data->window.clear();
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_title);
		this->_data->window.draw(this->_playButton);
		this->_data->window.draw(this->_PlayButtonOuter);
		this->_data->window.display();
	}
}