#include <iostream>
#include "Team.hpp"
#include "Game.hpp"
#include <vector>
#include <set>

namespace ariel{
    class Schedule{
        private:
            std::vector<Team *> teams;
        public:
            Schedule(std::vector<Team *> t) : teams(t){}

            std::vector<Game*> getGames(){
                std::vector<Game*> games;
                for (Team * team1 : teams){
                    for(Team * team2 : teams){
                        if(team1 == team2){
                            continue;
                        }
                        games.push_back(new Game(team1, team2));
                        games.push_back(new Game(team2, team1));
                    }
                }
                return games;
            };
    };
}