class NumMatrix {
    
    var sumMatrix: [[Int]]
    
    init(_ matrix: [[Int]]) {
        let columnCount = matrix[0].count
        let rowCount = matrix.count
        
        sumMatrix = Array(repeating: Array(repeating: 0, count: columnCount + 1), count: rowCount + 1)
        
        for row in 0..<rowCount {
            var prefix = 0
            for column in 0..<columnCount {
                prefix += matrix[row][column]
                let abovePrefixSum = sumMatrix[row][column + 1]
                sumMatrix[row + 1][column + 1] = prefix + abovePrefixSum
            }
        }
    }
    
    func sumRegion(_ row1: Int, _ col1: Int, _ row2: Int, _ col2: Int) -> Int {
        let entireArea = sumMatrix[row2 + 1][col2 + 1]
        let aboveArea = sumMatrix[row1][col2 + 1]
        let leftArea = sumMatrix[row2 + 1][col1]
        let topLeftElement = sumMatrix[row1][col1]
        return entireArea - aboveArea - leftArea + topLeftElement
    }
}