#include"graph.h"


int main()
{
    //number of tests
    int tests;
    cin>>tests;
    for(int d=0;d<tests;d++)
    {
        //amount of money
        //number of places
        //name of the city
        int money,places;
        string city;
        cin>>money;
        cin>>city>>places;
        Graph map(city,places,money);
        for(int p=0;p<places;p++)
        {
            //name of place
            //number of edges for that place
            string name;
            int edges;
            cin>>name>>edges;
            map.addnode(name);
            for(int t=0;t<edges;t++)
            {
                //name of places connected to that place
                //cost to travel to that place from the first
                string place;
                int weight;
                cin>>place>>weight;
                map.addedge(weight,map.find(name),place);
            }
        }
    map.findcosts();    
    map.results();    
    }
    return 0;
}

/*
3
7
NewNewYork 4
airport 1 museum 3
museum 2 zoo 4 park 5
zoo 1 park 3
park 0
6
Miami 3
airport 2 swamp 7 beach 10
swamp 0
beach 1 swamp 5
15
Rolla 5
airport 2 lake 5 forest 8
lake 1 forest 7
forest 2 river 6 bar 9
river 1 bar 7
bar 0
*/