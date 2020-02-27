#!/usr/bin/python3

import sys


if len(sys.argv) == 4:
    pid = sys.argv[1]
    maps_file = '/proc/' + pid + '/maps'
    mem_file = '/proc/' + pid + '/mem'
    search_string = sys.argv[2]
    replace_string = sys.argv[3]

    lines = []
    maps_file = open(maps_file, 'r', encoding='UTF-8')
    for line in maps_file:
        splited_line = line.split(' ')
        lines.append(splited_line)

    for line in lines:
        for l in line:
            if l == "[heap]\n":
                adress = line[0].split('-')
                adress_start = int(adress[0], 16)
                adress_end = int(adress[1], 16)
                permissions = line[1]
                heap = line[-1][0:6]

    if permissions[0] == 'r':
        try:
            mem_file = open(mem_file, 'rb+')
            print('True')
        except:
           print("error")

        mem_file.seek(adress_start)
        heap_mem = mem_file.read(adress_end - adress_start)

        try:
            i = heap_mem.index(bytes(search_string, "ASCII"))
            print("[*] found '{}' at {:x}".format(search_string, i))
        except:
           print("error2")

        print("[*] Writing '{}' at {:x}".format(replace_string, adress_start + i))
        mem_file.seek(adress_start + i)
        mem_file.write(bytes(replace_string, 'ASCII'))
        mem_file.close()


    #print(adress_start)
    #print(adress_end)
