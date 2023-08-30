PRVdetection
============

### A tool to find specific nucletide site between two subtype of viruses

#### requirements
You will need "git","make","cmake" and "gcc" to build this program

For **Ubuntu**: You can build them in following
```bash
sudo apt update
sudo apt install make gcc cmake git
git clone https://github.com/yuumeHuang/PRVdetection.git
cd PRVdetection
mkdir build
cd build
cmake ..
make
```

#### usage
Tset data were in PRVdetection/test_data
copy build/PRVdec and test data into workdir
Run PRVdec