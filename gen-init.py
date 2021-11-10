import os
import shutil

def gen_init(tc_files):
    lines = ["test_cases:"]
    in_files = [None for _ in range(len(tc_files) // 2)]
    out_files = [None for _ in range(len(tc_files) // 2)]
    for tc_file in tc_files:
        tokens = tc_file.split(".")
        index = int(tokens[0])-1
        if tokens[1] == "in":
            in_files[index] = tc_file
        else:
            out_files[index] = tc_file
    for i in range(len(in_files)):
        lines.append(f" - {{in: {in_files[i]}, out: {out_files[i]}, points: 0}}")
    return "\n".join(lines)

if __name__ == "__main__":
    prob_dirs = next(os.walk("problems"))[1]
    for prob in prob_dirs:
        print(prob)
        prob_path = os.path.join("problems", prob)
        pars_path = os.path.join(".testcases", prob.replace("_", "").replace("-", ""))
        os.makedirs(pars_path, exist_ok=True)

        tc_root = os.path.join(prob_path, "testcases")
        tc_files = []
        for tc_file in os.listdir(tc_root):
            tc_src = os.path.join(tc_root, tc_file)
            tc_dst = os.path.join(pars_path, tc_file)
            if os.path.isdir(tc_src):
                continue
            shutil.copyfile(tc_src, tc_dst)
            tc_files.append(tc_file)
        
        with open(os.path.join(pars_path, "init.yml"), "w") as init_file:
            init_file.write(gen_init(tc_files))
