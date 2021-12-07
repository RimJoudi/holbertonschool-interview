#!/usr/bin/python3
'''
'''


def canUnlockAll(boxes):
    '''
    '''
    n = len(boxes)

    key = [0]
    keys = set()

    while key:
        u = key.pop()
        keys.add(u)

        for v in boxes[u]:
            if v not in keys:
                key.append(v)

    return len(keys) == n
