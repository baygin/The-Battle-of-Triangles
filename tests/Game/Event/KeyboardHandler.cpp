#include "../../../include/Game/Event/KeyboardHandler.hpp"

int main()
{
    /**
     * @brief Init the keyboard event handler
     */
    Game::Event::KeyboardHandler *handler = new Game::Event::KeyboardHandler();

    /**
     * @brief Init a keyboard event
     */
    Game::Event::Keyboard *event = new Game::Event::Keyboard(Game::Event::Keys::Enter);
    event->SetFunction([]
                       { printf("Yup! The 'Enter' event is working!\n"); });

    /**
     * @brief Init another keyboard event
     */
    Game::Event::Keyboard *event2 = new Game::Event::Keyboard(Game::Event::Keys::W);
    event2->SetFunction([]
                       { printf("Yup! The 'W' event is working!\n"); });

    /**
     * @brief Add events to the event handler
     *
     */
    handler->AddEvent(event);
    handler->AddEvent(event2);

    /**
     * @brief It will work
     */
    handler->Handle(Game::Event::Keys::Enter);

    /**
     * @brief It won't work
     */
    handler->Handle(Game::Event::Keys::S);

    /**
     * @brief It will work
     */
    handler->Handle(Game::Event::Keys::W);
}