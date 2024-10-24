#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int  largestRectangleArea(vector<int>& heights) {
    stack<int> s;
    int maxArea = 0;
    heights.push_back(0); 

    for (int i = 0; i < heights.size(); ++i) {
        while (!s.empty() && heights[i] < heights[s.top()]) {
            int h = heights[s.top()];
            s.pop();
            int w = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        s.push(i);
    }
	return maxArea;
}

int main() {
    vector<int> building_heights = {11, 11, 10, 10, 10};
    cout << largestRectangleArea(building_heights) << endl;
    return 0;
}
