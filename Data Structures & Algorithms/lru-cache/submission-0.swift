final class ListNode {
    var key: Int
    var value: Int
    
    var next: ListNode?
    weak var prev: ListNode?
    
    init(key: Int, value: Int) {
        self.key = key
        self.value = value
    }
}

final class DoubleLinkedList {
    var head: ListNode?
    var tail: ListNode?
    
    
    func insertValue(key: Int, value: Int) {
        var current = tail
        if current == nil {
            head = ListNode(key: key,value: value)
            tail = head
            return
        }
        tail?.next = ListNode(key: key, value: value)
        var inserted = tail?.next
        inserted?.prev = current
        tail = tail?.next
    }
    
    var isEmpty: Bool {
        return head == nil
    }
    
    func insertNode(_ node: ListNode) {
        if head == nil {
            head = node
            tail = head
        } else {
            tail?.next = node
            node.prev = tail
            tail = node
        }
    }
    
    func remove(_ node: ListNode) -> Int {
        let key = node.key
        let prev = node.prev
        let next = node.next
        if prev == nil && next == nil { // the list has 1 elem only
            head = nil
            tail = nil
        } else if prev == nil { // in other words delete the head
            head = next
            node.next = nil
            next?.prev = nil
        } else if next == nil { // delete the tail
            tail = prev
            prev?.next = nil
            node.prev = nil
        } else { // in the middle
            prev?.next = next
            next?.prev = prev
            node.prev = nil
            node.next = nil
        }
        return key
    }
}

class LRUCache {
    let freq = DoubleLinkedList()
    var capacity: Int
    var size: Int
    var cache: [Int: ListNode] = [:]
    
    init(_ capacity: Int) {
        self.capacity = capacity
        self.size = 0
    }

    func get(_ key: Int) -> Int {
        if let resultNode = cache[key] {
            let result = resultNode.value
            if resultNode !== freq.tail {
                freq.remove(resultNode)
                freq.insertNode(resultNode)
            }
            return result
        } else {
            return -1
        }
    }

    func put(_ key: Int, _ value: Int) {
        if let node = cache[key] {
            if node !== freq.tail {
                node.value = value
                cache[key] = node
                freq.remove(node)
                freq.insertNode(node)
            } else {
                node.value = value
                cache[key] = node
            }
            return
        }
        let node = ListNode(key: key, value: value)
        if size < capacity {
            cache[key] = node
            freq.insertNode(node)
            size += 1
        } else {
            //free up some space by deleting the head
            let removedKey = freq.remove(freq.head!)
            cache[removedKey] = nil
            //insert the new element
            freq.insertNode(node)
            cache[key] = node
        }
    }
}