#!/usr/bin/python3

import sys


if len(sys.argv) == 4:
    pid = sys.argv[1]
    maps_file = '/proc/' + pid + '/maps'
    mem_file = '/proc/' + pid + '/maps'
    search_string = sys.argv[2]
    replace_string = sys.argv[3]

    lines = []
    with open(maps_file, 'r', encoding='UTF-8') as maps:
        for line in maps:
            splited_line = line.split(' ')
            lines.append(splited_line)

    for line in lines:
        for l in line:
            if l == "[heap]\n":
                adress_start = line[0][0:8]
                adress_end = line[0][9:17]
                permissions = line[1]
                heap = line[-1][0:6]

    print(adress_start)
    print(adress_end)
    print(a)


