Contest 1

1. Left Rotate

#include <bits/stdc++.h>
using namespace std;
vector<int> leftrotate(int* arr,int n,int d){
    d = (n-d)%n;
    vector<int> v;
    int i = n - d;
    while(i < n)
    { v.push_back(arr[i]);i++;}
    i = 0;
    while(i< n-d)
    {v.push_back(arr[i]);i++;}
    return v;
}
void print(vector<int> v){
    for(auto x : v)
        cout<<x<<" ";
    cout<<endl;
}
int main()
{
    int n,d;
    cin>>n>>d;
    int* arr = new int[n];
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    vector<int> ans = leftrotate(arr,n,d);
    print(ans);

    return 0;
}







2. Cycle Detection

    class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};





3. Balanced Brackets



string isBalanced(string s) {
    stack<char> st;
    for(int i = 0;i<s.length();i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{')
            st.push(s[i]);
        else{
            if(st.empty())
                return "NO";
            else{
            switch(s[i]){
            case ')': if(st.top()!='(')
                        return "NO";
                      else st.pop();
                        break;
             case ']': if(st.top()!='[')
                        return "NO";
                      else st.pop();
                        break;
             case '}': if(st.top()!='{')
                        return "NO";
                      else st.pop();
                        break;
        }}
        }
    }
    if(st.empty())
        return "YES";
return "NO";

}






4. Balanced Brackets
#include<bits/stdc++.h>
using namespace std;

int main() {
    stack<int> Front,Rear;
    int Q;
    cin >> Q;
    while(Q--)
    {
        int type, x;
        cin >> type;
        if(type == 1)
        {
            cin >> x;
            Rear.push(x);
        }
        else
        {
           if(Front.empty())
           {
               while(!Rear.empty())
               {
                   Front.push(Rear.top());
                   Rear.pop();
               }
            }
           if(!Front.empty())
           {
               if(type == 2) Front.pop();
               if(type == 3) cout << Front.top() << endl;
           }
        }
    }
    return 0;
}




5. Strong Password
bool isUpper(char x){
    if((int)x >=65 && (int)x <= 90)
        return true;
    return false;
}
bool isLower(char x){
    if((int)x >=97 && (int)x <= 122)
        return true;
    return false;
}
int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong


    int* arr = new int[4]{0};
    //0 - for digit
    //1 - for lowercase
    //2 - for upper case
    //3 - for special character

    for(int i = 0;i<password.length();i++){
        if(password[i]-'0' >=0 && password[i]-'0' <10)
            arr[0]++;
        else if(isLower(password[i]))
            arr[1]++;
        else if(isUpper(password[i]))
            arr[2]++;
        else if(password[i]=='!' || password[i]=='@' || password[i]=='#' || password[i]=='$' || password[i]=='%' || password[i]=='^' || password[i]=='&' || password[i]=='*' || password[i]=='(' || password[i]==')'|| password[i]=='-' ||password[i]=='+')
            arr[3]++;

    }
    int count = 0;
    for(int i = 0;i<4;i++){
        //cout<<arr[i]<<" ";
        if(arr[i]==0)count++;
    }
    return max(count,6-n);
}


