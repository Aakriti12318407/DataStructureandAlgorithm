class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        int largest = -1;
        int seclargest = -1;
        
        for (int i=0; i<n; i++){
            if (arr[i] > largest){
                seclargest = largest;
                largest = arr[i];
            }
            else if (arr[i] > seclargest && arr[i] != largest){
                seclargest = arr[i];
            }
        }
        return seclargest;
    }
};