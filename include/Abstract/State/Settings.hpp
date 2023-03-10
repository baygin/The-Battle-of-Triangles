#ifndef ABSTRACT_STATE_SETTINGS_H
#define ABSTRACT_STATE_SETTINGS_H

#include "../../Game/State/Settings.hpp"

namespace Abstract
{
    namespace State
    {
        class Settings
        {
        protected:
            Game::State::Settings *Settings;

        public:
            void SetSettings(Game::State::Settings *Settings)
            {
                this->Settings = Settings;
            }
            Game::State::Settings *GetSettings()
            {
                return this->Settings;
            }
        };
    } // namespace State

}

#endif // !ABSTRACT_STATE_SETTINGS_H