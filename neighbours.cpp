/*
Neighbours and New Year Party (100 Marks)
In the XYZ society, the neighbours hate each other for their attitude.
Various activities are organized in the society for Welcoming the New Year.
'' The tickets were provided to each house with an integer written on it.
 Some got tickets with positive integers and some got tickets with negative integers.
 In the evening, people had to carry their tickets to the club house where the eligible ones will get the exciting gifts.
 The eligibility of winning the gift depends on the maximum sum which can be formed from the tickets numbers keeping in mind that neighbours hate each other.
  Since the neighbours hate each other, the two cannot be together in the list of maximum sum.


  The President of the society, Mr. Singh, is a wise man and know that neighbours in society don't like each other.
   Also, he don't wish to become bad in front of people.
   So, he came up with an idea to design a program which will provide the list of integers forming maximum sum and thus all the members of the list will be
    given the gifts. The only problem with this idea is that he don't know programming so he is asking you to provide the correct list
     of integers. The people may be annoying but are smart and will fight if the list provided by you doesn't form the maximum sum.


Note: The integer written on ticket of individuals may or may not be unique. In case, when there are two list with equal maximum sum,
 the list with first greater element would be considered. For better understanding, look at the explanation of Test case 4 in Sample Test Case.
  The tickets with integer 0 are not considered for winning the gifts.



Input Format
The first line of input consist of number of test cases, T.

The first line of each test case consist of the number of houses (tickets distributed) in society, N.

The second line of each test case consist of N space separated tickets with integer written on them.


Constraints
1<= T <=10

1<= N <=10000

-1000<= Integer_on_Ticket <=1000



Output Format
For each test case, print the ticket numbers in a single line forming the maximum sum in the format similar to Sample Test Case.

Sample TestCase 1
Input
5
5
-1 7 8 -5 4
4
3 2 1 -1
4
11 12 -2 -1
4
4 5 4 3
4
5 10 4 -1
Output
48
13
12
44
10
*/

#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>
#include <vector>
#include <utility>
#include <string>
#define MAXTICKET 1000
#define MAXTESTCASE 10


using namespace std;
namespace {

bool _debugOn = 1;
char * mode = "new";
}

class TestCase {
    public :
        TestCase(int count, int nl ) : totalHouseCount(count)
         {
             while(nl)
                {
                    newline = newline + "\n";
                    nl--;
                }
         }

        virtual void addTicket(const int ticket) {
                tickets.push_back(ticket);
        }
        std::string getnewline() const  { return newline;}
        const int getHouseCount() const { return totalHouseCount;}
        virtual const std::vector<int>& getTickets () const { return tickets;}
protected :
    int totalHouseCount;
    std::string newline;
    std::vector<int> tickets;

};
class TestCaseNew :public TestCase{
    public :
        TestCaseNew(int count, int nl):TestCase(count,  nl ), currentIndex(0)
         {

         }

        void addTicket(const int ticket) {
            tickets[currentIndex] = ticket;
            currentIndex++;
        }
        std::string getnewline() const  { return newline;}
        const int getHouseCount() const { return totalHouseCount;}
        const std::array<int, MAXTICKET>& getTickets () const { return tickets;}
protected :
    int currentIndex;
    std::array<int, MAXTICKET> tickets;

};

class  TestCaseList {

public  :
    TestCaseList(int cnt) : totalTestCount(cnt) {}
    void playDraw();
    void addTestCase(TestCase *tc) {
        testCaseList.push_back(tc);
    }
    int getTotalTest() { return totalTestCount;}
    const std::vector<TestCase *> getTestCaseList() const  { return testCaseList;}
private :
    std::vector<TestCase *> testCaseList;
    int totalTestCount;

};
class GoldenPair {

public :
    GoldenPair() : sum(0) { }
    GoldenPair(const int par ) : data({par}), sum(par) {}
    const std::vector<int>& getPair () const { return data;}
    int getSum() { return sum;}
    virtual void addnewline(std::string newline) {nl = newline;}
    virtual std::string getnewline() { return nl;}
    virtual GoldenPair&  putPair(const int par)
    {
        if ( par != 0)
            data.push_back(par);
        sum = sum + par;
        return *this;
    }

    virtual void putSum(const int _sum) { sum = _sum; }
    virtual void showPair()
    {

        if(_debugOn)
        {
            std::cout << "Inside showPair" << std::endl;
            for (const auto& it : data)
            std::cout << it << " ";

            std::cout << std::endl;
        }

                //std::cout << "size s " << s1 <<  std::endl;
        //std::cout << std::endl;

    }
    virtual void displayResult(void)
    {
       //for ( int i = data.size() - 1  ; i >= 0 ; i--)
       std::cout << nl;
       if (1)
       {
        for(int i = 0; i < data.size() ; i++)
            std::cout << data[i];
        if ( data.size() == 0 )
            std::cout << 0 ;
        std::cout << std::endl;
       }

    }
    GoldenPair& operator=(const GoldenPair& copy )
    {
        this->data = copy.data;
        this->sum = copy.sum;
        return *this;

    }


protected :
    std::vector<int> data;
    std::string nl;
    int sum;
};

class GoldenPairNew : public GoldenPair
{
public :
    //GoldenPairNew(int count ) : GoldenPair(count) {}
    GoldenPairNew(const int par )
    {
        currentIndex = 0;
        data[currentIndex] = par;
        currentIndex++;
    }
    GoldenPairNew&  putPair(const int par)
    {
        if ( par != 0)
            data[currentIndex] = par;
        sum = sum + par;
        currentIndex++;
        return *this;
    }

