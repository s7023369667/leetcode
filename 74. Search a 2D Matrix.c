

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    
    int totalSize = matrixSize * (*matrixColSize);
    int left = 0, right = totalSize - 1;
    while (left <= right){
        int mid = (left + right) / 2;
        int row = mid / (*matrixColSize);
        int col = mid % (*matrixColSize);
        if (matrix[row][col] == target){
            return true;
        }else if (matrix[row][col] > target){
            right = mid - 1;
        }else{
            left = mid + 1;
        }
    }
    return false;
}
