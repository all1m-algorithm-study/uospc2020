# Made by iknoom
# Modified by yonsweng

# path_from/tests/01 -> path_from/testcases/01.in
# path_from/tests/01.a -> path_from/testcases/01.out

import os
import shutil

path_from = "problems/x_mas"

for (path, dir, files) in os.walk(path_from):
    if path[-5:] != "tests": continue
    for filename in files:
        src = os.path.join(path, filename)
        dst = os.path.join(path, '../testcases/', filename)
        if filename[-2:] == '.a':
            dst = dst[:-2] + '.out'
        else:
            dst = dst + '.in'
        shutil.copy(src, dst)
