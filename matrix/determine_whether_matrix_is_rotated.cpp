leetcode 1886. Determine Whether Matrix Can Be Obtained By Rotation

 //function to rotate the matrix
     void rotate(vector<vector<int>>& matrix) {
        if(matrix.size()==0 || matrix[0].size()==0)
            return;
        for(int i=0; i<matrix.size(); ++i)
        {
            for(int j=i+1; j<matrix[i].size(); ++j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        int l=0, r=matrix[0].size()-1;
        while(l<=r)
        {
            for(int i=0; i<matrix.size(); ++i)
            {
                swap(matrix[i][l], matrix[i][r]);
            }
            ++l, --r;
        }
    }
    
    //function to check if 2 matrices are same or not
    bool is_same(vector<vector<int>>& matrix, vector<vector<int>>& target)
    {
        for(int i=0; i<matrix.size(); ++i)
        {
            for(int j=0; j<matrix[i].size(); ++j)
            {
                if(matrix[i][j] != target[i][j])
                    return false;
            }
        }
        return true;
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        // algo: if a matrix is rotated clockwise 90 degree 4 times, it becomes same as original matrix.
        if(is_same(mat, target))
            return true;
        rotate(mat);
         if(is_same(mat, target))
            return true;
        rotate(mat);
         if(is_same(mat, target))
            return true;
        rotate(mat);
         if(is_same(mat, target))
            return true;
        return false;
    }