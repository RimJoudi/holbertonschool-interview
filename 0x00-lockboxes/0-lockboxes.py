#!/usr/bin/python3
'''Lockboxes module'''


def canUnlockAll(boxes):
    '''
    method that determinesif all the boxes can be opened.
    '''
    n = len(boxes)
    key = [0]
    keys = set()
    if boxes[0] == [] or not isinstance(boxes, list):
        return False
    while key:
        u = key.pop()
        keys.add(u)

        for v in boxes[u]:
            if v not in keys:
                key.append(v)

    return len(keys) == n
