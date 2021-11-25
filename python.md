 subprocess.call("rm -rf graph*", shell=True)

def nested_dict(n, type):
    if n == 1:
        return defaultdict(type)
    else:
        return defaultdict(lambda: nested_dict(n-1, type))
datas = nested_dict(4,str)
