#include "League.hpp"
using namespace ariel;
using namespace std;

int main(){
    // srand( (unsigned)time( NULL ) );
    // Team t1{ 0.7, "eldad"};
    // Team t2{ 0.6, "maya"};

    // cout << "Printing teams" << endl;
    // cout << "------------" << endl;

    // cout << t1.GetName() << endl;
    // cout << t2.GetName() << endl;

    // cout << "------------" << endl;
    // cout << "Start Game Eldad(home) vs Maya(away)";
    // cout << "------------" << endl;

    // Game game1(t1, t2);
    // game1.startGame();

    // cout << "The winner is: " << endl;
    // cout << game1.getWinner().GetName() << endl;
    
    // cout << "Home score: " << game1.getHomeScore() << endl;
    // cout << "Away score: " << game1.getAwayScore() << endl;

    // cout << "------------" << endl;

    // cout << "------------" << endl;
    // cout << "Start Game Eldad(away) vs Maya(home)";
    // cout << "------------" << endl;

    // Game game2(t2, t1);
    // game2.startGame();

    // cout << "The winner is: " << endl;
    // cout << game2.getWinner().GetName() << endl;
    
    // cout << "Home score: " << game2.getHomeScore() << endl;
    // cout << "Away score: " << game2.getAwayScore() << endl;

    // cout << "------------" << endl;

    League league;
    league.startLeague();
    league.showStatistics(League::Mode::win);
    league.showStatistics(League::Mode::points);

    return 0;
}