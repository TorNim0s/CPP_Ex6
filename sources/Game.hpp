#pragma once

#include "Team.hpp"
#include <vector>


namespace ariel{

    struct Score{
        int homePoints;
        int awayPoints;
    };

    class Game{
        private:
            Team *homeT;
            Team *awayT;
            Score score;

            bool finished;
            int randomScore(int min, int max);
            
        public:
            Game(Team *home, Team *away) : homeT(home), awayT(away){
                finished = false;
                
                score.awayPoints = 0;
                score.homePoints = 0;
            }

            void startGame();
            Team *getWinner();

            Team *getHomeTeam();
            Team *getAwayTeam();

            int getHomeScore();
            int getAwayScore();

            void setHomeScore(int num);
            void setAwayScore(int num);
            
    };
}