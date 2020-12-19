# about 
its program to RSA sign

# build 

- install 'cmake' and 'make'
- build program 
```
cmake . 
make
```

# work 
- generate keys 
```
./e -sk 
```
- Sign msg 
```
./e --sign 
```
- check signed msg
```
./e --check-sign
```
- Encrypt msg 
```
./e -e
```
- Decrypt msg
```
./e -d
```