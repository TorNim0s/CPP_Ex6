#include "League.hpp"

using namespace std;

namespace ariel{
    League::League() : leagueIsOver(false)
    {
        srand( (unsigned)time( NULL ) );
        for(int i = 0; i<20; i++){
            string name = to_string(i);
            double Points = (float) rand()/RAND_MAX;
            teams.push_back(new Team(Points, name));
        }
    }

    League::League(vector<Team *> other) : leagueIsOver(false)
    {
        if(other.size() == 20){
            copy(begin(other), begin(other), back_inserter(teams));
        }
        else{
            if(other.size() > 20){
                throw runtime_error("Amount of teams is to big!");
            }

            srand( (unsigned)time( NULL ) );
            copy(begin(other), begin(other), back_inserter(teams));
            for(int i = other.size(); i<20; i++){
                string name = to_string(i);
                double Points = (float) rand()/RAND_MAX;
                teams.push_back(new Team(Points, name));
            }
        }
    }

    void League::sortLeague(enum Mode mode){
        if(mode == Mode::win){
            sort(teams.begin(), teams.end(), [](Team * a, Team * b){
                return (a->totalWin > b->totalWin) && (a->totalLose < b->totalLose);
            });
        }
        else if(mode == Mode::points){
            sort(teams.begin(), teams.end(), [](Team * a, Team * b){
                return ((a->totalGoodPoints - a->totalBadPoints) > (b->totalGoodPoints - b->totalBadPoints));
            });
        }
    }

    void League::startLeague(){
        if(this->leagueIsOver){
            throw runtime_error("The league is over!");
        }

        Schedule schedule(this->getTeams());
        vector<Game*> games = schedule.getGames();
        for (Game * game : games){
            game->startGame();
        }

        this->sortLeague(Mode::win);

        this->leagueIsOver = true;
    }

    void League::showTable(){
        for(Team * team: teams){
            cout << "Team: " << team->GetName() << " with " << team->totalWin << " Wins and " << team->totalLose << " Lose, Total points: " << team->totalGoodPoints << endl;
        }
    }

    void League::showStatistics(enum Mode mode){

        this->sortLeague(mode);

        int bestWinStreak = 0;
        int bestLoseStreak = 0;

        int counterMoreGoodThanBad;

        for(Team * team: teams){
            cout << "Team: " << team->GetName() << " with " << team->totalWin << " Wins and " << team->totalLose << " Lose, Total points: " << team->totalGoodPoints << endl;
            
            if(team->winStreak > bestWinStreak){
                bestWinStreak = team ->winStreak;
            }

            if(team->loseStreak > bestLoseStreak){
                bestLoseStreak = team->loseStreak;
            }

            if(team->totalGoodPoints > team->totalBadPoints){
                counterMoreGoodThanBad++;
            }

        }

        cout << "Length of the most win streak is: " << bestWinStreak << endl;
        cout << "Length of the most lose streak is: " << bestLoseStreak << endl;
        cout << "Amount of teams with positive score: " << counterMoreGoodThanBad << endl;




    }

}