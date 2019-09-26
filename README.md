# STag: A Stable Fiducial Marker System
## my additional README
### build
```
$ make
```
### run
#### to detect markers in a single image file.
##### for example, to detect markers of library 11 with error correction 7 in a image file whose path is /mnt/work/21924.png, run the follwing commands and check out the directory 'log'.
```
$ mkdir log
$ ./Stag 11 7 /mnt/work/21924.png
```
#### to detect markers in the frames of camera capturing.
##### for example, to detect markers of library 11 with error correction 7 in the captured frames of a camera whose camera index is 0, run the follwing commnads and you wiil see a window named "marker detection"
```
$ ./Stag 11 7 0
```
#### shell script.
```
$ sh stag.sh
```

## original README of bbenligiray
Code used in the following paper:

[B. Benligiray; C. Topal; C. Akinlar, "STag: A Stable Fiducial Marker System," Image and Vision Computing (Accepted), 2019.](https://arxiv.org/abs/1707.06292)

Markers (will provide a generation script in the future):

https://drive.google.com/drive/folders/0ByNTNYCAhWbIV1RqdU9vRnd2Vnc

### TODO:
* Add a makefile
* Write Matlab and Python wrappers

[![Supplementary Video](https://user-images.githubusercontent.com/19530665/57184379-6a250580-6ec3-11e9-8ab3-7e139966f13b.png)](https://www.youtube.com/watch?v=vnHI3GzLVrY) 

Some figures from the paper:

<p align="center">
  <img src="https://user-images.githubusercontent.com/19530665/57179654-c0c11e00-6e88-11e9-9ca5-0c0153b28c91.png"/>
</p>

<p align="center">
  <img src="https://user-images.githubusercontent.com/19530665/57179660-cae31c80-6e88-11e9-8f80-bf8e24e59957.png"/>
</p>