    GoldenPairNew& operator=(const GoldenPairNew& copy )
    {
        this->data = copy.data;
        this->sum = copy.sum;
        return *this;

    }


private :
    int currentIndex;
    std::array<int, MAXTICKET> data;


};


namespace {

    GoldenPair * createObject(int data, char *mode)
    {
        if (mode == "new")
            return(new GoldenPairNew(data));
        else
            return(new GoldenPair(data));
    }
    TestCase * createTestCase(int count, int nl, char *mode )
    {
        if(mode == "new")
            return(new TestCaseNew(count, nl));
        else
            return(new TestCase(count, nl));
    }

    int getInput()
    {
        std::string op;
        std::getline(std::cin , op) ;
        //std::cout << op.size() << std::endl;
        int value;
        std::stringstream os(op);
        if ( op.size() == 0 )
            return -1;
        os >> value;
            return value;

    }

    void debugMsg(std::ostringstream& s)
    {
        if(_debugOn)
            std::cout << s.str() << std::endl;
    }
GoldenPair* getMax(const std::vector<int>& data, int start, int end)
{
    std::ostringstream buffer;
    GoldenPair* g1;
    //auto g3;
    //debugMsg(sprintf(s, "start end %d %d ", start, end));
    buffer << "GetMax() start  end " << start << " " << end << " " << std::endl;
    debugMsg(buffer);
    if (start == end)
    {
        //GoldenPair  g1 = new GoldenPairNew(data[start]);
        g1 = createObject(data[start], mode);
        return g1;

    }
    if ( start + 1 == end)
    {
        //GoldenPair g1= (data[start] > data[end]  ? data[start] : data[end]);
        g1 = createObject((data[start] > data[end]  ? data[start] : data[end]), mode);
        return g1;
    }
    if ( start > end + 1)
    {
        //GoldenPair g1(data[end - 1 ]);
        g1 = createObject(data[end -1 ], mode);
        return g1;
    }
    if (start > end )
    {
        g1 = createObject(0, "new");
        return g1;

    }
    {

    GoldenPair*  g1 = getMax(data, start + 2, end);
    GoldenPair*  g2 = getMax(data, start + 3, end);
    bool useG1 = false;
    bool useG2 = false;
    std::cout << "      calling show pair   " << std::endl;
    g1->showPair();
    g2->showPair();



    if ( g1->getSum() + data[start] > g1->getSum())
    {
        if (g1->getSum() + data[start] < data[start])
        {
            delete(g1);
            g1 = createObject(data[start], mode);
        }

        else
            g1->putPair(data[start]);

    }


    if ( g2->getSum() + data[start+1] > g2->getSum())
    {


         if (g2->getSum() + data[start+1] < data[start+1])
         {
            delete(g2);
            g2 = createObject(data[start+1], mode);
         }
        else
            g2->putPair(data[start+1]);
    }

    if (g1->getSum() > g2->getSum())
    {
        std::cout << " Inside ";
        g1->displayResult();
        return g1;
    }

    if (g1->getSum() == g2->getSum())
    {

            auto s1 = g1->getPair().size();
            auto s2 = g2->getPair().size();
            for ( int i = 0 ; i < s1 && i < s2 ; i++)
            {
                if (g1->getPair()[i] > g2->getPair()[i])
                    return g1;
                else if (g2->getPair()[i] > g2->getPair()[i])
                    return g2;

            }


    }
     return g2;
    }

}
}

void TestCaseList::playDraw(void )
{
    int itr = 0;
    for(const auto& it : testCaseList)
    {
        itr++;
        std::ostringstream buff;
        buff << "TestCase  " << itr << std::endl;
        debugMsg(buff);
        auto i1 = *it->getTickets().begin();

      //  std::cout << "House Count ==>" << it.getHouseCount() << std::endl ;
        GoldenPair * gold;

        gold = getMax(it->getTickets(), 0, it->getTickets().size() - 1);
        gold->addnewline(it->getnewline());
        gold->displayResult();
    }


}

int main()
{

    int numTestCase;
    std::cin >> numTestCase;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    TestCaseList tclist(numTestCase);
    int newline = 0;
    for(int test = 0 ; test < numTestCase; )
    {
        int input = getInput();
        int count = input;



        //std::cin >> count ;
        //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

         if(input < 0 )
        {
           // std::cout << "inputs is less than 0" << std::endl;
             newline++;
            continue;

        }
        if (input >= 0)
        {
            //TestCase tc(count, newline);
            TestCase *tc = createTestCase(count, newline, mode);
            newline = 0;

            test++;

            for(int houseCount = 0 ; houseCount < count ; houseCount++)
            {
                int tk;
                std::cin >> tk;
                tc->addTicket(tk);
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            tclist.addTestCase(tc);
        }

    }

 if(_debugOn)
 {

	//Write code here

	std::cout << std::endl;
	std::cout << "Debugging " << std::endl;
	std::cout << tclist.getTotalTest() << std::endl;

    for(auto const& tc : tclist.getTestCaseList())
    {
        std::cout << tc->getHouseCount() << std::endl;;

        for(const auto& vil : tc->getTickets())
        {
            std::cout << vil << " ";

        }
        std::cout << "new line is " << tc->getnewline() << "finished";
        std::cout << std::endl;

    }
 }

    tclist.playDraw();


}


