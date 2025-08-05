class Solution {
public:
    string removeOccurrences(string s, string part) {
        int length=part.size();
        while(s.length()>0 && s.find(part)<s.length()){
            int ind=s.find(part);
            s.erase(ind,length);
        }
        return s;
    }
};