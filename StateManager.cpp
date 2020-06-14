#include "StateManager.h"

void hn::StateManager::add_state(hn::GameState* state)
{
	states.push(state);
	states.top()->init();
}

void hn::StateManager::back()
{
	states.pop();
}

void hn::StateManager::loop()
{
	states.top()->loop();
}

void hn::StateManager::render(sf::RenderWindow* window)
{
	states.top()->render(window);
}

void hn::StateManager::key_pressed(int key)
{
	states.top()->key_pressed(key);
}

void hn::StateManager::key_released(int key)
{
	states.top()->key_released(key);
}
