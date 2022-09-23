/* Geek has a string Sof size Nconsisting of characters from '0'to '9'. He wants to minimise the length of the string. In each minimising operation, geek can remove any two consecutive characters if they are of the form {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"}.
Find the minimum possible length of the string after applying minimising operations. */
/* Your Task:  
You don't need to read input or print anything. Complete the functionminLength() which takes N and S as input parameters and returns the the minimum possible length of the string. */

// My solution
class Solution{
public:
    int minLength(string s, int n) {
        for(int j=0;j<10;j++)
        {
        for(int i=0;i<s.size();i++)
        {
            if(((int)s[i]%2==1)&&(s[i]!='9'))
            {
                if(i!=0)
                {
                    if(s[i+1]==s[i]+1)
                    {
                        s.erase(i,2);
                        i-=2;;
                    }
                    else if(s[i-1]==s[i]+1)
                    {
                        s.erase(i-1,2);
                        i-=2;
                    }
                }
                else
                {
                    if(s[i+1]==s[i]+1)
                    {
                        s.erase(i,2);
                        i--;
                    }
                }
            }
            else if(s[i]=='9')
            {
                if(i!=0)
                {
                    if(s[i+1]=='0')
                    {
                        s.erase(i,2);
                        i-=2;
                    }
                    else if(s[i-1]=='0')
                    {
                        s.erase(i-1,2);
                        i-=2;
                    }
                }
                else
                {
                    if(s[i+1]=='0')
                    {
                        s.erase(i,2);
                        i--;
                    }
                }
            }
        }
        }
        return s.size();
    } 
};
//my solution ends

// Author's solution using stack
class Solution{

    public:
    int minLength(string s, int n) 
    { 
      
        // Stack to store the characters 
        // of the given string 
        stack<char> st; 

        vector<string> list = {"12", "21", "34", "43", "56", "65", "78", "87", "09", "90"};
      
        // For every character of the string 
        for (int i = 0; i < n; i++) { 
      
            // If the stack is empty then push the 
            // current character in the stack 
            if (st.empty()) { 
                st.push(s[i]); 
            } 
            else { 
                
                string temp = "";

                temp += st.top();
                temp += s[i];

                int flag = 0;

                for(int j = 0; j < (int)list.size(); j++)
                    if(list[j] == temp)
                        flag = 1;

                // If removable
                if(flag == 1){
                    st.pop();
                }
                // Else push the current element 
                else { 
                    st.push(s[i]); 
                } 
            } 
        }
        return (int)(st.size());
    } 

};
//autor's solution ends
