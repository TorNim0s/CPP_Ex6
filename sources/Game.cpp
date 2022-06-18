#include "Game.hpp"

using namespace std;

namespace ariel{

    Team *Game::getHomeTeam(){
        return this->homeT;
    }

    Team *Game::getAwayTeam(){
        return this->awayT;
    }


    int Game::getHomeScore(){
        if(!this->finished){
            throw runtime_error("Game is not finished!");
        }

        return this->score.homePoints;
    }

    int Game::getAwayScore(){
        if(!this->finished){
            throw runtime_error("Game is not finished!");
        }

        return this->score.awayPoints;
    }

    void Game::setHomeScore(int num){
        this->score.homePoints = num;
    }

    void Game::setAwayScore(int num){
        this->score.awayPoints = num;
    }

    int Game::randomScore(int min, int max){
        return rand() % (max - min) + min;
    }

    void Game::startGame(){

        if(this->finished){
            throw runtime_error("Game is finished");
        }

        double homePoints = randomScore(55, 100);
        double awayPoints = randomScore(50, 100);

       
        if(this->getHomeTeam()->GetRank() > this->getAwayTeam()->GetRank()){
            homePoints = homePoints + 10 > 100 ? 100 : homePoints+10;
        }
        else{
            awayPoints = awayPoints + 10 > 100 ? 100 : awayPoints+10;
        }

        this->setHomeScore(homePoints);
        this->setAwayScore(awayPoints);

        this->getAwayTeam()->totalGoodPoints += awayPoints;
        this->getAwayTeam()->totalBadPoints += homePoints;

        this->getHomeTeam()->totalGoodPoints += homePoints;
        this->getHomeTeam()->totalBadPoints += awayPoints;

        this->finished = true;

        if (this->getHomeTeam() == this->getWinner()){
            this->getHomeTeam()->totalWin++;
            this->getAwayTeam()->totalLose++;

            if(this->getHomeTeam()->isWinStreak){
                this->getHomeTeam()->currentWinStreak++;
                if(this->getHomeTeam()->currentWinStreak > this->getHomeTeam()->winStreak){
                    this->getHomeTeam()->winStreak = this->getHomeTeam()->currentWinStreak;
                }
                this->getHomeTeam()->isLoseStreak = true;
                this->getHomeTeam()->currentLoseStreak = 0;
            }

            this->getAwayTeam()->isWinStreak = false;
            this->getAwayTeam()->currentWinStreak = 0;
            
        }
        else{
            this->getAwayTeam()->totalWin++;
            this->getHomeTeam()->totalLose++;

            if(this->getAwayTeam()->isWinStreak){
                this->getAwayTeam()->currentWinStreak++;
                if(this->getAwayTeam()->currentWinStreak > this->getAwayTeam()->winStreak){
                    this->getAwayTeam()->winStreak = this->getAwayTeam()->currentWinStreak;
                }
                this->getAwayTeam()->isLoseStreak = true;
                this->getAwayTeam()->currentLoseStreak = 0;
            }

            this->getHomeTeam()->isWinStreak = false;
            this->getHomeTeam()->currentWinStreak = 0;
            if(this->getHomeTeam()->isLoseStreak){
                this->getHomeTeam()->currentLoseStreak++;
                if(this->getHomeTeam()->currentLoseStreak > this->getHomeTeam()->loseStreak){
                    this->getHomeTeam()->loseStreak = this->getHomeTeam()->currentLoseStreak;
                }
            }

        }
    }

    Team *Game::getWinner(){

        if(!this->finished){
            throw runtime_error("Game is not finished!");
        }

        int home = this->getHomeScore();
        int away = this->getAwayScore();
        if(home > away){
            return this->getHomeTeam();
        }
        else if(home < away){
            return getAwayTeam();
        }

        if(getHomeTeam()->GetRank() > getAwayTeam()->GetRank()){
            return this->getHomeTeam();
        }
        return this->getAwayTeam();

    }

}