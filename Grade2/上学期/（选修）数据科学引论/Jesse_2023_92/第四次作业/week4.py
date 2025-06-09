from hdfs3 import HDFileSystem

hdfs = HDFileSystem(host='localhost', port=9000)
hdfs.ls('/')
hdfs.put('opt/qqq.txt','/stu1')
hdfs.get('/stu1/qqq.txt','/opt/return_file/')