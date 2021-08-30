
```
# discovery
get the xeon-6130
salloc --time=1:00:00 -N 1 --exclusive  --partition=gpu  --cpus-per-task=32

clush -w  nerv[1-16] ps aux | grep yoo

watch -n10 squeue


squeue -l -a -o %M%o

watch -n10 ' squeue -l -a  -o "%.18i %.9P %.8j %.8u %.8T %.10M %.9l %.6D %R     %o" ' 
watch -n10 ' squeue -l -a  -o "%.8i %.4P %.8j %.5u %.8T %.10M %.4D %R     %o" | grep RUN' 

scancel

#if you launch a lot lot of tasks
scancel --state=PENDING
#if you took other's node
scancel --nodelist=nerv1,nerv2,nerv3

salloc -N 1 -t 101:00:00

  scontrol update JobId=561,562,563 Priority=2
  

```

credits to youwei  for his scripts

```python
        slurm_config = '''#!/bin/bash
#SBATCH -J %s
#SBATCH -D /home/yoo/SGraph/GraphP/run/%s
#SBATCH -o zsim.stdout
#SBATCH -e zsim.stderr
srun /home/youwei/hmc-zsim/build/opt/zsim run.cfg
''' % (run_id, dir_name)
        slurm_submit_name = "%s/run.submit" % dir_name
        with open(slurm_submit_name, "w") as file:
          file.writelines(slurm_config)
        slurm_submit_cmd = "sbatch %s" % slurm_submit_name
        print slurm_submit_cmd
        ret = subprocess.call(slurm_submit_cmd, shell=True)
```
