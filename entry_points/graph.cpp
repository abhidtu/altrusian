// Created by linux on 13/1/16.

#include <iostream>
#include "../graphs/Graph.hpp"
//#include "../graphs/adjacency_matrix/undirected/UnDirected.hpp"
#include "../graphs/adjacency_list/undirected/UnDirected.hpp"

#include <unordered_map>

using namespace std;
using namespace LibAlDs;

class SuperStar {
public:
    string name;
    int weight;
    int height;
    int chest;
    int biceps;
};

class Traversal : public LibAlDs::graph::DfsVisitor {

public:
    void onVertexDiscovery(int vertex) {
        cout << vertex;
    }

};

class BfsTraversal : public LibAlDs::graph::BfsVisitor {

public:
    void onVertexDiscovery(int vertex) {
        cout << vertex;
    }

};

unordered_map<int,unordered_map<int,int>> d;

int sos(int sum, int size, vector<int> set, vector<vector<int>>& vec, vector<int> tmp) {

    if(sum < 0)
        return 0;

    if(sum == 0){
        vec.push_back(tmp);
        return 1;
    }

    if(size == 0)
        return 0;

        //if(d[sum-set[size-1]][size-1]==0)
        {
            tmp.push_back(set[size-1]);
            d[sum-set[size-1]][size-1] = sos(sum - set[size-1], size - 1, set,vec,tmp);
            tmp.pop_back();
        }
        //if(d[sum][size-1]==0)
        {
            d[sum][size-1] = sos(sum,size - 1, set,vec,tmp);
        }
        return d[sum-set[size-1]][size-1]+d[sum][size-1];

}


int sosInf(int sum, vector<int> set, vector<vector<int>>& vec, vector<int> tmp) {

    if(sum < 0)
        return 0;

    if(sum == 0){
        vec.push_back(tmp);
        return 1;
    }

    int a=0;
    for(auto& v : set) {
        tmp.push_back(v);
        a+=sosInf(sum - v,  set, vec, tmp);
        tmp.pop_back();
    }
    return a;
}

int lcs(vector<char> a, vector<char> b,int asize, int bsize,vector<string>& veclcs, string veclcstmp) {

    if(asize == 0 || bsize == 0){
        veclcs.push_back(veclcstmp);
        return 0;
    }
    if(a[asize-1] == b[bsize-1]) {
        veclcstmp.push_back(a[asize-1]);
        return lcs(a,b,asize-1,bsize-1,veclcs,veclcstmp)+1;
    }
    else {
        return std::max(lcs(a,b,asize-1,bsize,veclcs,veclcstmp),lcs(a,b,asize,bsize-1,veclcs,veclcstmp));
    }

}

int isIntegerPalindrome(int a) {

    int t1 = a;
    int t2=0;

    int i=0;
    while(t1) {
        t2 = t2*(10^i)+t1%10;
        t1=t1/10;
        i++;
    }
    //cout << "t1= " << t1 <<"\n";
    //cout << "t2= " <<t2 <<"\n\n";
    return t1==t2;
}

int main() {

    LibAlDs::graph::adjacency_list::UnDirected<SuperStar> directed(10);
    LibAlDs::Graph<SuperStar> *graphs = &directed;

    SuperStar star;
    star.biceps = 50;
    star.chest = 200;
    star.height = 6;
    star.name = "jhon cena";
    star.weight = 286;

    graphs->addEdge(0,2);
    graphs->setContext(0,star);

    //graphs->addEdge(0,6);
    //graphs->addEdge(0,9);

    //graphs->addEdge(1,2);
    graphs->addEdge(1,5);

    //graphs->addEdge(2,8);
    //graphs->addEdge(2,3);
    graphs->addEdge(2,6);
    graphs->addEdge(2,7);

    graphs->addEdge(3,8);
    graphs->addEdge(3,4);

    graphs->addEdge(4,7);

    graphs->addEdge(5,7);

    graphs->addEdge(6,9);



    //graphs->updateEdgeCost(0,1,8);
    //graphs->updateEdgeCost(0,2,8);

   // graphs->removeEdge(0,2);

    //cout << graphs->edgeExists(0,2);

    //graphs->addVertex();

    //cout << graphs->isEmpty();
    //cout << graphs->size();
    //cout << "\n";

    BfsTraversal bfsTraversal;

    cout << "bfs " ;
    graphs->breadthFirstSearch(bfsTraversal,0);

    cout << "\n";

    Traversal traversal;

    cout << "dfs ";
    graphs->depthFirstSearch(traversal,0);

    cout << "\n";
    cout << "pathExists " << graphs->pathExists(0,6);

    cout << "\n";

    cout << "iscyclic " << graphs->isCyclic();

    vector<vector<int>> vec;

    vector<int> tmp;
    vector<int> arr;
    arr.push_back(16);
    arr.push_back(2);
    arr.push_back(1);
    arr.push_back(5);
    arr.push_back(3);
    arr.push_back(8);
    arr.push_back(9);
    arr.push_back(11);
    arr.push_back(14);

    //cout <<"\n" << sos(10,arr.size(),arr, vec,tmp);
    //cout <<"\n" << sosInf(10,arr, vec,tmp);

    vector<char> a;
    vector<char> b;

    a.push_back('a');
    a.push_back('b');
    a.push_back('a');
    a.push_back('b');
    a.push_back('a');
    a.push_back('b');
    a.push_back('a');
    a.push_back('b');
    a.push_back('b');
    a.push_back('a');
    a.push_back('b');

    b.push_back('b');
    b.push_back('a');
    b.push_back('b');
    b.push_back('b');
    b.push_back('a');
    b.push_back('a');
    b.push_back('b');
    b.push_back('a');
    b.push_back('b');
    b.push_back('b');
    b.push_back('a');

    vector<string> veclcs;
    string veclcstmp;

    //cout << "\nlcs = " << lcs(a,b,a.size(),b.size(),veclcs,veclcstmp);

    for(auto& k : veclcs) {
        cout << "\n" << k;
    }

    //cout <<"\n\n" << isIntegerPalindrome(121);

    return 0;
}

