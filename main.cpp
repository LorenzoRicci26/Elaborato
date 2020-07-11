#include "stlastar.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <random>
#include "SFML/Graphics.hpp"
#define DEBUG_LISTS 0
#define DEBUG_LIST_LENGTHS_ONLY 0

using namespace std;

const int MAP_WIDTH=20;

const int MAP_HEIGHT=20;

int world_map[ MAP_WIDTH * MAP_HEIGHT ]=
        {
                // 0001020304050607080910111213141516171819
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 00
                1,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,1,   // 01
                1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 02
                1,9,9,1,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 03
                1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 04
                1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 05
                1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 06
                1,9,9,9,9,9,9,9,9,1,1,1,9,9,9,9,9,9,9,1,   // 07
                1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 08
                1,9,1,9,9,9,9,9,9,9,1,1,9,9,9,9,9,9,9,1,   // 09
                1,9,1,1,1,1,9,1,1,9,1,1,1,1,1,1,1,1,1,1,   // 10
                1,9,9,9,9,9,1,9,1,9,1,9,9,9,9,9,1,1,1,1,   // 11
                1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 12
                1,9,1,9,1,9,9,9,1,9,1,9,1,9,1,9,9,9,1,1,   // 13
                1,9,1,1,1,1,9,9,1,9,1,9,1,1,1,1,9,9,1,1,   // 14
                1,9,1,1,9,1,1,1,1,9,1,1,1,1,9,1,1,1,1,1,   // 15
                1,9,9,9,9,1,1,1,1,1,1,9,9,9,9,1,1,1,1,1,   // 16
                1,1,9,9,9,9,9,9,9,1,1,1,9,9,9,1,9,9,9,9,   // 17
                1,9,1,1,1,1,1,1,1,1,1,9,1,1,1,1,1,1,1,1,   // 18
                1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,   // 19
        };

int GetMap(int x,int y){
    if(x<0 || x>=MAP_WIDTH || y<0 ||y>MAP_HEIGHT){
        return 9;
    }
    return world_map[y*MAP_WIDTH+x];
}

class MapSearchNode{
public:
    MapSearchNode(){
        x=y=0;
    }
    MapSearchNode(int px,int py){
        x=px;
        y=py;
    }
    int x;
    int y;

    float GoalDistanceEstimate(MapSearchNode &nodeGoal);
    bool IsGoal(MapSearchNode &nodeGoal);
    bool GetSuccessors(AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node);
    float GetCost(MapSearchNode &successor);
    bool IsSameState(MapSearchNode &rhs);

    void PrintNodeInfo();
};

float MapSearchNode::GoalDistanceEstimate(MapSearchNode &nodeGoal) {
    return abs( x - nodeGoal.x) + abs( y - nodeGoal.y);
}

bool MapSearchNode::IsGoal(MapSearchNode &nodeGoal) {
    if( x==nodeGoal.x && y==nodeGoal.y)
        return true;
    else
        return false;
}

bool MapSearchNode::GetSuccessors(AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node) {

    int parent_x = -1;
    int parent_y = -1;

    if(parent_node){
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }

    MapSearchNode NewNode;

    if( (GetMap(x-1,y) < 9) && !((parent_x == x-1) && (parent_y == y))){
        NewNode = MapSearchNode( x-1, y);
        astarsearch->AddSuccessor(NewNode);
    }

    if ( (GetMap(x,y-1) < 9) && !((parent_x == x) && (parent_y == y-1))){

        NewNode = MapSearchNode( x, y-1);
        astarsearch->AddSuccessor(NewNode);

    }

    if( (GetMap(x+1,y) < 9) && !((parent_x == x+1) && (parent_y == y))){

        NewNode = MapSearchNode(x+1,y);
        astarsearch->AddSuccessor(NewNode);

    }

    if( (GetMap(x,y+1) < 9) && !((parent_x == x) && (parent_y == y+1))){

        NewNode = MapSearchNode(x,y+1);
        astarsearch->AddSuccessor(NewNode);
    }

    return true;
}

float MapSearchNode::GetCost(MapSearchNode &successor) {
    return static_cast<float>(GetMap(x,y));
}

bool MapSearchNode::IsSameState(MapSearchNode &rhs) {
    if( x == rhs.x && y == rhs.y)
        return true;
    else
        return false;
}

void MapSearchNode::PrintNodeInfo() {

    char str[100];

    sprintf(str, "Node position : (%d,%d)\n", x, y);

    cout<< str;

}

int main (int argc, char* argv[]){

    AStarSearch<MapSearchNode> astarsearch;

    unsigned int SearchCount=0;

    const unsigned int NumSearches = 1;

    while(SearchCount < NumSearches){

        MapSearchNode nodeStart;
        nodeStart.x=10;
        nodeStart.y=13;

        if(GetMap(nodeStart.x,nodeStart.y)==9){
            cout<<"Bad start node..."<<std::endl;
        }

        MapSearchNode nodeEnd;
        nodeEnd.x=4;
        nodeEnd.y=3;

        if(GetMap(nodeEnd.x,nodeEnd.y)==9){
            cout<<"Impossible point of the map to reach..."<<std::endl;
        }

        astarsearch.SetStartAndGoalStates(nodeStart,nodeEnd);

        unsigned int SearchState;
        unsigned int SearchSteps = 0;

        do
        {
            SearchState = astarsearch.SearchStep();

            SearchSteps++;

#if DEBUG_LISTS

            cout << "Steps:" << SearchSteps << "\n";

			int len = 0;

			cout << "Open:\n";
			MapSearchNode *p = astarsearch.GetOpenListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY
				((MapSearchNode *)p)->PrintNodeInfo();
	#endif
				p = astarsearch.GetOpenListNext();

			}

			cout << "Open list has " << len << " nodes\n";

			len = 0;

			cout << "Closed:\n";
			p = astarsearch.GetClosedListStart();
			while( p )
			{
				len++;
	#if !DEBUG_LIST_LENGTHS_ONLY
				p->PrintNodeInfo();
	#endif
				p = astarsearch.GetClosedListNext();
			}

			cout << "Closed list has " << len << " nodes\n";
#endif

        }
        while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );

        if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
        {
            cout << "Search found goal state\n";

            MapSearchNode *node = astarsearch.GetSolutionStart();

#if DISPLAY_SOLUTION
            cout << "Displaying solution\n";
#endif
            int steps = 0;

            node->PrintNodeInfo();
            for( ;; )
            {
                node = astarsearch.GetSolutionNext();

                if( !node )
                {
                    break;
                }

                node->PrintNodeInfo();
                steps ++;

            };

            cout << "Solution steps " << steps << endl;

            // Once you're done with the solution you can free the nodes up
            astarsearch.FreeSolutionNodes();


        }
        else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED )
        {
            cout << "Search terminated. Did not find goal state\n";

        }

        // Display the number of loops the search went through
        cout << "SearchSteps : " << SearchSteps << "\n";

        SearchCount ++;

        astarsearch.EnsureMemoryFreed();
    }

    return 0;
}
