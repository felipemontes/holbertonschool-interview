#!/usr/bin/python3
'''Lock boxes iterate algorithm'''


def canUnlockAll(boxes):
    '''Compares the key with the set box index'''
    count_boxes = len(boxes)
    for set_box in range(1, count_boxes):
        all_box = False
        for key in range(count_boxes):
            all_box = set_box in boxes[key] and set_box != key
            if all_box:
                break
        if all_box is False:
            return all_box
    return True
