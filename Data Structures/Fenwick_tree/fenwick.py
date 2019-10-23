"""
@author: shakeelsamsu
https://gihtub.com/shakeelsamsu
Oct 7 18 9:42:35 PM
"""


class fenwick:
    """Fenwick Tree"""

    # def __init__(self, list):
    #     """Initialize BIT with list in O(n*log(n))"""
    #     self.array = [0] * (len(list) + 1)
    #     for idx, val in enumerate(list):
    #         self.update(idx, val)

    def __init__(self, list):
        """"Initialize BIT with list in O(n)"""
        self.array = [0] + list
        for idx in range(1, len(self.array)):
            idx2 = idx + (idx & -idx)
            if idx2 < len(self.array):
                self.array[idx2] += self.array[idx]

    def prefix_query(self, idx):
        """Computes prefix sum of up to including the idx-th element"""
        idx += 1
        result = 0
        while idx:
            result += self.array[idx]
            idx -= idx & -idx
        return result

    def range_query(self, from_idx, to_idx):
        """Computes the range sum between two indices (both inclusive)"""
        return self.prefix_query(to_idx) - self.prefix_query(from_idx - 1)

    def update(self, idx, add):
        """Add a value to the idx-th element"""
        idx += 1
        while idx < len(self.array):
            self.array[idx] += add
            idx += idx & -idx


if __name__ == '__main__':
    array = [1, 7, 3, 0, 5, 8, 3, 2, 6, 2, 1, 1, 4, 5]
    bit = fenwick(array)
    print('Array: [{}]'.format(', '.join(map(str, array))))
    print()

    print('Prefix sum of first {} elements: {}'.format(13,
                                                       bit.prefix_query(12)))
    print('Prefix sum of first {} elements: {}'.format(7, bit.prefix_query(6)))
    print('Range sum from pos {} to pos {}: {}'.format(1, 5,
                                                       bit.range_query(1, 5)))
    print()

    bit.update(4, 2)
    print('Add {} to element at pos {}'.format(2, 4))
    new_array = [bit.range_query(idx, idx) for idx in range(len(array))]
    print('Array: [{}]'.format(', '.join(map(str, new_array))))
    print()

    print('Prefix sum of first {} elements: {}'.format(13,
                                                       bit.prefix_query(12)))
    print('Prefix sum of first {} elements: {}'.format(7, bit.prefix_query(6)))
    print('Range sum from pos {} to pos {}: {}'.format(1, 5,
                                                       bit.range_query(1, 5)))
    print()
