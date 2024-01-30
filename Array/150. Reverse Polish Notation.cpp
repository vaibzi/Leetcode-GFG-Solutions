//Medium
//Topics-> Array, String

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int ans = 0;
        vector<int> temp;

        for(int i=0; i<tokens.size(); i++){
            
            if(tokens[i]=="*" || tokens[i]=="+" ||tokens[i]=="-" ||
            tokens[i]=="/"){
                
                int num1 = temp[temp.size()-1];
                temp.pop_back();
                int num2 = temp[temp.size()-1];
                temp.pop_back();

                if(tokens[i]=="*"){
                    temp.push_back(num1*num2);
                }
                if(tokens[i]=="+"){
                    temp.push_back(num1+num2);
                }
                if(tokens[i]=="-"){
                    temp.push_back(num2-num1);
                }
                if(tokens[i]=="/"){
                    temp.push_back(num2/num1);
                }
            }
            else{
                temp.push_back(stoi(tokens[i]));
            }
        }
        return temp[0];
    }
};
