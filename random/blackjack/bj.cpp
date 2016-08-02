#include<iostream>
#include<math.h>
#include<cstdlib>
#include<ctime>
using namespace std;

const int suitnum=4;
const int nums=13;

//class def
class Deck
{
    public:
    int* cards;
    int cardnum;
    Deck(int decknum);
    Deck(const Deck& d);
    ~Deck();
    Deck& operator=(const Deck& d);
};

//extra funcs  



ostream& operator<< (ostream& out, const Deck a)
{
    out << "[ ";
    for (int i=0; i <a.cardnum; i++){
        out << a.cards[i] << ", ";
    } 
    out << "]"<<endl;
    return out;
}

void randomize(Deck a)
{
    for(int i=0;i<a.cardnum;i++)
    {
        int r=rand()%a.cardnum;
        int temp = a.cards[i];
        a.cards[i] = a.cards[r];
        a.cards[r]= temp;
    } 
} 
 
//member funcs

Deck& Deck::operator=(const Deck& d)
{
    cardnum=d.cardnum;
    cards= new int [cardnum];
    for(int n=0;n<cardnum;n++)
        cards[n]=d.cards[n];
    return *this;
}

Deck::Deck(int decknum)
{
   cardnum=suitnum*nums*decknum;
   cards= new int [cardnum];
   int n=0;
   for(int d=0;d<decknum;d++)
   {
        for(int s=0;s<suitnum;s++)
        {
            for(int c=0;c<nums;c++)
            {
                if(c<10)
                {
                    cards[n]=c+1;
                    n++;
                }
                else 
                {
                    cards[n]=10;
                    n++;
                }
            }
        }
   }  
   
}

Deck::Deck(const Deck& d)
{
    cardnum=d.cardnum;
    for(int i=0;i<cardnum;i++)
        cards[i]=d.cards[i];
}

Deck::~Deck()
{
    delete [] cards;
    cards=NULL;
}



int main()
{
   
   
   
   srand(time(NULL));
   /*
   cout<<"How many decks do you want to include? ";
   int decknum;
   cin>>decknum;
   cout<<"What would you like the deck penetration \nto be as a fraction of the entire deck? (0 to 1) ";
   float pene;
   cin>>pene;
   */
   Deck deck(1);
   
   
   //cout<<deck;
   randomize(deck);
   cout<<deck;
}