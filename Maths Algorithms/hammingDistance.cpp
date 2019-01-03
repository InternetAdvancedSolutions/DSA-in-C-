class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {    
    if((nums.size()==0)||(nums.size()==1)) return 0;
    int max = nums[0];
    for(int i=1; i<nums.size(); i++) 
        if(max<nums[i]) 
            max = nums[i];
    int N=0;int count =0; 
    while(max){
        max = max/2;
        N++;}
    int B[N];int j=0;
    for(int  i=0; i<N; i++) B[i]=0;
    for(int i=0; i<nums.size(); i++){
         j=0;
        int n = nums[i];
        while(n){
            if(n%2!=0)  B[j]+= 1;
            n=n/2;
            j++;
        }
    }
        int n = nums.size();
    for(int i=0; i<N; i++)
        if(B[i]){ 
           j = B[i]*(n-B[i]);
            count = count +j;
        }
    return count;     
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

int main() {
    string line;
    while (getline(cin, line)) {
        vector<int> nums = stringToIntegerVector(line);
        
        int ret = Solution().totalHammingDistance(nums);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}