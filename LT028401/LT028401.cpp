#include <lt_help/lt.h>

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    int next();             // Returns the next element in the iteration.
    bool hasNext() const;   // Returns true if the iteration has more elements.
};

class PeekingIterator : public Iterator {
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        m_peek = false;
	}

    // Returns the next element in the iteration without advancing the iterator.
	int peek() {
        if( !m_peek )
        {   m_val = Iterator::next();
            m_peek = true;
        }
        return m_val;
	}

	// hasNext() and next() should behave the same as in the Iterator interface.
	// Override them if needed.
	int next() {
        if( m_peek )
        {   m_peek = false;
            return m_val;
        }
        return Iterator::next();
	}
	
	bool hasNext() const {
        return m_peek || Iterator::hasNext();
	}

    int m_val;
    int m_peek;
};



int main(void)
{
    cout << "output: done!" << endl;
}

// Result 
//
// 2023-01-04: Runtime 6ms 32.31% Memory 7.5MB 36.33%, https://leetcode.com/problems/peeking-iterator/submissions/871271650/
// 2023-02-27: Runtime 3ms 71.31% Memory 7.6MB 36.33%, https://leetcode.com/problems/peeking-iterator/submissions/905736943/


