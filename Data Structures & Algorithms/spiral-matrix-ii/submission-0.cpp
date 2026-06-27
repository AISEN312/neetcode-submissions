class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
    int r1 = 0; int r2 = n-1; int c1 = 0; int c2 = n-1;
    vector<vector<int>> v(n, vector<int> (n,0));
    int val = 1;
   
    while(r1 <= r2 && c1 <= c2)
    {
        //left to right
        for(int c= c1; c <= c2; c++) v[r1][c] = val++;
        //up to down
        for(int r = r1+1; r <= r2; r++) v[r][c2] = val++;
       
        if(r1 < r2 && c1 < c2){
            //right to left
            for(int c= c2-1; c >= c1; c--) v[r2][c] = val++;
            //bottom to top
            for(int r = r2-1; r > r1; r--) v[r][c1] = val++;
        }
        r1++;
        r2--;
        c1++;
        c2--;
    }
    return v;
}
        
    
};