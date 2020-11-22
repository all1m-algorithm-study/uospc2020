import os
import shutil

path_from = "problems/frame"

for (path, dir, files) in os.walk(path_from):
    if path[-5:] != "tests": continue
    os.mkdir(path + '/testcases')
    for filename in files:
        src = path + '/' + filename
        dst = path + '/testcases/' + filename
        if filename[-2:] == '.a':
            dst = dst[:-2] + '.out'
        else:
            dst = dst + '.in'
        shutil.copy(src, dst)
