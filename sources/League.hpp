#pragma once

#include "Game.hpp"
#include "Team.hpp"
#include "Schedule.hpp"
#include <iostream>
#include <set>
#include <stdexcept>

namespace ariel{
    class League{
        public:
            enum Mode{
                win=0,
                points
            };
        private:
            std::vector<Team *> teams;
            bool leagueIsOver;
            void sortLeague(enum Mode mode);

        public:
            League();

            League(std::vector<Team *> other);

            std::vector<Team *> getTeams(){
                return this->teams;
            }

            void startLeague();
            void showTable();
            
            void showStatistics(enum Mode mode);
    };
}