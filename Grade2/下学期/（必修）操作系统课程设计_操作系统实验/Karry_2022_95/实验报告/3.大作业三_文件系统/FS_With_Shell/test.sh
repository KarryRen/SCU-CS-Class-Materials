P=sfs
C='test.c disk_emu.c sfs_api.c sfs_util.c'

echo Compiling...
gcc $C -o $P -std=c99 
./$P
# rm -rf ./disk.sfs
