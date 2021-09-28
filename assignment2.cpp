// Documentation 

/*
 Author:	Sanskar Shrivastava
 Module:	3 
 Topic:		Gully Cricket App
*/


// Include required header files and define namespaces as required

#include <iostream>
#include<unistd.h>
#include<string>
#include<cstdlib>
#include<ctime>

using namespace std;

// Define a class Team

class Team {
    public:
           char team;
           string players[3];
           int totalRuns;
           void displayPlayers();
           //void selectBatsmanAndBowler(Team,Team,int);

           



};
// Function declarations (function prototypes) as used in the program 
void displayPlayers(Team, Team);
void  welcomeUsers();
void selectBatsmanAndBowler(Team, Team);
void startInning(int, string, string);
int playInning();
void decideWinner(int, int);


// Global declaration of variables 
string currentBowler;
string currentBatsman;
int MAX = 2;
 //Team objA, objB;

int main() {
    // Call functions (as required) defined in the subprogram section.  
// Greet the user with a welcome message 
    welcomeUsers();
// Initialize both teams with the required data 
    Team objA, objB;
    int totalScore1 = 0, totalScore2 = 0;
    objA.team = 'A';
    objA.players[0] = "Sachin";
    objA.players[1] = "Virat";
    objA.players[2] = "Hardik";

    

    objB.team = 'B';
    objB.players[0] = "Dhoni";
    objB.players[1] = "Rohit";
    objB.players[2] = "Rahul";

// Display player names of both the teams
    displayPlayers(objA,objB);
    //displayPlayers(objA,objB);
// Play inning one 
    srand(time(NULL));
    selectBatsmanAndBowler(objA, objB);
    startInning(1, "A", "B");
    totalScore1 = playInning();
    

    
// Display score 
    cout<<"Total score of inining One(1) : "<<totalScore1<<endl<<endl;
// Play inning two 
    cout<<"Inning two begins"<<endl<<endl;
    selectBatsmanAndBowler(objB, objA);
    startInning(2, "B", "A");
    totalScore2 = playInning();

// Display score 
    cout<<"Total score of inining Two(2) : "<<totalScore2<<endl<<endl;
// Decide winner 
decideWinner(totalScore1, totalScore2);
 return 0;
}


// Note: The following function definitions are just an illustration of what are the possible  functions that can be created to perform tasks. You may or may not use the following function 
//prototypes. You can have as many functions as you require. 
/* Greet users with a welcome message */ 
void welcomeUsers() {
// Code…. 
    cout << "---------------------------------------" << endl;
    cout << "|======================================|" << endl;
    //cout << "|                                      |" << endl;
    cout << "|Ready to play Gully Cricket, Let's GO!|" << endl;
    cout << "|======================================|" << endl;
    cout << "---------------------------------------" << endl;
//cout<<"Ready to play Gully Cricket, Let's GO!"<<endl;
sleep(2);
 }


/* Display all the players in both team A and team B */
void displayPlayers(Team t1, Team t2) {
// Code… 
    Team show;
// Loop can be used to print player names in an array
    //cout<<"List of Players of Team "<<team<<endl;
    cout << endl;
	cout << "------------------------------------------------" << endl;
	cout << "|========== List of Players of Teams ==========|" << endl;
	cout << "------------------------------------------------" << endl;
    sleep(2);
    cout<<endl;

    cout << "------------------------------------------------------------------" << endl;
    cout << "|===========  Team-A  ==========  || ==========  Team-B  =========|" << endl;
    cout << "------------------------------------------------------------------" << endl;


    
    for (int i = 0; i < 3; i++) {
        cout << "|\t" << "[" << i << "] " << t1.players[i] << "\t          |"
			<< "|\t     " << "[" << i << "] " << t2.players[i] << "\t          |" << endl;
    }
    cout << "------------------------------------------------------------------" << endl << endl;


   /* for (int i = 0; i < 3; i++)
    {
        
        cout<<i+1<<". "<<players[i]<<endl;

    }
    cout<<endl;

    }*/
}


/* Select randomly a batsman and bowler from the batting team and bowler team respectively for 
a inning */
void selectBatsmanAndBowler(Team batTeam, Team bowlTeam) {
// Code...
     
    
         currentBatsman = batTeam.players[rand() % 3];
         //cout<<currentBatsman;
         currentBowler = bowlTeam.players[rand() % 3];
        // cout<<"bowler is"<<currentBowler;

    


}


/* Start inning by displaying initial inning details */
void startInning(int inning, string batTeam, string bowlTeam) { 
// Code…
// Display details such as who is the batting team or who is the batsman/bowler etc. 
    cout<<"Current Batting team: "<<batTeam<<endl<<endl;
    sleep(1);
    cout<<"Current Bowling team: "<<bowlTeam<<endl<<endl;
    sleep(1);
    cout<<"Current Batsman: "<<currentBatsman<<endl<<endl;
    sleep(1);
    cout<<"Current Bowler: "<<currentBowler<<endl<<endl;
    sleep(1);
    cout<<"Inning "<<inning<<" begins now, READY SET GO!!"<<endl<<endl;
    sleep(2);

}


/* Play one inning (6 balls) */
int playInning() {
// Code… 
// Use random function to generate run in each ball 
    int  presentScore, runs = 0;
    for(int i = 0; i < 6; i++)
    {
        int presentScore = ((rand() % 7));
        cout<<"presentScore is:"<<presentScore<<endl<<endl;
        runs = runs + presentScore;
        sleep(1);
        cout<<"Total runs :"<<runs<<endl<<endl;
        sleep(1);
        cout<<"Bowling and Batting......"<<endl<<endl;
        sleep(2);
        
    }


return runs; // Return the final run scored by the batting team 
}


/* Decide winner by comparing final scores of both the teams */
void decideWinner(int teamAScore, int teamBScore) {
// code… 
    cout<<"Waiting for result...";
    sleep(2);

    if (teamAScore > teamBScore)
    {
        cout<<"Team A WON the match by "<<teamAScore - teamBScore<<" runs";
    }
    else if (teamAScore == teamBScore)
    {
        cout<<"IT's A TIE!";
    }
    else{
        cout<<"Team B WON the match by "<<teamBScore - teamAScore<<" runs";
    }
}