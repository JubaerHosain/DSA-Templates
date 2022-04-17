
//LeetCode 1024. Video Stitching


class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        vector<pair<int, int>> intervals;
        for(int i = 0; i < clips.size(); i++)
            intervals.push_back({clips[i][0], clips[i][1]});
        
        intervals.push_back({INT_MAX, INT_MAX});
        sort(intervals.begin(), intervals.end());
        
        int start = 0, end = 0, cnt = 0;
        for(int i = 0; i < intervals.size();) {
            if(intervals[i].first <= start) {
                end = max(intervals[i++].second, end);
            }
            else if(intervals[i].first > start) {
                cnt++;
                start = end;
                if(intervals[i].first > end || end >= time)
                    break;
            }
        }
        
        if(end < time)
            return -1;
        else
            return cnt;
    }
};
