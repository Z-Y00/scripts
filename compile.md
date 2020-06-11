# here is always sth crazy...


https://github.com/BVLC/caffe/issues/4333
    cd /usr/lib/x86_64-linux-gnu

    ln -s libhdf5_serial.so.8.0.2 libhdf5.so

    ln -s libhdf5_serial_hl.so.8.0.2 libhdf5_hl.so

    In Ubuntu 16.04, the file versions are different. Visit /usr/lib/x86_64-linux-gnu/ and list the contents. The versions are 10.1.0 and 10.0.2 respectively.

