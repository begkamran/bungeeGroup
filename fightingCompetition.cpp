
/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
/*WIN or LOSE (100 Marks)
A new fighting game has become popular. There are N number of villains with each having some strength.
There are N players in the game with each having some energy. The energy is used to kill the villains.
The villain can be killed only if the energy of the player is greater than the strength of the villain.
Maxi is playing the game and at a particular time wants to know if it is possible for him to win the game or not with the given set of energies and strengths of players and villains. Maxi wins the game if his players can kill all the villains with the allotted energy.



Input Format
The first line of input consist of number of test cases, T.

The first line of each test case consist of number of villains and player, N.

The second line of each test case consist of the N space separated strengths of Villains.

The third line of each test case consist of N space separated energy of players.



Constraints
1<= T <=10

1<= N <=1000

1<= strength , energy <=100000



Output Format
For each test case, Print WIN if all villains can be killed else print LOSE in separate lines.

Sample TestCase 1
Input
1
6
112 243 512 343 90 478
500 789 234 400 452 150
Output
WIN
Explanation
For the given test case, If we shuffle the players and villains, we can observe that all the villains can be killed by players.
As all the villains can be killed by the players, MAXI will WIN the game. Thus, the final output is WIN.
Sample TestCase 2
Input
2
6
10 20 50 100 500 400
30 20 60 70 90 490
5
10 20 30 40 50
40 50 60 70 80
Output
LOSE
WIN
Time Limit(X):
1.00 sec(s) for each input.
Memory Limit:
512 MB
Source Limit:
100 KB


*/
#include <iostream>
#include <vector>
#include <iomanip>
#include <map>
#include <bits/stdc++.h>
using namespace std;
class Villain {
	public:
	    Villain(int str) : strength(str) {}
        const int getStrength() const { return strength;}
        void setStrength(int& value) { strength = value;}

	private :
        int strength;

};
class Player{

	public:
        Player(int en) : energy(en) {}
        const int getEnergy(void) const { return energy;}
        void setEnergy(int& value) { energy = value;}

	private:
        int energy;

};

class TestCase {

    public:
        TestCase(int cnt) : count(cnt), totalCount(0) {}
        const int getMemberCount() const { return count ;}
        void addPlayer(Player& pl) {
            playerList.push_back(pl);
            totalCount++;
        }
        void removePlayer(int energy) {
            totalCount--;
            for(auto it = playerList.begin(); it != playerList.end();  it++)
            {
                if(it->getEnergy() == energy)
                {
                   playerList.erase(it);
                   break;
                }
            }
        }
        void removeVillain(int str)
        {
            totalCount--;
            for(auto it = villainList.begin(); it != villainList.end() ; it++)
            {
                if(it->getStrength() == str)
                {
                   villainList.erase(it);
                   break;
                }
            }
        }
        const Player biggestPlayer()
        {
            Player pl = *playerList.begin();
            for(const auto& it : playerList)
            {
                if( it.getEnergy() > pl.getEnergy())
                    pl = it;
            }
            return pl;
        }

        const Villain biggestVillain()
        {
            Villain pl = *villainList.begin();
            for(const auto& it : villainList)
            {
                if( it.getStrength() > pl.getStrength())
                    pl = it;
            }
            return pl;
        }
        const bool winnable(const Player& pl, const Villain& vil)
        {
            return( pl.getEnergy() > vil.getStrength() ? true : false);

        }

        const std::vector<Player>& getPlayerList() const { return playerList;}
        const std::vector<Villain>& getVillainList() const { return villainList; }
        void addVillain(Villain& vill ) {
            villainList.push_back(vill);
            totalCount++;
            }
        const int getTotalCount() const { return totalCount; }
    private:
        std::vector<Player> playerList;
        std::vector<Villain> villainList;
        int count;
        int totalCount;
};

class AllTestCases {

    public:
        AllTestCases(int cnt) : count(cnt) { }

        const std::string playMatch(void);
        int getNumTestCases() const { return count;}
        const std::vector<TestCase>&  getTestCaseList() const { return testCaseList;}
        void addTestCase(TestCase& tc) { testCaseList.push_back(tc);}
    private :
        std::vector<TestCase> testCaseList;
        int count;
};
const std::string AllTestCases::playMatch(void) {
    std::string result;


    for(const auto& it : testCaseList)
    {
        int total = it.getTotalCount();
        TestCase test = it;
        while(total)
        {
            Villain vl = test.biggestVillain();
            Player pl = test.biggestPlayer();
            const bool canwin = test.winnable(pl, vl);
            if (!canwin){
                result = result + "LOSE\n";
                break;
            } else {
                test.removePlayer(pl.getEnergy());
                total--;
                test.removeVillain(vl.getStrength());
                total--;

            }

        }
        if (total == 0)
        result = result + "WIN\n";
    }
    return(result);
}

int main()
{
    int numTestCase;
    std::cin >> numTestCase;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    AllTestCases tclist(numTestCase);

    for(int test = 0 ; test < numTestCase; test++)
    {
        int count;
        std::cin >> count ;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        TestCase tc(count);

        for(int villCnt = 0 ; villCnt < count ; villCnt++)
        {   int strength;
            std::cin >> strength;
            Villain vill(strength);
            tc.addVillain(vill);
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        for(int playerCnt = 0 ; playerCnt < count ; playerCnt++ )
        {
            int energy;
            std::cin >> energy;
            Player pl(energy);
            tc.addPlayer(pl);

        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        tclist.addTestCase(tc);

    }
    #if 1

	//Write code here

	std::cout << std::endl;
	std::cout << "Debugging " << std::endl;
	std::cout << tclist.getNumTestCases() << std::endl;

    for(auto const& tc : tclist.getTestCaseList())
    {
        std::cout << tc.getMemberCount() << std::endl;;

        for(const auto& vil : tc.getVillainList())
        {
            std::cout << vil.getStrength() << " ";

        }
        std::cout << std::endl;
        for(const auto& pl : tc.getPlayerList())
        {
            std::cout << pl.getEnergy() << " ";

        }
        std::cout << std::endl;

    }
    #endif
    const std::string result = tclist.playMatch();
    std::cout << result;



	return 0;
}
