#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

class Node{
public:
    int nbr;
    int nbrEdges;
    int level;
    string id;
    vector<Node*> edges;
    bool root;


    Node() = default;
    Node(int _level){
        level = _level;
    }
    Node(string _id, int val, int edg):nbr{val},nbrEdges{edg},id{_id}{
        if(edg>0){
            assignEdges("");
        }
    }

    void assignEdges(Node* N){
        edges.push_back(N);
    }



    void assignNodes(string parentPath,int _level){
        level = _level;
        cout << "Id : ";
        cin >> id;

        cout << "Value : ";
        cin >> nbr;

        cout << "Edges : ";
        cin >> nbrEdges;

        if(nbrEdges > 0){
            assignEdges((parentPath+"/"+id ));
        }
    }

    Node searchForNode(string _id){
        searchNode();
        for(size_t i=0;i<edges.size();++i){
            if(strcmp(_id,edges[i]->id));
                return edges[i];
        }
        return null;
    }

    void assignEdges(string parentPath){

        for(int i{};i<nbrEdges;++i){
            edges.push_back(new Node());
            cout << "Path : " << parentPath << endl;
            cout << "Edge ["<<i+1<<"] : " << endl;
            edges[i]->assignNodes(parentPath, level+1);
        }
    }

    void showNode(){
        cout << id << endl;
        if(nbrEdges>0)
            showChildren();
    }

    void showChildren(){
        for(int i{};i<nbrEdges;++i){
            for(int j{};j<level;j++){
                cout<<"|     ";
            }
            cout << "|___ ";
            edges[i]->showNode();
        }
    }



    vector<Node> searchNode(){
        vector<Node> x,y;
        x.push_back(this);
        for(int i{};i<nbrEdges;++i){
            y = edges[i]->searchNode();
            x.insert(x.end(), y.begin(), y.end());
        }
        return x;
    }
};

class Tree{
    public :
    int taille;
    Node *root;
    vector<Node> x;

    Tree(){
        taille = 0;
        root = NULL;
    }
    void createTree(){
        cout << "ROOT : " << endl;
        root = new Node();
        root->assignNodes("",0);
    }
    void showTree(){
        root->showNode();
    }
    void depthFirstSearch(){
        x = root->searchNode();
    }
    void showDFS(){
        for(size_t i{};i<x.size();i++){
            cout<< x[i] <<endl;
        }
    }
};

int main()
{
    //Node *root = new Node();
    //root->assignEdge();
    //root->assignEdge();
    //root->showNode
    // Tree a;
     //a.createTree();
    // cout << endl;
     //a.showTree();
     //cout << endl;
    // cout << endl;
    // a.depthFirstSearch();
    // cout << endl;
     //cout << endl;
     //a.showDFS();
    return 0;
}
