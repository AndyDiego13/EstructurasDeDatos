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


};

#endif // !NodeBST_hpp
