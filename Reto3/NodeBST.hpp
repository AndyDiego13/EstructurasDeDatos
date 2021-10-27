/* 

    "NodeBST.hpp"
*/

#ifndef NodeBST_hpp
#define NodeBST_hpp

#include <iostream>
#include <string>
#include <vector>
#include <queue>

class NodeBST
{
    public:
        std::pair<std::string, int> value;
        NodeBST *left;
        NodeBST *right;
        int deep;

        /* Destructores */
        virtual ~NodeBST();

        /* Constructores */
        NodeBST() {};

        NodeBST(std::string name, int num);
        NodeBST(std::pair<std::string, int> val);
        NodeBST(std::string name, int num, NodeBST *_left, NodeBST *_right);
        NodeBST(std::pair<std::string, int> val, NodeBST *_left, NodeBST *_right);

        std::pair<std::string, int> getVal();
        std::string getValName();
        int getValNum();

        NodeBST *getLeft();
        NodeBST *getRight();

        void setVal(std::pair<std::string, int> val);
        void setValName(std::string name);
        void setValNum(int num);

        



};

#endif // !NodeBST_hpp
