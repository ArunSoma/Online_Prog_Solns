class Solution {
public:
    void stack_printer(vector<pair<int, int>> stk, int ps, int cur_max){
            // Vector Print
            cout<<"Position: "<<ps<<" Current Stack: ";
            for(pair a:stk)
                cout<<"("<<a.first<<","<<a.second<<") ";
            cout<<" Cur_Max: "<<cur_max<<endl;
    }
    int largestRectangleArea(vector<int>& heights) {
        int out = 0;
        pair<int, int> top_pair;
        vector<pair<int, int>> stk;
        
        int lpos, lhei;
        for(int i = 0; i < heights.size(); ++i){
            if(heights[i] == 0){
                while(!stk.empty()){
                    lpos = stk.back().second;
                    lhei = stk.back().first;
                    out = max(out, lhei*(i-lpos));
                    stk.pop_back();
                }
                // stack_printer(stk, i, out);
                continue;
            }
            if(stk.empty()){
                stk.push_back(make_pair(heights[i], i));
                out = max(out, heights[i]);
                // stack_printer(stk, i, out);
                continue;
            }
            
            top_pair = stk.back();

            if(heights[i] > top_pair.first){
                out = max(out, top_pair.first*(i-top_pair.second+1));
                stk.push_back(make_pair(heights[i], i));
            }
            else if(heights[i] == top_pair.first){
                out = max(out, top_pair.first*(i-top_pair.second+1));
            }
            else{
                while(!stk.empty() && stk.back().first > heights[i]){
                    lpos = stk.back().second;
                    lhei = stk.back().first;
                    out = max(out, heights[i]*(i-lpos+1));
                    out = max(out, lhei*(i-lpos));
                    stk.pop_back();
                }
                stk.push_back(make_pair(heights[i], lpos));
            }
            // stack_printer(stk, i, out);
            
        }
        while(!stk.empty()){
            lpos = stk.back().second;
            lhei = stk.back().first;
            out = max(out, lhei*(int(heights.size())-lpos));
            stk.pop_back();
        }
        return out;
    }
};