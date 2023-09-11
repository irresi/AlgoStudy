import os
import sys
# basepath = os.path.curdir
# if "codeforces" in os.listdir(basepath):
#     basepath = os.path.join(basepath,"codeforces")
basepath = "/workspaces/Algostudy"
curpath = basepath
template_file = open(f"{basepath}/settings/template.cpp","r")
template_code = template_file.read()
if "python" in sys.argv[0]:
    sys.argv.pop(0)
if sys.argv[0]=="codeforce" or sys.argv[0]=="codeforces" or sys.argv[0]=="cf":
    curpath+="/codeforces"
#실행명령어는 1개만 저장
if len(sys.argv)>=2:
    curpath = os.path.join(curpath, sys.argv[1])
    if not os.path.exists(curpath):
        os.makedirs(curpath)
    filenum=6
    if len(sys.argv)>=3:
        filenum = int(sys.argv[2])
    for i in range(0,filenum):
        curfile = os.path.join(curpath,chr(65+i)+".cpp")
        with open(curfile,'a') as f:
            f.write(template_code)
template_file.close()