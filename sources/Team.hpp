#pragma once

#include <iostream>
#include <stdexcept>

namespace ariel{
    class Team{
        private:
            double rank;
            std::string name;
        
        public:
            int totalWin;
            int totalLose;
            int totalGoodPoints;
            int totalBadPoints;

            int winStreak;
            int currentWinStreak;
            bool isWinStreak;

            int loseStreak;
            int currentLoseStreak;
            bool isLoseStreak;

            Team(double r, const std::string& n) : name(n), totalWin(0), totalLose(0), totalGoodPoints(0), totalBadPoints(0), winStreak(0), currentWinStreak(0),
             isWinStreak(true), loseStreak(0), currentLoseStreak(0), isLoseStreak(true){
                if(r < 0.0 || r > 1.0){
                    throw std::runtime_error("Rank is not valid");
                }
                this->rank = r;
            }
            Team(std::string n) : name(n), rank(0.5), totalWin(0), totalLose(0), totalGoodPoints(0), totalBadPoints(0), winStreak(0), currentWinStreak(0), 
            isWinStreak(true), loseStreak(0), currentLoseStreak(0), isLoseStreak(true){}

            std::string &GetName();
            double GetRank();

            bool operator==(const Team &other) const
            {
                return (this->name == other.name);
            }
    };
}