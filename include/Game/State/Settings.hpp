#ifndef GAME_STATE_SETTINGS_H
#define GAME_STATE_SETTINGS_H

namespace Game
{
    namespace State
    {
        class Settings
        {
        private:
            bool Running = true;

        public:
            bool GetRunning();
            void SetRunning(bool Running);
        };
    }
}

#endif // !GAME_STATE_SETTINGS_H