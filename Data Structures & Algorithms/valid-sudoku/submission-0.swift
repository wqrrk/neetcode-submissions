class Solution {
    func isValidSudoku(_ board: [[Character]]) -> Bool {
        
        //check the rows
        for row in board {
            var rowUnique: Set<Character> = Set()
            for elem in row {
                if elem.isNumber {
                    let inserted = rowUnique.insert(elem).inserted
                    if inserted == false {
                        return false
                    }
                }
            }
        }
        
        //check the columns
        for i in 0..<9 {
            var columnUnique: Set<Character> = Set()
            for row in board {
                let elem = row[i]
                if elem.isNumber {
                    let inserted = columnUnique.insert(elem).inserted
                    if inserted == false {
                        return false
                    }
                }
            }
        }
        
        //check for squares
        var squareUnique: Dictionary<[Int], Set<Character>> = [:]
        for i in board.indices {
            let currentRow = board[i]
            let rowGroup = i / 3
            for j in currentRow.indices {
                let columnGroup = j / 3
                let elem = currentRow[j]
                if elem.isNumber {
                    let inserted = squareUnique[[rowGroup,columnGroup], default: Set()].insert(currentRow[j]).inserted
                    if inserted == false {
                        return false
                    }
                }
            }
        }
        return true
    }
}