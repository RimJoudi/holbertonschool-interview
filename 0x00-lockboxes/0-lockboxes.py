#!/usr/bin/python3
'''Lockboxes module'''


def canUnlockAll(boxes):
    '''
    method that determinesif all the boxes can be opened.
    '''
    n = len(boxes)

    seen = {0}
    keys = [0]

    while keys:
        u = keys.pop()
        for key in boxes[u]:
            if isinstance(key,
                          int) and 0 <= key < len(boxes) and key not in seen:
                seen.add(key)
                keys.append(key)

    return len(seen) == n
