MATLAB  *.mat file. convert to  Matrix Market (.mtx)

this is what I've used to init the dataset

```
echo 'read this for install the data converter http://bebop.cs.berkeley.edu/smc/index.html#installation'
wget -N http://bebop.cs.berkeley.edu/smc/tarballs/bebop_make.tar.gz
wget -N http://bebop.cs.berkeley.edu/smc/tarballs/bebop_util.tar.gz
wget -N http://bebop.cs.berkeley.edu/smc/tarballs/sparse_matrix_converter.tar.gz
wget -N leitang.net/code/social-dimension/data/blogcatalog.mat
wget -N leitang.net/code/social-dimension/data/youtube.mat
wget -N http://leitang.net/code/social-dimension/data/flickr.mat

tar xvzf bebop_make.tar.gz  
tar xvzf bebop_util.tar.gz  
tar xvzf sparse_matrix_converter.tar.gz  

make -C bebop_util  
make -C sparse_matrix_converter  

cd sparse_matrix_converter

export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:../bebop_util:../sparse_matrix_converter
echo 'each of these runs very slowly, I hope you are run these concurrently and using tmux'
./sparse_matrix_converter ../blogcatalog.mat ML ../blogcatalog.mtx MM
./sparse_matrix_converter ../flickr.mat ML ../flickr.mtx MM
./sparse_matrix_converter ../youtube.mat ML ../youtube.mtx MM
```
```
git clone --recursive https://github.com/Z-Y00/gunrock.git
cd gunrock
mkdir build && cd build
cmake .. && make -j16
make test

wget http://sourceforge.net/projects/boost/files/boost/1.58.0/boost_1_58_0.tar.gz
tar  -vxf ./boost_1_58_0.tar.gz

the original deepwalk don't have any kind of value, so we only need to run the gunrock as walk_mode=0
```
