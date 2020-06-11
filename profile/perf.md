perf record ./generated_applications/four_motif ../datasets/citeseer/data/dataset.dgraph 
perf report
 
 http://www.brendangregg.com/perf.html
```
#!/usr/bin/env python3

import subprocess

subprocess.call('mkdir build/bin', shell=True)
subprocess.call('rm -rf build/log', shell=True)
subprocess.call('mkdir -p build/log', shell=True)
subprocess.call('cp build/generated_applications/* build/bin', shell=True)
subprocess.call('cp build/generated_automine_applications/* build/bin', shell=True)
datasets = ["citeseer","mico","youtube"] #,"patents","wiki_vote"
apps = ["triangle","three_chain","three_motif","four_motif","four_clique"]



for data_file in datasets:
	for app in apps:
		print(data_file)
		subprocess.call('perf stat -e branches,branch-misses   -d  build/bin/%s datasets/%s/data/dataset.dgraph > log1 2>&1'%(app,data_file), shell=True)
		subprocess.call('perf stat -e cache-misses  -d  build/bin/%s datasets/%s/data/dataset.dgraph > log2 2>&1'%(app,data_file), shell=True)
		subprocess.call('mv log1 build/log/%s.%s.b.log'%(app,data_file), shell=True)
		subprocess.call('mv log2 build/log/%s.%s.c.log'%(app,data_file), shell=True)
	
# perf stat -e branches,branch-misses   -d ./generated_applications/triangle ../datasets/citeseer/data/dataset.dgraph 
# perf stat -e cache-misses  -d ./generated_applications/triangle ../datasets/citeseer/data/dataset.dgraph 
# perf stat -e cache-references,cache-misses,LLC-store-misses,LLC-stores  -d ./generated_applications/triangle ../datasets/citeseer/data/dataset.dgraph 
	
# perf stat -e L1-dcache-load-misses,LLC-load-misses,LLC-store-misses,LLC-stores,cycles,cache-misses   ./generated_applications/triangle ../datasets/citeseer/data/dataset.dgraph 

```
